set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyHICPPModule
  ExceptionBaseclassCheck.cpp
  HICPPTidyModule.cpp
  MultiwayPathsCoveredCheck.cpp
  NoAssemblerCheck.cpp
  SignedBitwiseCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyBugproneModule
#  cppClippyCppCoreGuidelinesModule
#  cppClippyGoogleModule
#  cppClippyMiscModule
#  cppClippyModernizeModule
#  cppClippyPerformanceModule
#  cppClippyReadabilityModule
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyHICPPModule
  PRIVATE
  cppClippy
  cppClippyBugproneModule
  cppClippyCppCoreGuidelinesModule
  cppClippyGoogleModule
  cppClippyMiscModule
  cppClippyModernizeModule
  cppClippyPerformanceModule
  cppClippyReadabilityModule
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangSerialization
  )
