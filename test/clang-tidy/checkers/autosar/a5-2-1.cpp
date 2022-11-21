// RUN: %check_clang_tidy %s autosar-a5-2-1 %t

class A {
 public:
  virtual void F() noexcept;
};

class B : public A {
  void F() noexcept override {}
};

void Fn(A* aptr) noexcept {
  // ...
  B* bptr = dynamic_cast<B*>(aptr);  // Non-compliant
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use dynamic_cast [autosar-a5-2-1]

  if (bptr != nullptr) {
    // Use B class interface
  } else {
    // Use A class interface
  }
}