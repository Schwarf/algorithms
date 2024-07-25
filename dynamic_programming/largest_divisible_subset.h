//
// Created by andreas on 10.02.24.
//

#ifndef LARGEST_DIVISIBLE_SUBSET_H
#define LARGEST_DIVISIBLE_SUBSET_H
// Given a set of distinct positive integers nums, return the largest subset answer
// such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
//
// If there are multiple solutions, return any of them.
#include <vector>
#include <algorithm>

std::vector<int> largest_divisible_subset(std::vector<int> &input) {
    int n = input.size();
    std::sort(input.begin(), input.end());


    int max_size{1};
    std::vector<int> dp(n, max_size);
    std::vector<int> parent_indices(n, -1);
    int max_value_index{};
    for (int i{1}; i < n; ++i) {
        for (int j{}; j < i; ++j) {
            if (input[i] % input[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent_indices[i] = j;
            }
        }
        if (dp[i] > max_size) {
            max_size = dp[i];
            max_value_index = i;
        }
    }
    std::vector<int> result;
    for (int i = max_value_index; i != -1; i = parent_indices[i]) {
        result.push_back(input[i]);
    }
    return result;
}

#endif //LARGEST_DIVISIBLE_SUBSET_H
