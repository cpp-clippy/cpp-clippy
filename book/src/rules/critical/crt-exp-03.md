---
description: >-
  The value returned by a function having a non-void return type that is not an
  overloaded operator shall be used.
---

# Rule CRT-EXP-03

* **Classification:** _Required_
* **Offers Fixes:** _No_

## What it does?

This check warns on unused function return values. The checked functions can be configured.

## Why is this bad?

A called function may provide essential information about its process status and result through return statement. Calling a function without using the return value should be a warning that incorrect assumptions about the process were made.&#x20;

Overloaded operators are excluded, as they should behave in the same way as built- in operators.

{% hint style="warning" %}
**Exception**

The return value of a function call may be discarded by use of a _static\_cast_ cast, so intentions of a programmer are explicitly stated.
{% endhint %}

## Example

```cpp
#include <algorithm>
#include <cstdint>
#include <vector>

std::uint8_t fun_1() noexcept { return 0U; }

void fun_2() noexcept {
    std::uint8_t x = fun_1();    // Compliant by exception
    fun_1();                     // Non-Compliant
    static_cast<void>(fun_1());  // Compliant by exception
}

void fun_3() {
    std::vector<std::int8_t> v{0, 1, 2};
    std::unique(v.begin(), v.end());                    // Non-Compliant
    v.erase(std::unique(v.begin(), v.end()), v.end());  // Compliant
}
```

### See also

* Autosar March 2019: A0-1-2 The value returned by a function having a non-void return type that is not an overloaded operator shall be used.
* MISRA C++ 2008: 0-1-7 The value returned by a function having a non-void return type that is not an overloaded operator shall always be used.&#x20;
* HIC++ v4.0: 17.5.1 Do not ignore the result of std::remove, std::remove\_if or std::unique.
