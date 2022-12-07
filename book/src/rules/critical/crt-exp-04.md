---
description: Don't cast away const or volatile
---

# Rule CRT-EXP-04

* **Classification:** _Required_
* **Offers Fixes:** _No_

## What it does?

This check flags all uses of const\_cast or C-style casts that remove const or volatile qualification.

## Why is this bad?

Modifying a variable that was declared const is _**undefined behavior**_, even with _const\_cast_.

## Example

```cpp
void fun_1() 
{ 
  const MyClass a1{};
  MyClass* a2 = const_cast<MyClass*>(&a1);  // Non-compliant
  MyClass* a3 = (MyClass*)&a1;  // Non-compliant
}
```

### See also

* Autosar March 2019: A5-2-3 A cast shall not remove any const or volatile qualification from the type of a pointer or reference.
* [C++ Core Guidelines: ES.50: Don’t cast away const.](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Res-casts-const)
