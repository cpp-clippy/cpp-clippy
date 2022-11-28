// RUN: %check_cpp_clippy %s critical-crt-exp-02 %t

struct Base
{
    virtual ~Base() {}
};
 
struct Derived: Base
{
    virtual void name() {}
};

void Fn(Base* bptr) noexcept {
  Derived* d = dynamic_cast<Derived*>(bptr);
  // CHECK-MESSAGES: :[[@LINE-1]]:16: warning: do not use dynamic_cast [critical-crt-exp-02]
}
