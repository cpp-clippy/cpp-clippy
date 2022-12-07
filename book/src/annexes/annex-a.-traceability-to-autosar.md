---
description: Traceability to Autosar C++14 Release 19-03
---

# Annex A. Traceability to Autosar

| Autosar Rule                                                                                                                                                              | Relation Type | Related Rule | Comment |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-----------: | :----------: | ------- |
| A0-1-2 (required) The value returned by a function having a non-void return type that is not an overloaded operator shall be used.                                        |   Identical   |  CRT-EXP-03  | -       |
| M2-13-4 (required) Literal suffixes shall be upper case.                                                                                                                  |   Identical   |  CRT-DCL-01  | -       |
| A2-13-3 (required) Type wchar\_t shall not be used.                                                                                                                       |   Identical   |  CRT-DCL-01  | -       |
| A5-2-1 (advisory) dynamic\_cast should not be used.                                                                                                                       |   Identical   |  CRT-EXP-02  | -       |
| A5-2-2 (required) Traditional C-style casts shall not be used.                                                                                                            |   Identical   |  CRT-EXP-01  | -       |
| A5-2-3 (required) A cast shall not remove any const or volatile qualification from the type of a pointer or reference.                                                    |   Identical   |  CRT-EXP-04  | -       |
| A7-1-1 (required) Constexpr or const specifiers shall be used for immutable data declaration.                                                                             |   Identical   |  CRT-EXP-05  | -       |
| M7-1-2 (required) A pointer or reference parameter in a function shall be declared as pointer to const or reference to const if the corresponding object is not modified. |   Identical   |  CRT-EXP-09  | -       |
| A7-1-6 (required) The typedef specifier shall not be used.                                                                                                                |   Identical   |  CRT-EXP-06  | -       |
| A7-2-2 (required) Enumeration underlying base type shall be explicitly defined.                                                                                           |   Identical   |  CRT-EXP-07  | -       |
| A7-2-3 (required) Enumerations shall be declared as scoped enum classes.                                                                                                  |   Identical   |  CRT-EXP-08  | -       |
