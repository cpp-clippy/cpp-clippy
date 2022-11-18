set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyLinuxKernelModule
  LinuxKernelTidyModule.cpp
  MustCheckErrsCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyLinuxKernelModule
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
