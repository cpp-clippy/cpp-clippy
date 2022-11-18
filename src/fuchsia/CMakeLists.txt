set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyFuchsiaModule
  DefaultArgumentsCallsCheck.cpp
  DefaultArgumentsDeclarationsCheck.cpp
  FuchsiaTidyModule.cpp
  MultipleInheritanceCheck.cpp
  OverloadedOperatorCheck.cpp
  StaticallyConstructedObjectsCheck.cpp
  TrailingReturnCheck.cpp
  VirtualInheritanceCheck.cpp

  LINK_LIBS
  cppClippy
  cppClippyGoogleModule
  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyFuchsiaModule
  PRIVATE
  cppClippy
  cppClippyGoogleModule
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
