// RUN: %check_cpp_clippy %s critical-crt-exp-03 %t

namespace std {
using uint8_t = char;

template <typename ForwardIt>
ForwardIt unique(ForwardIt, ForwardIt);

template <typename T> struct vec_iterator {
  T ptr;
  vec_iterator operator++(int);

  template <typename X>
  vec_iterator(const vec_iterator<X> &); // Omit enable_if<...>.
};

template <typename T> struct vector {
  typedef vec_iterator<T*> iterator;

  iterator begin();
  iterator end();

  void erase(iterator);
  void erase(iterator, iterator);
};

void memcpy(void *, const void *, decltype(sizeof(int)));
}

namespace ns {

struct Outer {
  struct Inner {
    bool memFun();
  };
};

using AliasName = Outer;

struct Derived : public Outer::Inner {};

struct Retval {
  int *P;
  Retval() { P = new int; }
  ~Retval() { delete P; }
};

struct Type {
  Retval memFun();
  static Retval staticFun();
};

template <typename T>
struct ClassTemplate {
  Retval memFun();
  static Retval staticFun();
};

} // namespace ns

struct StreamClass {
  StreamClass &operator<<(unsigned int i) { return *this; }
  StreamClass &operator>>(unsigned int i) { return *this; }
};

std::uint8_t fun1() noexcept { return 0U; }
void fun1(int);

void warning() noexcept {
  fun1();
  // CHECK-NOTES: [[@LINE-1]]:3: warning: the value returned by this function should be used
  // CHECK-NOTES: [[@LINE-2]]:3: note: cast the expression to void to silence this warning
  
  (fun1());
  // CHECK-NOTES: [[@LINE-1]]:4: warning: the value {{.*}} should be used
  // CHECK-NOTES: [[@LINE-2]]:4: note: cast {{.*}} this warning

  ns::Outer::Inner ObjA1;
  ObjA1.memFun();
  // CHECK-NOTES: [[@LINE-1]]:3: warning: the value {{.*}} should be used
  // CHECK-NOTES: [[@LINE-2]]:3: note: cast {{.*}} this warning

  ns::AliasName::Inner ObjA2;
  ObjA2.memFun();
  // CHECK-NOTES: [[@LINE-1]]:3: warning: the value {{.*}} should be used
  // CHECK-NOTES: [[@LINE-2]]:3: note: cast {{.*}} this warning

  ns::Derived ObjA3;
  ObjA3.memFun();
  // CHECK-NOTES: [[@LINE-1]]:3: warning: the value {{.*}} should be used
  // CHECK-NOTES: [[@LINE-2]]:3: note: cast {{.*}} this warning

  ns::Type::staticFun();
  // CHECK-NOTES: [[@LINE-1]]:3: warning: the value {{.*}} should be used
  // CHECK-NOTES: [[@LINE-2]]:3: note: cast {{.*}} this warning

  ns::ClassTemplate<int> ObjA4;
  ObjA4.memFun();
  // CHECK-NOTES: [[@LINE-1]]:3: warning: the value {{.*}} should be used
  // CHECK-NOTES: [[@LINE-2]]:3: note: cast {{.*}} this warning

  ns::ClassTemplate<int>::staticFun();
  // CHECK-NOTES: [[@LINE-1]]:3: warning: the value {{.*}} should be used
  // CHECK-NOTES: [[@LINE-2]]:3: note: cast {{.*}} this warning
}

void no_warning() {
  std::uint8_t x = fun1();

  static_cast<void>(fun1());

  std::vector<std::uint8_t> v;
  v.erase(std::unique(v.begin(), v.end()), v.end());

  auto R1 = fun1();

  ns::Outer::Inner ObjB1;
  auto R2 = ObjB1.memFun();

  auto R3 = ns::Type::staticFun();

  ns::ClassTemplate<int> ObjB2;
  auto R4 = ObjB2.memFun();

  auto R5 = ns::ClassTemplate<int>::staticFun();

  // test calling a void overload of a function
  fun1(5);

  StreamClass s;
  unsigned char ui = 1u;
  s << 1u; // Ok
  s >> ui;  // Ok

  char source[] = "once upon a midnight dreary...", dest[4];
  std::memcpy(dest, source, sizeof dest);
}