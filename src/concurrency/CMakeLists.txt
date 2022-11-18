set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyConcurrencyModule
  ConcurrencyTidyModule.cpp
  MtUnsafeCheck.cpp
  ThreadCanceltypeAsynchronousCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils
  )

clang_target_link_libraries(cppClippyConcurrencyModule
  PRIVATE
  clangAnalysis
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangSerialization
  clangTooling
  )
