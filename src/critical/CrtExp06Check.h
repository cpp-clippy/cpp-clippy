//===--- CrtExp06Check.h - cpp-clippy ---------------------------*- C++ -*-===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//
// Note: Based on
// https://github.com/llvm/llvm-project/blob/main/clang-tools-extra/clang-tidy/modernize/UseUsingCheck.cpp

#ifndef CPP_CLIPPY_SRC_CRITICAL_CRTEXP06CHECK_H_
#define CPP_CLIPPY_SRC_CRITICAL_CRTEXP06CHECK_H_

#include "../ClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace critical {

/// Check finds typedefs and replaces it with usings.
///
/// For the user-facing documentation see:
/// https://cpp-clippy.gitbook.io/book/rules/critical/crt-exp-06
class CrtExp06Check : public ClangTidyCheck {
 public:
  CrtExp06Check(StringRef Name, ClangTidyContext *Context);
  bool isLanguageVersionSupported(const LangOptions &LangOpts) const override {
    return LangOpts.CPlusPlus11;
  }
  void storeOptions(ClangTidyOptions::OptionMap &Opts) override;
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;

 private:
  const bool IgnoreMacros;
  SourceLocation LastReplacementEnd;
  llvm::DenseMap<const Decl *, SourceRange> LastTagDeclRanges;

  std::string FirstTypedefType;
  std::string FirstTypedefName;
};

}  // namespace critical
}  // namespace tidy
}  // namespace clang

#endif  // CPP_CLIPPY_SRC_CRITICAL_CRTEXP06CHECK_H_
