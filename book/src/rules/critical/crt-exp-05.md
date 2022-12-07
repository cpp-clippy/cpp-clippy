---
description: Use Constexpr or const specifiers for immutable data declaration.
---

# Rule CRT-EXP-05

* **Classification:** _Required_
* **Offers Fixes:** _Yes_

## What it does?

This check detects local variables which could be declared as const but are not.

## Why is this bad?

If data is declared to be const or constexpr then its value can not be changed by mistake. Also, such declaration can offer the compiler optimization opportunities.

Note that the constexpr specifier in an object declaration implies const as well.

## Example

```cpp
void f(int n)
{ 
    const int bufmax = 2 * n + 2;  // Compliant
    constexpr int y = 9;           // Compliant
    int xmax = n;                  // Non-Compliant
}
```

### See also

* Autosar March 2019: A7-1-1 Constexpr or const specifiers shall be used for immutable data declaration.
* [C++ Core Guidelines: ES.25: Declare objects const or constexpr unless you want to modify its value later on. ](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-const)
* [C++ Core Guidelines: Con.1: By default, make objects immutable. ](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-immutable)
* [C++ Core Guidelines: Con.4: Use const to define objects with values that do not change after construction.](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-const)
