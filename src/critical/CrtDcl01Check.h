//===--- CrtDcl01Check.h - cpp-clippy ---------------------------*- C++ -*-===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===// d
// Note: Based on
// https://github.com/llvm/llvm-project/blob/main/clang-tools-extra/clang-tidy/readability/UppercaseLiteralSuffixCheck.cpp

#ifndef CPP_CLIPPY_SRC_CRITICAL_CRTDCL01CHECK_H_
#define CPP_CLIPPY_SRC_CRITICAL_CRTDCL01CHECK_H_

#include "../ClangTidyCheck.h"
#include "../utils/OptionsUtils.h"

namespace clang {
namespace tidy {
namespace critical {

/// Detects when the integral literal or floating point literal has
/// non-uppercase suffix, and suggests to make the suffix uppercase.
///
/// For the user-facing documentation see:
/// https://cpp-clippy.gitbook.io/book/rules/critical/crt-dcl-01
class CrtDcl01Check : public ClangTidyCheck {
public:
  CrtDcl01Check(StringRef Name, ClangTidyContext *Context);
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
  void storeOptions(ClangTidyOptions::OptionMap &Opts) override;
  llvm::Optional<TraversalKind> getCheckTraversalKind() const override {
    return TK_IgnoreUnlessSpelledInSource;
  }

private:
  template <typename LiteralType>
  bool checkBoundMatch(const ast_matchers::MatchFinder::MatchResult &Result);

  const std::vector<StringRef> NewSuffixes;
  const bool IgnoreMacros;
};

} // namespace critical
} // namespace tidy
} // namespace clang

#endif // CPP_CLIPPY_SRC_CRITICAL_CRTDCL01CHECK_H_
