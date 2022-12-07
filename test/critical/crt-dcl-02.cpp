// RUN: %check_cpp_clippy %s critical-crt-dcl-02 %t

char16_t string1[] = u"A";
char32_t string2[] = U"B";

wchar_t string3[] = L"C";
// CHECK-MESSAGES: :[[@LINE-1]]:1: warning: Do not use wchar_t [critical-crt-dcl-02]

void fun_1(wchar_t* bad) {
// CHECK-MESSAGES: :[[@LINE-1]]:12: warning: Do not use wchar_t
}

