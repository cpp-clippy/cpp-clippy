set(LLVM_LINK_COMPONENTS
  support
  FrontendOpenMP
  )

add_clang_library(cppClippyCERTModule
  CERTTidyModule.cpp
  CommandProcessorCheck.cpp
  DefaultOperatorNewAlignmentCheck.cpp
  DontModifyStdNamespaceCheck.cpp
  FloatLoopCounter.cpp
  LimitedRandomnessCheck.cpp
  MutatingCopyCheck.cpp
  NonTrivialTypesLibcMemoryCallsCheck.cpp
  PostfixOperatorCheck.cpp
  ProperlySeededRandomGeneratorCheck.cpp
  SetLongJmpCheck.cpp
  StaticObjectExceptionCheck.cpp
  StrToNumCheck.cpp
  ThrownExceptionTypeCheck.cpp
  VariadicFunctionDefCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyBugproneModule
#  cppClippyConcurrencyModule
#  cppClippyGoogleModule
#  cppClippyMiscModule
#  cppClippyPerformanceModule
#  cppClippyReadabilityModule
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyCERTModule
  PRIVATE
  cppClippy
  cppClippyBugproneModule
  cppClippyConcurrencyModule
  cppClippyGoogleModule
  cppClippyMiscModule
  cppClippyPerformanceModule
  cppClippyReadabilityModule
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
