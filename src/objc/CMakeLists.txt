set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyObjCModule
  AssertEquals.cpp
  AvoidNSErrorInitCheck.cpp
  DeallocInCategoryCheck.cpp
  ForbiddenSubclassingCheck.cpp
  MissingHashCheck.cpp
  NSInvocationArgumentLifetimeCheck.cpp
  ObjCTidyModule.cpp
  PropertyDeclarationCheck.cpp
  SuperSelfCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyObjCModule
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
