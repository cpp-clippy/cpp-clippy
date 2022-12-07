// RUN: %check_cpp_clippy %s critical-crt-dcl-01 %t

void floating_point_suffix() {
  static constexpr auto v0 = 0x0p0; // no literal
  static_assert(v0 == 0, "");

  // Float

  static constexpr auto v1 = 0xfp0f;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: floating point literal has suffix 'f', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v1 = 0xfp0f;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}F{{$}}
  // CHECK-FIXES: static constexpr auto v1 = 0xfp0F;
  static_assert(v1 == 15, "");

  static constexpr auto v2 = 0xfp0F; // OK
  static_assert(v2 == 15, "");

  static constexpr auto v3 = 0xfP0f;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: floating point literal has suffix 'f', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v3 = 0xfP0f;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}F{{$}}
  // CHECK-FIXES: static constexpr auto v3 = 0xfP0F;
  static_assert(v3 == 15, "");

  static constexpr auto v4 = 0xfP0F; // OK
  static_assert(v4 == 15, "");

  static constexpr auto v5 = 0xFP0f;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: floating point literal has suffix 'f', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v5 = 0xFP0f;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}F{{$}}
  // CHECK-FIXES: static constexpr auto v5 = 0xFP0F;
  static_assert(v5 == 15, "");

  static constexpr auto v6 = 0xFP0F; // OK
  static_assert(v6 == 15, "");

  static constexpr auto v7 = 0xFp0f;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: floating point literal has suffix 'f', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v7 = 0xFp0f;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}F{{$}}
  // CHECK-FIXES: static constexpr auto v7 = 0xFp0F;
  static_assert(v7 == 15, "");

  static constexpr auto v8 = 0xFp0F; // OK
  static_assert(v8 == 15, "");

  // long double

  static constexpr auto v9 = 0xfp0l;
  // CHECK-MESSAGES: :[[@LINE-1]]:30: warning: floating point literal has suffix 'l', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v9 = 0xfp0l;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}L{{$}}
  // CHECK-FIXES: static constexpr auto v9 = 0xfp0L;
  static_assert(v9 == 0xfp0, "");

  static constexpr auto v10 = 0xfp0L; // OK.
  static_assert(v10 == 0xfp0, "");

  // __float128

  static constexpr auto v11 = 0xfp0q;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: floating point literal has suffix 'q', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v11 = 0xfp0q;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}Q{{$}}
  // CHECK-FIXES: static constexpr auto v11 = 0xfp0Q;
  static_assert(v11 == 0xfp0, "");

  static constexpr auto v12 = 0xfp0Q; // OK.
  static_assert(v12 == 0xfp0, "");
}

void floating_point_complex_suffix() {
  // _Complex, I

  static constexpr auto v14 = 0xfp0i;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: floating point literal has suffix 'i', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v14 = 0xfp0i;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}I{{$}}
  // CHECK-FIXES: static constexpr auto v14 = 0xfp0I;
  static_assert(v14 == 0xfp0I, "");

  static constexpr auto v16 = 0xfp0I; // OK.
  static_assert(v16 == 0xfp0I, "");

  // _Complex, J

  static constexpr auto v18 = 0xfp0j;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: floating point literal has suffix 'j', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v18 = 0xfp0j;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}J{{$}}
  // CHECK-FIXES: static constexpr auto v18 = 0xfp0J;
  static_assert(v18 == 0xfp0J, "");

  static constexpr auto v20 = 0xfp0J; // OK.
  static_assert(v20 == 0xfp0J, "");
}

void macros() {
#define PASSTHROUGH(X) X
  static constexpr auto m0 = PASSTHROUGH(0x0p0f);
  // CHECK-MESSAGES: :[[@LINE-1]]:42: warning: floating point literal has suffix 'f', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto m0 = PASSTHROUGH(0x0p0f);
  // CHECK-MESSAGES-NEXT: ^ ~
  // CHECK-MESSAGES-NEXT: {{^ *}}F{{$}}
  // CHECK-FIXES: static constexpr auto m0 = PASSTHROUGH(0x0p0F);
  static_assert(m0 == 0x0p0F, "");
}