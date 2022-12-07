---
description: Declare numerations as scoped enum classes
---

# Rule CRT-EXP-08

* **Classification:** _Required_
* **Offers Fixes:** _Yes_

## What it does?

The check detects all unscoped enum declarations.

## Why is this bad?

If unscoped enumeration enum is declared in a global scope, then its values can redeclare constants declared with the same identifier in the global scope. This may lead to developer’s confusion. Using enum-class as enumeration encloses its enumerators in its inner scope and prevent redeclaring identifiers from outer scope. Note that enum class enumerators disallow implicit conversion to numeric values.

## Example

```cpp
enum E1 : std::uint8_t // Non-compliant 
{
    E11, 
    E12, 
    E13 
}; 

enum class E1 : std::uint8_t // Compliant 
{ 
    E11, 
    E12, 
    E13 
};
```

### See also

* Autosar March 2019: A7-2-3 Enumerations shall be declared as scoped enum classes.
* [C++ Core Guidelines: Enum.3 Prefer class enums over "‘plain"’ enums.](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Renum-class)
