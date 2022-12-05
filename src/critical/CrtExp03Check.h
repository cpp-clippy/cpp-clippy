//===--- CrtExp03Check.h - cpp-clippy ---------------------------*- C++ -*-===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#ifndef CPP_CLIPPY_SRC_CRITICAL_CRTEXP03CHECK_H_
#define CPP_CLIPPY_SRC_CRITICAL_CRTEXP03CHECK_H_

#include <string>

#include "../ClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace critical {

/// Detects function calls where the return value is unused.
///
/// For the user-facing documentation see:
/// https://cpp-clippy.gitbook.io/cpp-clippy/rules/critical/crt-exp-03
class CrtExp03Check : public ClangTidyCheck {
 public:
  CrtExp03Check(StringRef Name, ClangTidyContext *Context);
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
private:
  std::string ExcludedFunctions;
};

}  // namespace critical
}  // namespace tidy
}  // namespace clang

#endif  // CPP_CLIPPY_SRC_CRITICAL_CRTEXP03CHECK_H_
