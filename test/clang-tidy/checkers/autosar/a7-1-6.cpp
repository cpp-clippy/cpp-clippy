// RUN: %check_cpp_clippy %s autosar-a7-1-6 %t

#include <stdint.h>

typedef int32_t (*fPointer1)(int32_t);
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: use 'using' instead of 'typedef' [autosar-a7-1-6]
// CHECK-FIXES: using fPointer1 = int32_t (*)(int32_t);

using fPointer2 = int32_t (*)(int32_t);

template <typename T>
using fPointer3 = int32_t (*)(T);