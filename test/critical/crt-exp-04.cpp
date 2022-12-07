// RUN: %check_cpp_clippy %s critical-crt-exp-04 %t

namespace std {
using uint8_t = char;
}

void fun_1(const char* str) {
  *(const_cast<char*>(str)) = '\0';
  // CHECK-MESSAGES: :[[@LINE-1]]:5: warning: do not cast away const or volatile [critical-crt-exp-04]
}

class MyClass {
 public:
  explicit MyClass(std::uint8_t) {}
};

void fun_2() {
  const MyClass a1 = MyClass(0);
  MyClass* a2 = const_cast<MyClass*>(&a1);
  // CHECK-MESSAGES: :[[@LINE-1]]:17: warning: do not cast away const or volatile [critical-crt-exp-04]
  MyClass* a3 = (MyClass*)&a1;
  // CHECK-MESSAGES: :[[@LINE-1]]:17: warning: do not cast away const or volatile [critical-crt-exp-04]
}

extern volatile std::uint8_t* fun_3();

void F4() {
  volatile std::uint8_t* ptr1 = fun_3();

  std::uint8_t* ptr2 = const_cast<std::uint8_t*>(ptr1);
  // CHECK-MESSAGES: :[[@LINE-1]]:24: warning: do not cast away const or volatile [critical-crt-exp-04]
  std::uint8_t* ptr3 = (std::uint8_t*)ptr1;
  // CHECK-MESSAGES: :[[@LINE-1]]:24: warning: do not cast away const or volatile [critical-crt-exp-04]
}

const int* i;
int* j;
void f() { j = const_cast<int*>(i); }
// CHECK-MESSAGES: :[[@LINE-1]]:16: warning: do not cast away const or volatile [critical-crt-exp-04]
