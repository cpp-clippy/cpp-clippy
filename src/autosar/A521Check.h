//===--- A521Check.h - cpp-clippy -----------------------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A521CHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A521CHECK_H

#include "../ClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace autosar {

/// Flags all occurrences of dynamic_cast
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/autosar/a5-2-1.html
class A521Check : public ClangTidyCheck {
public:
  A521Check(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace autosar
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_AUTOSAR_A521CHECK_H
