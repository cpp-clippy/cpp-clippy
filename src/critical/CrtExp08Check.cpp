//===--- CrtExp08Check.cpp - cpp-clippy -----------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "CrtExp08Check.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace critical {

void CrtExp08Check::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(enumDecl(unless(isScoped())).bind("raw_enum"), this);
}

void CrtExp08Check::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedDecl = Result.Nodes.getNodeAs<EnumDecl>("raw_enum");

  diag(MatchedDecl->getLocation(), "enum %0 is not scoped") << MatchedDecl;
  diag(MatchedDecl->getLocation(), "convert to scoped enum",
       DiagnosticIDs::Note)
      << FixItHint::CreateInsertion(MatchedDecl->getLocation(), "class");
}

} // namespace critical
} // namespace tidy
} // namespace clang
