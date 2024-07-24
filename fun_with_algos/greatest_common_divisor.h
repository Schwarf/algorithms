//
// Created by andreas on 25.02.24.
//

#ifndef GREATEST_COMMON_DIVISOR_H
#define GREATEST_COMMON_DIVISOR_H

#include <concepts>
#include <valarray>

// Euclidean algorithm: Take two numbers a and b to find the greatest common divisor. Subtract the smaller one from the larger
// until they are equal. That is the greatest common divisor.
// Instead of 'subtract' we divide.
template<typename T>
requires std::is_integral_v<T>
T greatest_common_divisor(T a, T b) {
    // GCD is typically defined to be positive
    if constexpr (std::is_signed_v<T>) {
        a = std::abs(a);
        b = std::abs(b);
    }
    if (a == 0)
        return b;
    while (b != 0) {
        // If b > a, the roles are switched here.
        T h = a % b;
        a = b;
        b = h;
    }
    return a;
}


template<typename T>
requires std::is_integral_v<T>
T greatest_common_divisor_recursive(T a, T b) {
    // GCD is typically defined to be positive
    if constexpr (std::is_signed_v<T>) {
        a = std::abs(a);
        b = std::abs(b);
    }
    if (b == 0)
        return a;
    return greatest_common_divisor_recursive(b, static_cast<T>(a % b));
}

#endif //GREATEST_COMMON_DIVISOR_H
