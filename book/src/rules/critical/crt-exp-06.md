---
description: Do no use typedef specifier
---

# Rule CRT-EXP-06

* **Classification:** _Required_
* **Offers Fixes:** _Yes_

## What it does?

The check converts the usage of _typedef_ with _using_ keyword.

## Why is this bad?

The typedef specifier can not be easily used for defining alias templates. Also, the typedef syntax makes the code less readable.&#x20;

For defining aliases, as well as template aliases, it is recommended to use the _using_ syntax instead of the _typedef_.

## Example

```cpp
typedef std::int8_t (*PFI)(std::int8_t);   // Non-compliant
using PFI2 = std::int8_t (*)(std::int8_t); // Compliant
```

### See also

* Autosar March 2019: A7-1-6 The typedef specifier shall not be used.
* [C++ Core Guidelines: T.43 Prefer using over typedef for defining aliases](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rt-using)&#x20;
