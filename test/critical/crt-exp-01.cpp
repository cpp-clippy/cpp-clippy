// RUN: %check_cpp_clippy %s critical-crt-exp-01 %t

void reinterpretcast() {
  int i = 0;
  void *j;
  j = (int*)j;
  // CHECK-MESSAGES: :[[@LINE-1]]:7: warning: do not use C-style cast [critical-crt-exp-01]
}

void constcast() {
  int* i;
  const int* j;
  i = (int*)j;
  // CHECK-MESSAGES: :[[@LINE-1]]:7: warning: do not use C-style cast
  j = (const int*)i;
  // CHECK-MESSAGES: :[[@LINE-1]]:7: warning: do not use C-style cast
  (void)j;
  // CHECK-MESSAGES: :[[@LINE-1]]:3: warning: do not use C-style cast
}

void const_and_reinterpret() {
  int* i;
  const void* j;
  i = (int*)j;
  // CHECK-MESSAGES: :[[@LINE-1]]:7: warning: do not use C-style cast
}

class Base {
};

class Derived : public Base {
};

class Base2 {
};

class MultiDerived : public Base, public Base2 {
};

class PolymorphicBase {
public:
  virtual ~PolymorphicBase();
};

class PolymorphicDerived : public PolymorphicBase {
};

class PolymorphicMultiDerived : public Base, public PolymorphicBase {
};

void pointers() {

  auto P0 = (Derived*)new Base();
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast

  const Base* B0;
  auto PC0 = (const Derived*)(B0);
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: do not use C-style cast

  auto P1 = (Base*)new Derived();
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast

  auto P2 = (Base*)new MultiDerived();
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast

  auto P3 = (Base2*)new MultiDerived();
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast
}

void pointers_polymorphic() {

  auto PP0 = (PolymorphicDerived*)new PolymorphicBase();
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: do not use C-style cast

  const PolymorphicBase* B0;
  auto PPC0 = (const PolymorphicDerived*)B0;
  // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: do not use C-style cast

  auto B1 = (PolymorphicBase*)new PolymorphicDerived();
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast

  auto B2 = (PolymorphicBase*)new PolymorphicMultiDerived();
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast

  auto B3 = (Base*)new PolymorphicMultiDerived();
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast
}

void arrays() {
  Base ArrayOfBase[10];
  auto A0 = (Derived*)ArrayOfBase;
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast
}

void arrays_polymorphic() {
  PolymorphicBase ArrayOfPolymorphicBase[10];
  auto AP0 = (PolymorphicDerived*)ArrayOfPolymorphicBase;
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: do not use C-style cast
}

void references() {
  Base B0;
  auto R0 = (Derived&)B0;
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast
  Base& RefToBase = B0;
  auto R1 = (Derived&)RefToBase;
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast

  const Base& ConstRefToBase = B0;
  auto RC1 = (const Derived&)ConstRefToBase;
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: do not use C-style cast


  Derived RD1;
  auto R2 = (Base&)RD1;
  // CHECK-MESSAGES: :[[@LINE-1]]:13: warning: do not use C-style cast
}

void references_polymorphic() {
  PolymorphicBase B0;
  auto RP0 = (PolymorphicDerived&)B0;
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: do not use C-style cast

  PolymorphicBase& RefToPolymorphicBase = B0;
  auto RP1 = (PolymorphicDerived&)RefToPolymorphicBase;
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: do not use C-style cast

  const PolymorphicBase& ConstRefToPolymorphicBase = B0;
  auto RPC2 = (const PolymorphicDerived&)(ConstRefToPolymorphicBase);
  // CHECK-MESSAGES: :[[@LINE-1]]:15: warning: do not use C-style cast

  PolymorphicDerived d1;
  auto RP2 = (PolymorphicBase&)d1;
  // CHECK-MESSAGES: :[[@LINE-1]]:14: warning: do not use C-style cast
}

template<class B, class D>
void templ() {
  auto B0 = (B*)new D();
}

void templ_call() {
  templ<Derived, Base>();
  // CHECK-MESSAGES: :[[@LINE-5]]:13: warning: do not use C-style cast
}