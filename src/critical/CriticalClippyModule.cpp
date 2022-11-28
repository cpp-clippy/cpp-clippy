//===------- CriticalTidyModule.cpp - clang-tidy -------------------------===//
//
// Part of the Cpp-Clippy Project, under the Apache License v2.0.
// See https://github.com/cpp-clippy/cpp-clippy/LICENSE.txt for
// license information.
// SPDX-License-Identifier: Apache-2.0
//
//===--------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "CrtExp01Check.h"
#include "CrtExp02Check.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace critical {

class CriticalModule : public ClangTidyModule {
 public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<CrtExp01Check>("critical-crt-exp-01");
    CheckFactories.registerCheck<CrtExp02Check>(
        "critical-crt-exp-02");
  }
};

// Register the CriticalModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<CriticalModule> X("critical-module",
                                                      "Add critical checks.");

}  // namespace critical

// This anchor is used to force the linker to link in the generated object file
// and thus register the CriticalModule.
volatile int CriticalModuleAnchorSource = 0;

}  // namespace tidy
}  // namespace clang
