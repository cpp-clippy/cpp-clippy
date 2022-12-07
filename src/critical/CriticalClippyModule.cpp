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
#include "CrtDcl01Check.h"
#include "CrtDcl02Check.h"
#include "CrtExp01Check.h"
#include "CrtExp02Check.h"
#include "CrtExp03Check.h"
#include "CrtExp04Check.h"
#include "CrtExp05Check.h"
#include "CrtExp06Check.h"
#include "CrtExp07Check.h"
#include "CrtExp08Check.h"
#include "CrtExp09Check.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace critical {

class CriticalModule : public ClangTidyModule {
 public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<CrtDcl01Check>(
        "critical-crt-dcl-01");
    CheckFactories.registerCheck<CrtDcl02Check>(
        "critical-crt-dcl-02");
    CheckFactories.registerCheck<CrtExp01Check>("critical-crt-exp-01");
    CheckFactories.registerCheck<CrtExp02Check>(
        "critical-crt-exp-02");
    CheckFactories.registerCheck<CrtExp03Check>(
        "critical-crt-exp-03");
    CheckFactories.registerCheck<CrtExp04Check>(
        "critical-crt-exp-04");
    CheckFactories.registerCheck<CrtExp05Check>(
        "critical-crt-exp-05");
    CheckFactories.registerCheck<CrtExp06Check>(
        "critical-crt-exp-06");
    CheckFactories.registerCheck<CrtExp07Check>(
        "critical-crt-exp-07");
    CheckFactories.registerCheck<CrtExp08Check>(
        "critical-crt-exp-08");
    CheckFactories.registerCheck<CrtExp09Check>(
        "critical-crt-exp-09");
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
