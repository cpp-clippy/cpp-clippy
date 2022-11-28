add_clang_library(cppClippyCriticalModule
  CriticalClippyModule.cpp
  CrtExp01Check.cpp
  CrtExp02Check.cpp
  )

clang_target_link_libraries(cppClippyCriticalModule
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
