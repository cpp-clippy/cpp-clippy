// RUN: %check_cpp_clippy %s critical-crt-exp-07 %t

namespace std {
using uint8_t = char;
}

enum class E1
{
  E10, 
  E11, 
  E12
};
// CHECK-MESSAGES: :[[@LINE-6]]:14: warning: enumerator 'E1' base type shall be explicitly defined [critical-crt-exp-07]
// CHECK-MESSAGES: :[[@LINE-7]]:14: warning: set base type
// CHECK-FIXES: enum class E1: std::uint8_t

enum class E2 : std::uint8_t
{
  E20, 
  E21, 
  E22
};

enum E3
{
  E30, 
  E31, 
  E32
};
// CHECK-MESSAGES: :[[@LINE-6]]:8: warning: enumerator 'E3' base type shall be explicitly defined
// CHECK-MESSAGES: :[[@LINE-7]]:8: warning: set base type
// CHECK-FIXES: enum E3: std::uint8_t

enum E4 : std::uint8_t
{
  E40, 
  E41, 
  E42
};

enum class E5
{
  E50=-1, 
  E51, 
  E52=127
};
// CHECK-MESSAGES: :[[@LINE-6]]:14: warning: enumerator 'E5' base type shall be explicitly defined
// CHECK-MESSAGES: :[[@LINE-7]]:14: warning: set base type
// CHECK-FIXES: enum class E5: std::int8_t

enum class E6
{
  E60=-1, 
  E61, 
  E62=128
};
// CHECK-MESSAGES: :[[@LINE-6]]:14: warning: enumerator 'E6' base type shall be explicitly defined
// CHECK-MESSAGES: :[[@LINE-7]]:14: warning: set base type
// CHECK-FIXES: enum class E6: std::int16_t

enum class E7
{
  E70, 
  E71, 
  E72=255
};
// CHECK-MESSAGES: :[[@LINE-6]]:14: warning: enumerator 'E7' base type shall be explicitly defined
// CHECK-MESSAGES: :[[@LINE-7]]:14: warning: set base type
// CHECK-FIXES: enum class E7: std::uint8_t

enum class E8
{
  E80, 
  E81, 
  E82=65535
};
// CHECK-MESSAGES: :[[@LINE-6]]:14: warning: enumerator 'E8' base type shall be explicitly defined
// CHECK-MESSAGES: :[[@LINE-7]]:14: warning: set base type
// CHECK-FIXES: enum class E8: std::uint16_t

enum class E9
{
  E90, 
  E91, 
  E92=65536
};
// CHECK-MESSAGES: :[[@LINE-6]]:14: warning: enumerator 'E9' base type shall be explicitly defined
// CHECK-MESSAGES: :[[@LINE-7]]:14: warning: set base type
// CHECK-FIXES: enum class E9: std::uint32_t

enum class E10
{
  E100=-32768, 
  E101, 
  E102
};
// CHECK-MESSAGES: :[[@LINE-6]]:15: warning: enumerator 'E10' base type shall be explicitly defined
// CHECK-MESSAGES: :[[@LINE-7]]:15: warning: set base type
// CHECK-FIXES: enum class E10: std::int16_t

enum class E11
{
  E110=-32769, 
  E111, 
  E112
};
// CHECK-MESSAGES: :[[@LINE-6]]:15: warning: enumerator 'E11' base type shall be explicitly defined
// CHECK-MESSAGES: :[[@LINE-7]]:15: warning: set base type
// CHECK-FIXES: enum class E11: std::int32_t

enum { __value = 0 };
