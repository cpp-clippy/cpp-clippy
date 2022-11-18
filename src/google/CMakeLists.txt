set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyGoogleModule
  AvoidCStyleCastsCheck.cpp
  AvoidNSObjectNewCheck.cpp
  AvoidThrowingObjCExceptionCheck.cpp
  AvoidUnderscoreInGoogletestNameCheck.cpp
  DefaultArgumentsCheck.cpp
  ExplicitConstructorCheck.cpp
  ExplicitMakePairCheck.cpp
  FunctionNamingCheck.cpp
  GlobalNamesInHeadersCheck.cpp
  GlobalVariableDeclarationCheck.cpp
  GoogleTidyModule.cpp
  IntegerTypesCheck.cpp
  OverloadedUnaryAndCheck.cpp
  TodoCommentCheck.cpp
  UnnamedNamespaceInHeaderCheck.cpp
  UpgradeGoogletestCaseCheck.cpp
  UsingNamespaceDirectiveCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyReadabilityModule
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyGoogleModule
  PRIVATE
  cppClippy
  cppClippyReadabilityModule
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
