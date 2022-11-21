//===--- A521Check.cpp - cpp-clippy ---------------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "A521Check.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace autosar {

void A521Check::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(cxxDynamicCastExpr().bind("cast"), this);
}

void A521Check::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedCast =
      Result.Nodes.getNodeAs<CXXDynamicCastExpr>("cast");
  diag(MatchedCast->getOperatorLoc(), "do not use dynamic_cast");
}

} // namespace autosar
} // namespace tidy
} // namespace clang
