//
// Created by andreas on 06.10.23.
//

#ifndef MAXIMIZE_PRODUCT_FROM_GIVEN_TARGET_H
#define MAXIMIZE_PRODUCT_FROM_GIVEN_TARGET_H

#include <concepts>
#include <vector>
// Given an integer n, break it into the sum of k positive integers, where k >= 2,
// and maximize the product of those integers.
// Return the maximum product you can get.

template<typename T>
requires std::is_unsigned_v<T>
T maximize(T target, std::vector<T> &memo) {
    if (target < 4)
        return target;
    if (memo[target] != 0)
        return memo[target];
    T result = target;
    for (T i{2}; i <= target; ++i) {
        result = std::max(result, i * maximize(target - i, memo));
    }
    memo[target] = result;
    return result;
}

template<typename T>
requires std::is_unsigned_v<T>
T maximize_product_top_down(T target) {
    if (target < 4)
        return target - 1;
    auto memo = std::vector<T>(target + 1, 0);
    return maximize(target, memo);
}

template<typename T>
requires std::is_unsigned_v<T>
T maximize_product_bottom_up(T target) {
    if (target < 4)
        return target - 1;
    auto dp = std::vector<T>(target + 1, 0);
    for (T i{1}; i < 4; ++i)
        dp[i] = i;

    for (T number{4}; number <= target; ++number) {
        T result = number;
        for (T i{2}; i < number; ++i) {
            result = std::max(result, i * dp[number - i]);
        }
        dp[number] = result;
    }
    return dp[target];
}

template<typename T>
requires std::is_unsigned_v<T>
T maximize_product_math(T target) {
    if (target < 4)
        return target - 1;
    T result{1};
    while (target > 4) {
        result *= 3;
        target -= 3;
    }
    return target * result;
}


#endif //MAXIMIZE_PRODUCT_FROM_GIVEN_TARGET_H

