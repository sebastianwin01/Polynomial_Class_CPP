# Polynomial Class in C++

A C++ implementation of a polynomial class built to practice **dynamic memory management**, **the Rule of Five**, and basic **polynomial calculus**. The class stores coefficients in a dynamically allocated array and supports polynomial evaluation and differentiation.

## Polynomial representation

A polynomial is represented as

\[
P(x) = a_0 + a_1x + a_2x^2 + \cdots + a_{n-1}x^{n-1}.
\]

The coefficients are stored in **ascending order of power**:

```cpp
polynomial p{1.0, 2.0, 3.0};
```

This represents \(P(x) = 1 + 2x + 3x^2\), where `coef_[0]` is the constant term, `coef_[1]` is the coefficient of \(x\), and so on.

## Features

- **Initializer-list constructor:** Creates a polynomial from a list of coefficients.
- **Destructor:** Releases the dynamically allocated coefficient array using `delete[]`.
- **Copy constructor:** Performs a deep copy so that objects own independent arrays.
- **Copy assignment:** Replaces the coefficients of an existing polynomial, safely handling self-assignment.
- **Move constructor:** Transfers ownership of the coefficient array without copying its elements.
- **Move assignment:** Releases the destination's existing array and transfers ownership from another polynomial.
- **Derivative:** Returns a new polynomial representing the first derivative.
- **Evaluation:** Computes the value of the polynomial at a specified `double` input.
- **Accessors:** `size()` returns the number of stored coefficients, and `coefficients()` provides read-only access to their array.

## Rule of Five

Because the class manages a raw `double*`, it explicitly defines all five special member functions:

| Function | Purpose |
|---|---|
| `~polynomial()` | Releases owned memory |
| `polynomial(const polynomial&)` | Deep-copies coefficients |
| `operator=(const polynomial&)` | Deep-copies during assignment |
| `polynomial(polynomial&&) noexcept` | Transfers ownership during construction |
| `operator=(polynomial&&) noexcept` | Transfers ownership during assignment |

After a move, the source object's `coef_` is set to `nullptr` and `len_` to `0`, leaving it safe to destroy or assign to again.

## Calculus and evaluation

**Derivative.** For

\[
P(x) = \sum_{i=0}^{n-1} a_i x^i,
\]

the first derivative is

\[
P'(x) = \sum_{i=1}^{n-1} i a_i x^{i-1}.
\]

The `derivative()` method creates a separate result polynomial with coefficients `i * coef_[i]`. For constant or empty polynomials, it returns the zero polynomial, represented by `{0}`.

**Evaluation.** The `evaluate(double x) const` method computes

\[
P(x) = \sum_{i=0}^{n-1} a_i x^i
\]

using a loop that updates the current power of `x`. It does not modify the polynomial.

## Usage example

```cpp
#include <iostream>
#include "polynomial.h"

int main() {
    polynomial p{1.0, 2.0, 3.0}; // P(x) = 1 + 2x + 3x^2

    std::cout << "P(2) = " << p.evaluate(2.0) << '\n';

    polynomial dp = p.derivative(); // P'(x) = 2 + 6x
    std::cout << "P'(2) = " << dp.evaluate(2.0) << '\n';
    std::cout << "Coefficient count = " << p.size() << '\n';
}
```

Expected output:

```text
P(2) = 17
P'(2) = 14
Coefficient count = 3
```

## Implementation notes

- The class uses `new[]` and `delete[]` intentionally as an exercise in manual resource management and copy/move semantics.
- `size()` reports the number of stored coefficients; trailing zero coefficients are not automatically removed by the implementation shown.
- `coefficients()` returns a `const double*` that remains owned by the polynomial object. Callers must not free it, and it becomes invalid when the object's storage is released or replaced.
- This README documents only the methods present in the supplied implementation. Arithmetic operators such as `+` and `*` are **not** claimed as implemented.

## Learning goals

This project practices C++ class design, RAII, deep copying, move semantics, const-correctness, initializer lists, and translating mathematical operations into code.
