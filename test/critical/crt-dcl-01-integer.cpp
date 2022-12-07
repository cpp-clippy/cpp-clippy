// RUN: %check_cpp_clippy %s critical-crt-dcl-01 %t

void integer_suffix() {
  static constexpr auto v0 = __LINE__; // synthetic

  static constexpr auto v1 = __cplusplus; // synthetic, long

  static constexpr auto v2 = 1; // no literal
  static_assert(v2 == 1, "");

  // Unsigned

  static constexpr auto v3 = 1u;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: integer literal has suffix 'u', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v3 = 1u;
  // CHECK-MESSAGES-NEXT: ^~
  // CHECK-MESSAGES-NEXT: {{^ *}}U{{$}}
  // CHECK-FIXES: static constexpr auto v3 = 1U;
  static_assert(v3 == 1, "");

  static constexpr auto v4 = 1U; // OK.
  static_assert(v4 == 1, "");

  // Long

  static constexpr auto v5 = 1l;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: integer literal has suffix 'l', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v5 = 1l;
  // CHECK-MESSAGES-NEXT: ^~
  // CHECK-MESSAGES-NEXT: {{^ *}}L{{$}}
  // CHECK-FIXES: static constexpr auto v5 = 1L;
  static_assert(v5 == 1, "");

  static constexpr auto v6 = 1L; // OK.
  static_assert(v6 == 1, "");

  // Long Long

  static constexpr auto v7 = 1ll;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: integer literal has suffix 'll', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v7 = 1ll;
  // CHECK-MESSAGES-NEXT: ^~~
  // CHECK-MESSAGES-NEXT: {{^ *}}LL{{$}}
  // CHECK-FIXES: static constexpr auto v7 = 1LL;
  static_assert(v7 == 1, "");

  static constexpr auto v8 = 1LL; // OK.
  static_assert(v8 == 1, "");

  // Unsigned Long

  static constexpr auto v9 = 1ul;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: integer literal has suffix 'ul', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v9 = 1ul;
  // CHECK-MESSAGES-NEXT: ^~~
  // CHECK-MESSAGES-NEXT: {{^ *}}UL{{$}}
  // CHECK-FIXES: static constexpr auto v9 = 1UL;
  static_assert(v9 == 1, "");

  static constexpr auto v10 = 1uL;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'uL', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v10 = 1uL;
  // CHECK-MESSAGES-NEXT: ^~~
  // CHECK-MESSAGES-NEXT: {{^ *}}UL{{$}}
  // CHECK-FIXES: static constexpr auto v10 = 1UL;
  static_assert(v10 == 1, "");

  static constexpr auto v11 = 1Ul;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'Ul', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v11 = 1Ul;
  // CHECK-MESSAGES-NEXT: ^~~
  // CHECK-MESSAGES-NEXT: {{^ *}}UL{{$}}
  // CHECK-FIXES: static constexpr auto v11 = 1UL;
  static_assert(v11 == 1, "");

  static constexpr auto v12 = 1UL; // OK.
  static_assert(v12 == 1, "");

  // Long Unsigned

  static constexpr auto v13 = 1lu;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'lu', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v13 = 1lu;
  // CHECK-MESSAGES-NEXT: ^~~
  // CHECK-MESSAGES-NEXT: {{^ *}}LU{{$}}
  // CHECK-FIXES: static constexpr auto v13 = 1LU;
  static_assert(v13 == 1, "");

  static constexpr auto v14 = 1Lu;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'Lu', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v14 = 1Lu;
  // CHECK-MESSAGES-NEXT: ^~~
  // CHECK-MESSAGES-NEXT: {{^ *}}LU{{$}}
  // CHECK-FIXES: static constexpr auto v14 = 1LU;
  static_assert(v14 == 1, "");

  static constexpr auto v15 = 1lU;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'lU', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v15 = 1lU;
  // CHECK-MESSAGES-NEXT: ^~~
  // CHECK-MESSAGES-NEXT: {{^ *}}LU{{$}}
  // CHECK-FIXES: static constexpr auto v15 = 1LU;
  static_assert(v15 == 1, "");

  static constexpr auto v16 = 1LU; // OK.
  static_assert(v16 == 1, "");

  // Unsigned Long Long

  static constexpr auto v17 = 1ull;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'ull', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v17 = 1ull;
  // CHECK-MESSAGES-NEXT: ^~~~
  // CHECK-MESSAGES-NEXT: {{^ *}}ULL{{$}}
  // CHECK-FIXES: static constexpr auto v17 = 1ULL;
  static_assert(v17 == 1, "");

  static constexpr auto v18 = 1uLL;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'uLL', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v18 = 1uLL;
  // CHECK-MESSAGES-NEXT: ^~~~
  // CHECK-MESSAGES-NEXT: {{^ *}}ULL{{$}}
  // CHECK-FIXES: static constexpr auto v18 = 1ULL;
  static_assert(v18 == 1, "");

  static constexpr auto v19 = 1Ull;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'Ull', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v19 = 1Ull;
  // CHECK-MESSAGES-NEXT: ^~~~
  // CHECK-MESSAGES-NEXT: {{^ *}}ULL{{$}}
  // CHECK-FIXES: static constexpr auto v19 = 1ULL;
  static_assert(v19 == 1, "");

  static constexpr auto v20 = 1ULL; // OK.
  static_assert(v20 == 1, "");

  // Long Long Unsigned

  static constexpr auto v21 = 1llu;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'llu', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v21 = 1llu;
  // CHECK-MESSAGES-NEXT: ^~~~
  // CHECK-MESSAGES-NEXT: {{^ *}}LLU{{$}}
  // CHECK-FIXES: static constexpr auto v21 = 1LLU;
  static_assert(v21 == 1, "");

  static constexpr auto v22 = 1LLu;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'LLu', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v22 = 1LLu;
  // CHECK-MESSAGES-NEXT: ^~~~
  // CHECK-MESSAGES-NEXT: {{^ *}}LLU{{$}}
  // CHECK-FIXES: static constexpr auto v22 = 1LLU;
  static_assert(v22 == 1, "");

  static constexpr auto v23 = 1llU;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'llU', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v23 = 1llU;
  // CHECK-MESSAGES-NEXT: ^~~~
  // CHECK-MESSAGES-NEXT: {{^ *}}LLU{{$}}
  // CHECK-FIXES: static constexpr auto v23 = 1LLU;
  static_assert(v23 == 1, "");

  static constexpr auto v24 = 1LLU; // OK.
  static_assert(v24 == 1, "");
}

