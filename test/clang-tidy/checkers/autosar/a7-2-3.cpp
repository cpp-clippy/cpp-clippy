// RUN: %check_cpp_clippy %s autosar-a7-2-3 %t

#include <stdint.h>

enum E1
{
  E10, 
  E11, 
  E12
};
// CHECK-MESSAGES: :[[@LINE-6]]:6: warning: enum 'E1' is not scoped [autosar-a7-2-3]

enum E2 : int32_t
{
  E13, 
  E14, 
  E15
};
// CHECK-MESSAGES: :[[@LINE-6]]:6: warning: enum 'E2' is not scoped [autosar-a7-2-3]

enum class E3 : int32_t
{
  E20,
  E21,
  E22
};
