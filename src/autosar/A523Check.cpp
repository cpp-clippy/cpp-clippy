//===--- A523Check.cpp - cpp-clippy ---------------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "A523Check.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace autosar {

static bool needsConstVolatileCast(QualType SourceType, QualType DestType) {
  SourceType = SourceType.getNonReferenceType();
  DestType = DestType.getNonReferenceType();
  while (SourceType->isPointerType() && DestType->isPointerType()) {
    SourceType = SourceType->getPointeeType();
    DestType = DestType->getPointeeType();
    if ((SourceType.isConstQualified() && !DestType.isConstQualified()) || (SourceType.isVolatileQualified() && !DestType.isVolatileQualified()))
      return true;
  }
  return false;
}

void A523Check::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(cxxConstCastExpr().bind("const-cast"), this);
  Finder->addMatcher(
      cStyleCastExpr(unless(isInTemplateInstantiation())).bind("c-cast"), this);
}

void A523Check::check(const MatchFinder::MatchResult &Result) {
  if (const auto *MatchedCast =
          Result.Nodes.getNodeAs<CXXConstCastExpr>("const-cast")) {
    diag(MatchedCast->getOperatorLoc(), "do not cast away const or volatile");
  }

  if (const auto *MatchedCast =
          Result.Nodes.getNodeAs<CStyleCastExpr>("c-cast")) {
    QualType SourceType = MatchedCast->getSubExpr()->getType();

    if (MatchedCast->getCastKind() == CK_NoOp &&
        needsConstVolatileCast(SourceType, MatchedCast->getType())) {
      diag(MatchedCast->getBeginLoc(),
           "do not cast away const or volatile");
    }
  }
}

}  // namespace autosar
}  // namespace tidy
}  // namespace clang
