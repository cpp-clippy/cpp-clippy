//===--- A722Check.cpp - cpp-clippy ---------------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#include "A722Check.h"

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace autosar {

/// Stores a min and a max value which describe an interval.
struct ValueRange {
  llvm::APSInt MinVal;
  llvm::APSInt MaxVal;

  ValueRange(const EnumDecl *EnumDec) {
    const auto MinMaxVal = std::minmax_element(
        EnumDec->enumerator_begin(), EnumDec->enumerator_end(),
        [](const EnumConstantDecl *E1, const EnumConstantDecl *E2) {
          return llvm::APSInt::compareValues(E1->getInitVal(),
                                             E2->getInitVal()) < 0;
        });
    MinVal = MinMaxVal.first->getInitVal();
    MaxVal = MinMaxVal.second->getInitVal();
  }
};

std::string GetEnumType(ValueRange const &EnumRange) {
  std::string Type{": "};

  if (EnumRange.MinVal.isNegative()) {
    if (std::numeric_limits<std::int8_t>::min() <= EnumRange.MinVal &&
        std::numeric_limits<std::int8_t>::max() >= EnumRange.MaxVal) {
      Type += "std::int8_t";
    } else if (std::numeric_limits<std::int16_t>::min() <= EnumRange.MinVal &&
               std::numeric_limits<std::int16_t>::max() >= EnumRange.MaxVal) {
      Type += "std::int16_t";
    } else {
      Type += "std::int32_t";
    }
  } else {
    if (std::numeric_limits<std::uint8_t>::min() <= EnumRange.MinVal &&
        std::numeric_limits<std::uint8_t>::max() >= EnumRange.MaxVal) {
      Type += "std::uint8_t";
    } else if (std::numeric_limits<std::uint16_t>::min() <= EnumRange.MinVal &&
               std::numeric_limits<std::uint16_t>::max() >= EnumRange.MaxVal) {
      Type += "std::uint16_t";
    } else {
      Type += "std::uint32_t";
    }
  }

  return Type;
}

void A722Check::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(enumDecl().bind("enum"), this);
}

void A722Check::check(const MatchFinder::MatchResult &Result) {
  const auto *MatchedDecl = Result.Nodes.getNodeAs<EnumDecl>("enum");

  if (MatchedDecl->getIntegerTypeSourceInfo()) return;

  if (!MatchedDecl->getIdentifier()) return;

  int EnumNameLength = MatchedDecl->getIdentifier()->getLength();

  diag(MatchedDecl->getLocation().getLocWithOffset(EnumNameLength),
       "enumerator %0 base type shall be explicitly defined")
      << MatchedDecl;

  ValueRange EnumRange(MatchedDecl);

  diag(MatchedDecl->getLocation().getLocWithOffset(EnumNameLength),
       "set base type")
      << FixItHint::CreateReplacement(
             MatchedDecl->getLocation().getLocWithOffset(EnumNameLength),
             GetEnumType(EnumRange));
}

}  // namespace autosar
}  // namespace tidy
}  // namespace clang
