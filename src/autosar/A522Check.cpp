//===--- A522Check.cpp - cpp-clippy ---------------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "A522Check.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace autosar {

void A522Check::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
      cStyleCastExpr(unless(isInTemplateInstantiation())).bind("cast"), this);
}

void A522Check::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedCast = Result.Nodes.getNodeAs<CStyleCastExpr>("cast");

  diag(MatchedCast->getBeginLoc(), "do not use C-style cast");
}

}  // namespace autosar
}  // namespace tidy
}  // namespace clang
