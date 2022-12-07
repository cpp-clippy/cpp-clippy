---
description: Literal suffixes shall be upper case
---

# Rule CRT-DCL-01

* **Classification:** _Required_
* **Offers Fixes:** _Yes_

## What it does?

Detects when the integral literal or floating point (decimal or hexadecimal) literal has a non-uppercase suffix and provides a fix-it hint with the uppercase suffix.

## Why is this bad?

Using lower case literal suffixes creates potential ambiguity between "1" (digit 1) and "l" (letter el) for declaring literals.

## Example

```cpp
auto x = 1;  // OK, no suffix.
auto x = 1u; // warning: integer literal suffix 'u' is not upper-case 
auto x = 1U; // OK, suffix is uppercase.
```

### See also

* Autosar March 2019: M2-13-4 Literal suffixes shall be upper case.
* SEI CERT C++ Coding Standard: DCL16-CPP. Use "L," not "l," to indicate a long value
