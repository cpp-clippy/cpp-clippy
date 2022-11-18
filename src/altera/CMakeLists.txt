set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  support
  )

add_clang_library(cppClippyAlteraModule
  AlteraTidyModule.cpp
  IdDependentBackwardBranchCheck.cpp
  KernelNameRestrictionCheck.cpp
  SingleWorkItemBarrierCheck.cpp
  StructPackAlignCheck.cpp
  UnrollLoopsCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils
  )

clang_target_link_libraries(cppClippyAlteraModule
  PRIVATE
  clangAnalysis
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
