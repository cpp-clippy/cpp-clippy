set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyLLVMLibcModule
  CalleeNamespaceCheck.cpp
  ImplementationInNamespaceCheck.cpp
  LLVMLibcTidyModule.cpp
  RestrictSystemLibcHeadersCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyPortabilityModule
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyLLVMLibcModule
  PRIVATE
  cppClippy
  cppClippyPortabilityModule
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTooling
  )
