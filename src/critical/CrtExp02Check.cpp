//===--- CrtExp02Check.cpp - cpp-clippy -----------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "CrtExp02Check.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace critical {

void CrtExp02Check::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(cxxDynamicCastExpr().bind("cast"), this);
}

void CrtExp02Check::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedCast =
      Result.Nodes.getNodeAs<CXXDynamicCastExpr>("cast");
  diag(MatchedCast->getOperatorLoc(), "do not use dynamic_cast");
}

} // namespace critical
} // namespace tidy
} // namespace clang
