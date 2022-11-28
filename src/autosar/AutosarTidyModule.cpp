//===------- AutosarTidyModule.cpp - clang-tidy -----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "A523Check.h"
#include "A711Check.h"
#include "A716Check.h"
#include "A722Check.h"
#include "A723Check.h"
#include "M712Check.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace autosar {

class AutosarModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<A523Check>(
        "autosar-a5-2-3");
    CheckFactories.registerCheck<A711Check>(
        "autosar-a7-1-1");
    CheckFactories.registerCheck<A716Check>(
        "autosar-a7-1-6");
    CheckFactories.registerCheck<A722Check>(
        "autosar-a7-2-2");
    CheckFactories.registerCheck<A723Check>(
        "autosar-a7-2-3");
    CheckFactories.registerCheck<M712Check>(
        "autosar-m7-1-2");
  }
};

// Register the AutosarModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<AutosarModule> X("autosar-module",
                                                   "Add autosar checks.");

} // namespace autosar

// This anchor is used to force the linker to link in the generated object file
// and thus register the AutosarModule.
volatile int AutosarModuleAnchorSource = 0;

} // namespace tidy
} // namespace clang
