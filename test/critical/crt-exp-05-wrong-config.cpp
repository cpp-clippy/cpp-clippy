// RUN: %check_cpp_clippy %s critical-crt-exp-05 %t \
// RUN: -config='{CheckOptions: \
// RUN:  [{key: "critical-crt-exp-05.AnalyzeValues", value: false},\
// RUN:   {key: "critical-crt-exp-05.AnalyzeReferences", value: false},\
// RUN:  ]}' -- -fno-delayed-template-parsing

// CHECK-MESSAGES: warning: The check 'critical-crt-exp-05' will not perform any analysis because both 'AnalyzeValues' and 'AnalyzeReferences' are false. [clang-tidy-config]

void g() {
  int p_local0 = 42;
  // CHECK-FIXES-NOT: int const p_local0 = 42;
}