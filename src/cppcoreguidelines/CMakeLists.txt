set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyCppCoreGuidelinesModule
  AvoidGotoCheck.cpp
  AvoidNonConstGlobalVariablesCheck.cpp
  CppCoreGuidelinesTidyModule.cpp
  InitVariablesCheck.cpp
  InterfacesGlobalInitCheck.cpp
  MacroUsageCheck.cpp
  NarrowingConversionsCheck.cpp
  NoMallocCheck.cpp
  OwningMemoryCheck.cpp
  PreferMemberInitializerCheck.cpp
  ProBoundsArrayToPointerDecayCheck.cpp
  ProBoundsConstantArrayIndexCheck.cpp
  ProBoundsPointerArithmeticCheck.cpp
  ProTypeConstCastCheck.cpp
  ProTypeCstyleCastCheck.cpp
  ProTypeMemberInitCheck.cpp
  ProTypeReinterpretCastCheck.cpp
  ProTypeStaticCastDowncastCheck.cpp
  ProTypeUnionAccessCheck.cpp
  ProTypeVarargCheck.cpp
  SlicingCheck.cpp
  SpecialMemberFunctionsCheck.cpp
  VirtualClassDestructorCheck.cpp

  LINK_LIBS
  cppClippy
  cppClippyMiscModule
  cppClippyModernizeModule
  cppClippyReadabilityModule
  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyCppCoreGuidelinesModule
  PRIVATE
  cppClippy
  cppClippyMiscModule
  cppClippyModernizeModule
  cppClippyReadabilityModule
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangSerialization
  clangTooling
  )
