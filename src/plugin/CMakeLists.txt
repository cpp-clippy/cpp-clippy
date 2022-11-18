add_clang_library(cppClippyPlugin
  ClangTidyPlugin.cpp

  LINK_LIBS
  cppClippy
  ${ALL_CLANG_TIDY_CHECKS}

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyPlugin
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangFrontend
  clangSema
  clangTooling
  )
