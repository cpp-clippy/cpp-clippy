---
description: Do not use dynamic_cast
---

# Rule critical-crt-exp-02

* **Classification:** _Advisory_
* **Offers Fixes:** _No_

## What it does?

This check flags all use of _dynamic\_cast_.

## Why is this bad?

Implementations of dynamic\_cast mechanism are unsuitable for use with real-time systems where low memory usage and determined performance are essential.

If dynamic casting is essential for your program, usage of its custom implementation should be considered. Also, usage of the dynamic\_cast can be replaced with polymorphism, i.e. virtual functions.

## Example

```cpp
struct Base
{
    virtual ~Base() {}
};
 
struct Derived: Base
{
    virtual void name() {}
};
 
int main()
{
    Base* b = new Base;
    Derived* d = dynamic_cast<Derived*>(b);  // Non-Compliant
}
```

### See also

* JSF December 2005: AV Rule 178 Down casting (casting from base to derived class) shall only be allowed through one of the following mechanism: Virtual functions that act like dynamic casts (most likely useful in relatively simple cases); Use of the visitor (or similar) pattern (most likely useful in complicated cases).
* Autosar March 2019: A5-2-1 dynamic_cast should not be used.
