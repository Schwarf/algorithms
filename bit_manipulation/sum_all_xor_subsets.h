//
// Created by andreas on 20.05.24.
//

#ifndef BIT_MANIPULATION_SUM_ALL_XOR_SUBSETS_H
#define BIT_MANIPULATION_SUM_ALL_XOR_SUBSETS_H
// The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
// For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// Given an array nums, return the sum of all XOR totals for every subset of nums.
// Note: Subsets with the same elements should be counted multiple times.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
#include <vector>

// O(2^N) runtime complexity with optimal backtracking
// O(N) space complexity
int compute_xor_sums(const std::vector<int> &input, int index = 0, int current_sum = 0) {
    if (index == input.size())
        return current_sum;

    auto include = compute_xor_sums(input, index + 1, current_sum ^ input[index]);
    auto exclude = compute_xor_sums(input, index + 1, current_sum);
    return include + exclude;
}

// O(N) runtime complexity with optimal algorithm
// O(1) space complexity
int compute_xor_sums_optimal(const std::vector<int> &input) {
    int or_sum{};
    // Capture each bit that is set in any of the elements
    for (const auto element: input) {
        or_sum |= element;
    }
    // Multiply by the number of subset XOR totals that will have each bit set
    // Effectively we multiply or_sum with 2^(N-1)
    return or_sum << (input.size() - 1);
}


#endif //BIT_MANIPULATION_SUM_ALL_XOR_SUBSETS_H
