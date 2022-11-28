//===--- CrtExp01Check.cpp - cpp-clippy ---------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===--------------------------------------------------------------------===//

#include "CrtExp01Check.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace critical {

void CrtExp01Check::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
      cStyleCastExpr(unless(isInTemplateInstantiation())).bind("cast"), this);
}

void CrtExp01Check::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedCast = Result.Nodes.getNodeAs<CStyleCastExpr>("cast");

  diag(MatchedCast->getBeginLoc(), "do not use C-style cast");
}

}  // namespace critical
}  // namespace tidy
}  // namespace clang
