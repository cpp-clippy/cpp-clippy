set(LLVM_LINK_COMPONENTS
  support
  FrontendOpenMP
  )

add_clang_library(cppClippyAbseilModule
  AbseilTidyModule.cpp
  CleanupCtadCheck.cpp
  DurationAdditionCheck.cpp
  DurationComparisonCheck.cpp
  DurationConversionCastCheck.cpp
  DurationDivisionCheck.cpp
  DurationFactoryFloatCheck.cpp
  DurationFactoryScaleCheck.cpp
  DurationRewriter.cpp
  DurationSubtractionCheck.cpp
  DurationUnnecessaryConversionCheck.cpp
  FasterStrsplitDelimiterCheck.cpp
  NoInternalDependenciesCheck.cpp
  NoNamespaceCheck.cpp
  RedundantStrcatCallsCheck.cpp
  StrCatAppendCheck.cpp
  StringFindStartswithCheck.cpp
  StringFindStrContainsCheck.cpp
  TimeComparisonCheck.cpp
  TimeSubtractionCheck.cpp
  UpgradeDurationConversionsCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyAbseilModule
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTooling
  clangTransformer
  )
