---
description: Do not use C-style casts
---

# Rule CRT-EXP-01

* **Classification:** _Required_

## What it does?

This check flags all use of _C-style casts_

## Why is this bad?

C-style casts are more dangerous than the C++ named conversion operators. The C-style casts are difficult to locate in large programs and the intent of the conversion is not explicit.&#x20;

Traditional C-style casts raise several concerns:&#x20;

* C-style casts enable most any type to be converted to most any other type without any indication of the reason for the conversion.
* C-style cast syntax is difficult to identify for both reviewers and tools. Consequently, both the location of conversion expressions as well as the subsequent analysis of the conversion rationale proves difficult for C-style casts.

Thus, C++ introduces casts (_const\_cast_, _dynamic\_cast_, _reinterpret\_cast_, and _static\_cast_) that address these problems. These casts are not only easy to identify, but they also explicitly communicate the developer’s intent for applying a cast.

**Note:** C-style _**(T)expression**_ cast means to perform the first of the following that is possible:&#x20;

1. a const\_cast
2. a static\_cast
3. a static\_cast followed by a const\_cast
4. a reinterpret\_cast
5. a reinterpret\_cast followed by a const\_cast. This rule bans (T)expression only when used to perform an unsafe cast.

## Example

```cpp
#include <cstdint>

void Func() {
    std::int8_t x1{1};
    std::int16_t x3 = (std::int16_t)x1;               // Non-compliant
    std::int16_t x2 = static_cast<std::int16_t>(x1);  // Compliant
}
```

### See also

* Autosar March 2019: A5-2-2
* JSF December 2005: AV Rule 185
* [C++ Core Guidelines - Pro Type: C-Style Cast](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Pro-type-cstylecast.)&#x20;
