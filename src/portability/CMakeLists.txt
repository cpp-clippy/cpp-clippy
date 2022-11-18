set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyPortabilityModule
  PortabilityTidyModule.cpp
  RestrictSystemIncludesCheck.cpp
  SIMDIntrinsicsCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyPortabilityModule
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTooling
  )
