set(LLVM_LINK_COMPONENTS
  FrontendOpenMP
  Support
  )

add_clang_library(cppClippyUtils
  Aliasing.cpp
  ASTUtils.cpp
  DeclRefExprUtils.cpp
  ExceptionAnalyzer.cpp
  ExprSequence.cpp
  FileExtensionsUtils.cpp
  FixItHintUtils.cpp
  HeaderGuard.cpp
  IncludeInserter.cpp
  IncludeSorter.cpp
  LexerUtils.cpp
  NamespaceAliaser.cpp
  OptionsUtils.cpp
  RenamerClangTidyCheck.cpp
  TransformerClangTidyCheck.cpp
  TypeTraits.cpp
  UsingInserter.cpp

  LINK_LIBS
  cppClippy


#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyUtils
  PRIVATE
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangSema
  clangTransformer
  )
