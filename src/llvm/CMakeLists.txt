set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyLLVMModule
  HeaderGuardCheck.cpp
  IncludeOrderCheck.cpp
  LLVMTidyModule.cpp
  PreferIsaOrDynCastInConditionalsCheck.cpp
  PreferRegisterOverUnsignedCheck.cpp
  TwineLocalCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyReadabilityModule
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyLLVMModule
  PRIVATE
  cppClippy
  cppClippyReadabilityModule
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTooling
  )
