//
// Created by andreas on 04.08.24.
//

#ifndef FUN_WITH_ALGOS_RANGE_SUM_OF_SORTED_SUBARRAYS_H
#define FUN_WITH_ALGOS_RANGE_SUM_OF_SORTED_SUBARRAYS_H
// You are given an array with n elements and two indices 'left' and 'right'. Compute the
// array 'sub_sums' of size n*(n+1)/2 that contains all non-empty continuous sub-array sums.
// Sort the 'sub_sums' array and return the sum of the elements from 'left' and 'right'
// inclusive ('left' and 'right' are 1-indexed).
#include <vector>
#include <algorithm>

int range_sum_brute_force(std::vector<int> &nums, int n, int left, int right) {
    std::vector<int> sub_sums;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        // Iterate through all indices ahead of the current index.
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            sub_sums.push_back(sum);
        }
    }
    int mod{1000000007};
    std::sort(sub_sums.begin(), sub_sums.end());
    int result{};
    for (int i{left - 1}; i < right; ++i) {
        result = result % mod + sub_sums[i] % mod;
    }
    return result;
}

#endif //FUN_WITH_ALGOS_RANGE_SUM_OF_SORTED_SUBARRAYS_H
