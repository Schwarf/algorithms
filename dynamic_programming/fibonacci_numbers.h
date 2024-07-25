//
// Created by andreas on 08.07.23.
//

#ifndef FIBONACCI_NUMBERS_H
#define FIBONACCI_NUMBERS_H

#include <stdexcept>
#include <array>

// Compute the nth fibonacci number at runtime
unsigned long long n_th_fibonacci_number(int n) {
    if (n > 50)
        throw std::out_of_range("We only compute fibonacci numbers up to 50");

    std::vector<long long> help(n + 1);
    help[0] = 0;
    help[1] = 1;
    for (int i{2}; i < n + 1; ++i)
        help[i] = help[i - 1] + help[i - 2];
    return help[n];
}

// Compute fibonacci numbers at compile time.
constexpr std::array<unsigned long long, 51> first_50_fibonacci_numbers() {
    constexpr int N{51};
    std::array<unsigned long long, N> result{};
    result[0] = 0;
    result[1] = 1;
    for (int i{2}; i < N; ++i)
        result[i] = result[i - 1] + result[i - 2];
    return result;
}

#endif //FIBONACCI_NUMBERS_H
