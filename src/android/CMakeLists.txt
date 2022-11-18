set(LLVM_LINK_COMPONENTS
  support
  FrontendOpenMP
  )

add_clang_library(cppClippyAndroidModule
  AndroidTidyModule.cpp
  CloexecAccept4Check.cpp
  CloexecAcceptCheck.cpp
  CloexecCheck.cpp
  CloexecCreatCheck.cpp
  CloexecDupCheck.cpp
  CloexecEpollCreate1Check.cpp
  CloexecEpollCreateCheck.cpp
  CloexecFopenCheck.cpp
  CloexecInotifyInit1Check.cpp
  CloexecInotifyInitCheck.cpp
  CloexecMemfdCreateCheck.cpp
  CloexecOpenCheck.cpp
  CloexecPipeCheck.cpp
  CloexecPipe2Check.cpp
  CloexecSocketCheck.cpp
  ComparisonInTempFailureRetryCheck.cpp

#  LINK_LIBS
#  cppClippy
#  cppClippyUtils

#  DEPENDS
#  omp_gen
  )

clang_target_link_libraries(cppClippyAndroidModule
  PRIVATE
  cppClippy
  cppClippyUtils
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  )
