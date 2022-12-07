// RUN: %check_cpp_clippy %s critical-crt-exp-05 %t \
// RUN: -config='{CheckOptions: \
// RUN:  [{key: "critical-crt-exp-05.AnalyzeValues", value: true},\
// RUN:   {key: "critical-crt-exp-05.WarnPointersAsValues", value: true}, \
// RUN:   {key: "critical-crt-exp-05.TransformPointersAsValues", value: true},\
// RUN:  ]}' -- -fno-delayed-template-parsing

void potential_const_pointer() {
  double np_local0[10] = {0., 1., 2., 3., 4., 5., 6., 7., 8., 9.};
  double *p_local0 = &np_local0[1];
  // CHECK-MESSAGES: [[@LINE-1]]:3: warning: variable 'p_local0' of type 'double *' can be declared 'const'
  // CHECK-FIXES: double *const p_local0 = &np_local0[1];
}