// RUN: %check_clang_tidy %s autosar-a5-2-2 %t

#include <stdint.h>

class C {
 public:
  explicit C(int32_t) {}
  virtual void Fn() noexcept {}
};

class D : public C {
 public:
  void Fn() noexcept override {}
};

class E {};

int32_t G() noexcept { return 7; }

void F() noexcept(false) {
  C a1 = C{10}; 
  C* a2 = (C*)(&a1);
  // CHECK-MESSAGES: :[[@LINE-1]]:11: warning: do not use C-style cast [autosar-a5-2-2]
  const C a3(5);

  C* a4 = const_cast<C*>(&a3);
  E* d1 = reinterpret_cast<E*>(a4);
  D* d2 = dynamic_cast<D*>(a2);
  int16_t x1 = 20;
  int32_t x2 = static_cast<int32_t>(x1); 
  int32_t x3 = (int32_t)x1;
  // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: do not use C-style cast [autosar-a5-2-2]
  int32_t x4 = 10;
  float f1 = static_cast<float>(x4);
  float f2 = (float)x4;
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: do not use C-style cast [autosar-a5-2-2]
  int32_t x5 = static_cast<int32_t>(f1);
  int32_t x6 = (int32_t)f1;
  // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: do not use C-style cast [autosar-a5-2-2]
  (void)G();
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: do not use C-style cast [autosar-a5-2-2]
  static_cast<void>(G()); 
}
