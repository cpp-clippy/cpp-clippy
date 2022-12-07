---
description: >-
  Pass pointers and references to const if the corresponding object is not
  modified.
---

# Rule CRT-EXP-09

* **Classification:** _Required_
* **Offers Fixes:** _Yes_

## What it does?

The check finds function parameters of a pointer type that could be changed to point to a constant type instead.

{% hint style="warning" %}
This check still does not  check function parameters of a reference type.  See [https://github.com/cpp-clippy/cpp-clippy/issues/14](https://github.com/cpp-clippy/cpp-clippy/issues/14)
{% endhint %}

## Why is this bad?

When const is used properly, many mistakes can be avoided. Advantages when using const properly:&#x20;

* prevent unintentional modification of data
* get additional warnings such as using uninitialized data
* make it easier for developers to see possible side effects.

## Example

```cpp
 char f1(char *p)  // Non-compliant
{ 
  return *p; 
} 

int f2(const int *p) // Compliant
{ 
  return *p; 
}
```

### See also

* Autosar March 2019: M7-1-2 A pointer or reference parameter in a function shall be declared as pointer to const or reference to const if the corresponding object is not modified.
* [C++ Core Guidelines: Con.3: By default, pass pointers and references to consts.](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-ref)
