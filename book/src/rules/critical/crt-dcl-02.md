---
description: Type wchar_t shall not be used
---

# Rule CRT-DCL-02

* **Classification:** _Required_
* **Offers Fixes:** _No_

## What it does?

Detects all uses of wchar\_t type

## Why is this bad?

Width of wchar\_t type is implementation-defined. Use types char16\_t and char32\_t instead.

## Example

```cpp
char16_t string_1[] = u"AAA"; // Compliant
char32_t string_2[] = U"BBB"; // Compliant 
wchar_t  string_3[] = L"CCC"; // Non-compliant
```

### See also

* Autosar March 2019: Rule A2-13-3 Type wchar\_t shall not be used.
