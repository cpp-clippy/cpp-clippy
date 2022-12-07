//===--- CrtExp09Check.h - cpp-clippy ---------------------------*- C++ -*-===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------===//
// Note: Based on
// https://github.com/llvm/llvm-project/blob/main/clang-tools-extra/clang-tidy/readability/NonConstParameterCheck.cpp

#ifndef CPP_CLIPPY_SRC_CRITICAL_CRTEXP09CHECK_H_
#define CPP_CLIPPY_SRC_CRITICAL_CRTEXP09CHECK_H_

#include "../ClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace critical {

/// Warn when a pointer function parameter can be const.
///
/// For the user-facing documentation see:
/// https://cpp-clippy.gitbook.io/book/rules/critical/crt-exp-09
class CrtExp09Check : public ClangTidyCheck {
 public:
  CrtExp09Check(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
  void onEndOfTranslationUnit() override;
  llvm::Optional<TraversalKind> getCheckTraversalKind() const override {
    return TK_IgnoreUnlessSpelledInSource;
  }

 private:
  /// Parameter info.
  struct ParmInfo {
    /// Is function parameter referenced?
    bool IsReferenced;

    /// Can function parameter be const?
    bool CanBeConst;
  };

  /// Track all nonconst integer/float parameters.
  std::map<const ParmVarDecl *, ParmInfo> Parameters;

  /// Add function parameter.
  void addParm(const ParmVarDecl *Parm);

  /// Set IsReferenced.
  void setReferenced(const DeclRefExpr *Ref);

  /// Set CanNotBeConst.
  /// Visits sub expressions recursively. If a DeclRefExpr is found
  /// and CanNotBeConst is true the Parameter is marked as not-const.
  /// The CanNotBeConst is updated as sub expressions are visited.
  void markCanNotBeConst(const Expr *E, bool CanNotBeConst);

  /// Diagnose non const parameters.
  void diagnoseNonConstParameters();
};

}  // namespace critical
}  // namespace tidy
}  // namespace clang

#endif  // CPP_CLIPPY_SRC_CRITICAL_CRTEXP09CHECK_H_
