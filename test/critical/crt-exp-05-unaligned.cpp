// RUN: %check_cpp_clippy %s critical-crt-exp-05 %t -- \
// RUN:   -config="{CheckOptions: [\
// RUN:   {key: 'critical-crt-exp-05.TransformValues', value: true}, \
// RUN:   {key: 'critical-crt-exp-05.WarnPointersAsValues', value: false}, \
// RUN:   {key: 'critical-crt-exp-05.TransformPointersAsValues', value: false}, \
// RUN:   ]}" -- -fno-delayed-template-parsing -fms-extensions

struct S {};

void f(__unaligned S *);

void scope() {
  // FIXME: This is a bug in the analysis, that is confused by '__unaligned'.
  // https://bugs.llvm.org/show_bug.cgi?id=51756
  S s;
  // CHECK-MESSAGES:[[@LINE-1]]:3: warning: variable 's' of type 'S' can be declared 'const'
  // CHECK-FIXES: S const s;
  f(&s);
}