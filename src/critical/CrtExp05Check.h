//===--- CrtExp05Check.h - cpp-clippy ---------------------------*- C++ -*-===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//
// Note: Based on https://github.com/llvm/llvm-project/blob/main/clang-tools-extra/clang-tidy/misc/ConstCorrectnessCheck.cpp

#ifndef CPP_CLIPPY_SRC_CRITICAL_CRTEXP05CHECK_H_
#define CPP_CLIPPY_SRC_CRITICAL_CRTEXP05CHECK_H_

#include "../ClangTidyCheck.h"
#include "clang/Analysis/Analyses/ExprMutationAnalyzer.h"
#include "llvm/ADT/DenseSet.h"

namespace clang {
namespace tidy {
namespace critical {

/// This check warns on variables which could be declared const or constexpr but
/// are not.
///
/// For the user-facing documentation see:
/// https://cpp-clippy.gitbook.io/book/rules/critical/crt-exp-05
class CrtExp05Check : public ClangTidyCheck {
 public:
  CrtExp05Check(StringRef Name, ClangTidyContext *Context);

  // The rules for C and 'const' are different and incompatible for this check.
  bool isLanguageVersionSupported(const LangOptions &LangOpts) const override {
    return LangOpts.CPlusPlus;
  }
  void storeOptions(ClangTidyOptions::OptionMap &Opts) override;
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;

 private:
  void registerScope(const CompoundStmt *LocalScope, ASTContext *Context);

  using MutationAnalyzer = std::unique_ptr<ExprMutationAnalyzer>;
  llvm::DenseMap<const CompoundStmt *, MutationAnalyzer> ScopesCache;
  llvm::DenseSet<SourceLocation> TemplateDiagnosticsCache;

  const bool AnalyzeValues;
  const bool AnalyzeReferences;
  const bool WarnPointersAsValues;

  const bool TransformValues;
  const bool TransformReferences;
  const bool TransformPointersAsValues;
};

}  // namespace critical
}  // namespace tidy
}  // namespace clang

#endif  // CPP_CLIPPY_SRC_CRITICAL_CRTEXP05CHECK_H_