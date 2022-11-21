//===--- A711Check.h - cpp-clippy -----------------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A711CHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A711CHECK_H

#include "../ClangTidyCheck.h"
#include "clang/Analysis/Analyses/ExprMutationAnalyzer.h"
#include "llvm/ADT/DenseSet.h"

namespace clang {
namespace tidy {
namespace autosar {

/// Flags all immutable data that is not declared constexpr or const
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/autosar/a7-1-1.html
class A711Check : public ClangTidyCheck {
public:
  A711Check(StringRef Name, ClangTidyContext *Context);

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

} // namespace autosar
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A711CHECK_H
