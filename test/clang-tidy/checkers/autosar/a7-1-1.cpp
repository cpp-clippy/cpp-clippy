// RUN: %check_cpp_clippy %s autosar-a7-1-1 %t

#include <stdint.h>

void Fn() {
  const int16_t x1 = 5;
  constexpr int16_t x2 = 5;
  int16_t x3 = 5;
  // CHECK-MESSAGES: [[@LINE-1]]:3: warning: variable 'x3' of type 'int16_t' (aka 'short') can be declared 'constexpr' or 'const' [autosar-a7-1-1]
  // CHECK-FIXES: int16_t const x3 = 5;
  
  int a;
  constexpr int c[] = {0, 1, 2, 3, 4, 5};
  for (const int i : c) a = i;

  for (int i : c) a = i;
  // CHECK-MESSAGES: [[@LINE-1]]:8: warning: variable 'i' of type 'int' can be declared 'constexpr' or 'const' [autosar-a7-1-1]
  // CHECK-FIXES: for (int const i : c) a = i;
}