void integer_complex_suffix() {
  // _Complex, I

  static constexpr auto v25 = 1i;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'i', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v25 = 1i;
  // CHECK-MESSAGES-NEXT: ^~
  // CHECK-MESSAGES-NEXT: {{^ *}}I{{$}}
  // CHECK-FIXES: static constexpr auto v25 = 1I;
  static_assert(v25 == 1I, "");

  static constexpr auto v26 = 1I; // OK.
  static_assert(v26 == 1I, "");

  // _Complex, J

  static constexpr auto v27 = 1j;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: integer literal has suffix 'j', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v27 = 1j;
  // CHECK-MESSAGES-NEXT: ^~
  // CHECK-MESSAGES-NEXT: {{^ *}}J{{$}}
  // CHECK-FIXES: static constexpr auto v27 = 1J;
  static_assert(v27 == 1J, "");

  static constexpr auto v28 = 1J; // OK.
  static_assert(v28 == 1J, "");
}

void macros() {
#define PASSTHROUGH(X) X
  static constexpr auto m0 = PASSTHROUGH(1u);
  // CHECK-MESSAGES: :[[@LINE-1]]:42: warning: integer literal has suffix 'u', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto m0 = PASSTHROUGH(1u);
  // CHECK-MESSAGES-NEXT: ^~
  // CHECK-MESSAGES-NEXT: {{^ *}}U{{$}}
  // CHECK-FIXES: static constexpr auto m0 = PASSTHROUGH(1U);
  static_assert(m0 == 1, "");

  // This location is inside a macro, no warning on that by default.
#define MACRO 1u
  int foo = MACRO;
}

// Check that user-defined literals do not cause any diags.

unsigned long long int operator"" _ull(unsigned long long int);
void user_defined_literals() {
  1_ull;
}

template <unsigned alignment>
void template_test() {
  static_assert(alignment, "");
}
void actual_template_test() {
  template_test<4>();
}

const int table[6] = {};
void read_test() {
  for (auto i : table) {
  }
}

namespace {
enum a { b };
constexpr bool operator&(a, a) { return int(); }
template <a l>
void c() { l &a(); }
void d();
void d() { c<b>(); }
} // namespace

// Check that non-type template parameters do not cause any diags.
// https://bugs.llvm.org/show_bug.cgi?id=51790
template <int capacity>
struct Vector {
  static constexpr int kCapacity = capacity;
};

template <int capacity>
constexpr int Vector<capacity>::kCapacity;
// CHECK-MESSAGES-NOT: :[[@LINE-1]]:22: warning: integer literal has suffix 'ity', which is not uppercase

template <int foo1u>
struct Foo {
  static constexpr int kFoo = foo1u;
};

template <int foo1u>
constexpr int Foo<foo1u>::kFoo;
// CHECK-MESSAGES-NOT: :[[@LINE-1]]:19: warning: integer literal has suffix 'u', which is not uppercase

// The template needs to be instantiated for diagnostics to show up
void test_non_type_template_parameter() {
  int x = Vector<10>::kCapacity;
  int f = Foo<10>::kFoo;
}