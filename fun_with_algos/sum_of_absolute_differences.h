//
// Created by andreas on 26.11.23.
//

#ifndef SUM_OF_ABSOLUTE_DIFFERENCES_H
#define SUM_OF_ABSOLUTE_DIFFERENCES_H

#include <vector>
#include <concepts>
#include <numeric>
// You are given an integer array nums sorted in non-decreasing order.
// Build and return an integer array result with the same length as nums such that result[i] is equal to the
// summation of absolute differences between nums[i] and all the other elements in the array.
// In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

// #PREFIX_SUM
template<typename T>
requires std::is_arithmetic_v<T>
std::vector<T> sum_of_absolute_differences(const std::vector<T> &input) {
    int n = input.size();
    auto total = std::accumulate(input.begin(), input.end(), 0);
    T left_sum{};
    std::vector<T> result;
    for (int i{}; i < n; ++i) {
        T right_sum = total - left_sum - input[i];
        int left_count = i;
        int right_count = n - 1 - i;
        T left_total = left_count * input[i] // This the sum of all numbers that are equal to input[i] and left from it
                       -
                       left_sum;             // and we subtract the sum of all numbers left of input[i] to get the sum of absolute differences
        T right_total = right_sum - right_count * input[i];
        result.push_back(left_total + right_total);
        left_sum += input[i];
    }
    return result;
}

#endif //SUM_OF_ABSOLUTE_DIFFERENCES_H
