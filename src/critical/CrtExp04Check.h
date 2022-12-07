//===--- CrtExp04Check.h - cpp-clippy ---------------------------*- C++ -*-===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//

#ifndef CPP_CLIPPY_SRC_CRITICAL_CRTEXP04CHECK_H_
#define CPP_CLIPPY_SRC_CRITICAL_CRTEXP04CHECK_H_

#include "../ClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace critical {

/// This check flags all instances of casting away const or volatile
///
/// For the user-facing documentation see:
/// https://cpp-clippy.gitbook.io/book/rules/critical/crt-exp-04
class CrtExp04Check : public ClangTidyCheck {
public:
  CrtExp04Check(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace critical
} // namespace tidy
} // namespace clang

#endif // CPP_CLIPPY_SRC_CRITICAL_CRTEXP04CHECK_H_
