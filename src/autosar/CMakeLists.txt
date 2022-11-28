set(LLVM_LINK_COMPONENTS
  support
  FrontendOpenMP
  )

add_clang_library(cppClippyAutosarModule
  A523Check.cpp
  A711Check.cpp
  A716Check.cpp
  A722Check.cpp
  A723Check.cpp
  AutosarTidyModule.cpp
  M712Check.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyAutosarModule
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
