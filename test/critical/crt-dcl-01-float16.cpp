// RUN: %check_cpp_clippy %s critical-crt-dcl-01 %t

void float16_normal_literals() {
  static constexpr auto v14 = 1.f16;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: floating point literal has suffix 'f16', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v14 = 1.f16;
  // CHECK-MESSAGES-NEXT: ^ ~
  // CHECK-MESSAGES-NEXT: {{^ *}}F16{{$}}
  // CHECK-FIXES: static constexpr auto v14 = 1.F16;
  static_assert(v14 == 1.F16, "");

  static constexpr auto v15 = 1.e0f16;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: floating point literal has suffix 'f16', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v15 = 1.e0f16;
  // CHECK-MESSAGES-NEXT: ^ ~
  // CHECK-MESSAGES-NEXT: {{^ *}}F16{{$}}
  // CHECK-FIXES: static constexpr auto v15 = 1.e0F16;
  static_assert(v15 == 1.F16, "");

  static constexpr auto v16 = 1.F16; // OK.
  static_assert(v16 == 1.F16, "");

  static constexpr auto v17 = 1.e0F16; // OK.
  static_assert(v17 == 1.F16, "");
}

void float16_hexadecimal_literals() {
// _Float16

  static constexpr auto v13 = 0xfp0f16;
  // CHECK-MESSAGES: :[[@LINE-1]]:31: warning: floating point literal has suffix 'f16', which is not uppercase
  // CHECK-MESSAGES-NEXT: static constexpr auto v13 = 0xfp0f16;
  // CHECK-MESSAGES-NEXT: ^    ~
  // CHECK-MESSAGES-NEXT: {{^ *}}F16{{$}}
  // CHECK-FIXES: static constexpr auto v13 = 0xfp0F16;
  static_assert(v13 == 0xfp0F16, "");

  static constexpr auto v14 = 0xfp0F16; // OK.
  static_assert(v14 == 0xfp0F16, "");

}
