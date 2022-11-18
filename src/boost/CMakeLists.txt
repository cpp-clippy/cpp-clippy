set(LLVM_LINK_COMPONENTS
  support
  FrontendOpenMP
  )

add_clang_library(cppClippyBoostModule
  BoostTidyModule.cpp
  UseToStringCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyBoostModule
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
