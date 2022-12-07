// RUN: %check_cpp_clippy %s critical-crt-exp-08 %t

namespace std {
using uint8_t = char;
}

enum E1
{
  E10, 
  E11, 
  E12
};
// CHECK-MESSAGES: :[[@LINE-6]]:6: warning: enum 'E1' is not scoped [critical-crt-exp-08]

enum E2 : std::uint8_t
{
  E13, 
  E14, 
  E15
};
// CHECK-MESSAGES: :[[@LINE-6]]:6: warning: enum 'E2' is not scoped

enum class E3 : std::uint8_t
{
  E20,
  E21,
  E22
};
