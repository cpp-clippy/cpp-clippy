//===--- A523Check.h - cpp-clippy -----------------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A523CHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A523CHECK_H

#include "../ClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace autosar {

/// Flags all cast aways of const or volatile qualifiers.
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/autosar/a5-2-3.html
class A523Check : public ClangTidyCheck {
public:
  A523Check(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace autosar
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A523CHECK_H
