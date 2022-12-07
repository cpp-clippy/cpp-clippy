// RUN: %check_cpp_clippy %s critical-crt-exp-05 %t \
// RUN:   -config="{CheckOptions: [\
// RUN:   {key: 'critical-crt-exp-05.TransformValues', value: true}, \
// RUN:   {key: 'critical-crt-exp-05.TransformReferences', value: true}, \
// RUN:   {key: 'critical-crt-exp-05.WarnPointersAsValues', value: false}, \
// RUN:   {key: 'critical-crt-exp-05.TransformPointersAsValues', value: false}, \
// RUN:   ]}" -- -fno-delayed-template-parsing

template <typename T>
void type_dependent_variables() {
  T value = 42;
  auto &ref = value;
  T &templateRef = value;

  int value_int = 42;
  // CHECK-MESSAGES:[[@LINE-1]]:3: warning: variable 'value_int' of type 'int' can be declared 'const'
  // CHECK-FIXES: int const value_int
}
void instantiate_template_cases() {
  type_dependent_variables<int>();
  type_dependent_variables<float>();
}