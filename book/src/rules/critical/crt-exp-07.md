---
description: Define explicitly enumeration underlying base type
---

# Rule CRT-EXP-07

* **Classification:** _Required_
* **Offers Fixes:** _Yes_

## What it does?

The check detects all enum declarations without base type.

## Why is this bad?

The enumeration underlying type is implementation-defined, with the only restriction that the type must be able to represent the enumeration values. Although scoped enum will implicitly define an underlying type of int, the underlying base type of enumeration should always be explicitly defined with a type that will be large enough to store all enumerators.

## Example

```cpp
enum smallenum // Non-Compliant
{ 
    a, 
    b, 
    c 
};

enum smallenum: std::uint8_t // Compliant
{ 
    a, 
    b, 
    c 
};
```

### See also

* Autosar March 2019: A7-2-2 Enumeration underlying base type shall be explicitly defined.
* HIC++ v4.0: 7.2.1 Use an explicit enumeration base and ensure that it is large enough to store all enumerators
