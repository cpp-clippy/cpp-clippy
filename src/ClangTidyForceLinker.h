//===- ClangTidyForceLinker.h - clang-tidy --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_CLANGTIDYFORCELINKER_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_CLANGTIDYFORCELINKER_H

#include "clang-tidy-config.h"
#include "llvm/Support/Compiler.h"

namespace clang {
namespace tidy {

// This anchor is used to force the linker to link the AutosarModule.
extern volatile int AutosarModuleAnchorSource;
static int LLVM_ATTRIBUTE_UNUSED AutosarModuleAnchorDestination =
    AutosarModuleAnchorSource;

} // namespace tidy
} // namespace clang

#endif
