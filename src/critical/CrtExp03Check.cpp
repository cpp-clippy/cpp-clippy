//===--- CrtExp03Check.cpp - cpp-clippy -----------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "CrtExp03Check.h"

#include "../utils/OptionsUtils.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;
using namespace clang::ast_matchers::internal;

namespace clang {
namespace tidy {
namespace critical {

namespace {

// Matches functions that are instantiated from a class template member function
// matching InnerMatcher. Functions not instantiated from a class template
// member function are matched directly with InnerMatcher.
AST_MATCHER_P(FunctionDecl, isInstantiatedFrom, Matcher<FunctionDecl>,
              InnerMatcher) {
  FunctionDecl *InstantiatedFrom = Node.getInstantiatedFromMemberFunction();
  return InnerMatcher.matches(InstantiatedFrom ? *InstantiatedFrom : Node,
                              Finder, Builder);
}

}  // namespace

CrtExp03Check::CrtExp03Check(llvm::StringRef Name, ClangTidyContext *Context)
    : ClangTidyCheck(Name, Context),
      ExcludedFunctions(Options.get("ExcludedFunctions",
                                    "operator<<;"
                                    "operator>>;"
                                    "operator=;"
                                    "operator++;"
                                    "operator--;"
                                    "operator+=;"
                                    "::memcpy;"
                                    "std::string::append;"
                                    "basic_string::append;"
                                    "basic_string::erase;"
                                    "std::set_terminate;"
                                    "std::transform;")) {}

void CrtExp03Check::registerMatchers(MatchFinder *Finder) {
  auto FunVec = utils::options::parseStringList(ExcludedFunctions);
  auto MatchedCallExpr = expr(ignoringImplicit(ignoringParenImpCasts(
      callExpr(callee(functionDecl(
                   // Don't match void overloads of checked functions.
                   unless(returns(voidType())),
                   unless(isInstantiatedFrom(hasAnyName(FunVec))))))
          .bind("match"))));

  auto UnusedInCompoundStmt =
      compoundStmt(forEach(MatchedCallExpr),
                   // The checker can't currently differentiate between the
                   // return statement and other statements inside GNU statement
                   // expressions, so disable the checker inside them to avoid
                   // false positives.
                   unless(hasParent(stmtExpr())));
  auto UnusedInIfStmt =
      ifStmt(eachOf(hasThen(MatchedCallExpr), hasElse(MatchedCallExpr)));
  auto UnusedInWhileStmt = whileStmt(hasBody(MatchedCallExpr));
  auto UnusedInDoStmt = doStmt(hasBody(MatchedCallExpr));
  auto UnusedInForStmt =
      forStmt(eachOf(hasLoopInit(MatchedCallExpr),
                     hasIncrement(MatchedCallExpr), hasBody(MatchedCallExpr)));
  auto UnusedInRangeForStmt = cxxForRangeStmt(hasBody(MatchedCallExpr));
  auto UnusedInCaseStmt = switchCase(forEach(MatchedCallExpr));

  Finder->addMatcher(
      stmt(anyOf(UnusedInCompoundStmt, 
                 UnusedInIfStmt, 
                 UnusedInWhileStmt,
                 UnusedInDoStmt, 
                 UnusedInForStmt, 
                 UnusedInRangeForStmt,
                 UnusedInCaseStmt)),
      this);
}

void CrtExp03Check::check(const MatchFinder::MatchResult &Result) {
  if (const auto *Matched = Result.Nodes.getNodeAs<CallExpr>("match")) {
    diag(Matched->getBeginLoc(),
         "the value returned by this function should be used")
        << Matched->getSourceRange();
    diag(Matched->getBeginLoc(),
         "cast the expression to void to silence this warning",
         DiagnosticIDs::Note);
  }
}

}  // namespace critical
}  // namespace tidy
}  // namespace clang
