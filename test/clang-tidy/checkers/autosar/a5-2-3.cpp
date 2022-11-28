// RUN: %check_cpp_clippy %s autosar-a5-2-3 %t

#include <stdint.h>

void F1(const char* str) noexcept(false) {
  *(const_cast<char*>(str)) = '\0';
  // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: do not cast away const or volatile [autosar-a5-2-3]
}

class C {
 public:
  explicit C(int32_t) {}
};

void F2() noexcept(false) {
  C const a1 = C(10);
  C* a2 = const_cast<C*>(&a1);
  // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: do not cast away const or volatile [autosar-a5-2-3]
  C* a3 = (C*)&a1;
  // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: do not cast away const or volatile [autosar-a5-2-3]
}

extern volatile int32_t* F3() noexcept;

void F4() noexcept {
  volatile int32_t* ptr1 = F3();

  int32_t* ptr2 = const_cast<int32_t*>(ptr1);
  // CHECK-MESSAGES: :[[@LINE-1]]:19: warning: do not cast away const or volatile [autosar-a5-2-3]

  int32_t* ptr3 = (int32_t*)ptr1;
  // CHECK-MESSAGES: :[[@LINE-1]]:19: warning: do not cast away const or volatile [autosar-a5-2-3]
}