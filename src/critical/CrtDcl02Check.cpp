//===--- CrtDcl02Check.cpp - cpp-clippy -----------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "CrtDcl02Check.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace critical {

void CrtDcl02Check::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(varDecl().bind("var-decl"), this);
}

void CrtDcl02Check::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedDecl = Result.Nodes.getNodeAs<VarDecl>("var-decl");
  auto type = MatchedDecl->getType().getAsString();

  if (type.compare(0, 7, "wchar_t") == 0) {
    diag(MatchedDecl->getBeginLoc(), "Do not use wchar_t")
        << MatchedDecl->getType();
  }
}

}  // namespace critical
}  // namespace tidy
}  // namespace clang
