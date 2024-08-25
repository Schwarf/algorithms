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
#include <numeric>

int range_sum_brute_force(std::vector<int> &input, int left, int right) {
    std::vector<int> sub_sums;
    for (int i = 0; i < input.size(); i++) {
        int sum = 0;
        // Iterate through all indices ahead of the current index.
        for (int j = i; j < input.size(); j++) {
            sum += input[j];
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
// This function computes the count and the sum of all subarray-sums 's' where each 's' is lower than 'target'.
std::pair<int, long long> count_subarrays_sums_below_target(std::vector<int> &input, int n, int target) {
    int count = 0;
    long long current_sum{};
    long long total_sum{};
    long long window_sum{};
    for (int j = 0, i = 0; j < n; ++j) {
        current_sum += input[j];
        // The window_sum computes the contribution of input[j] to all subarray-sums from [i..j].
        window_sum += input[j] * (j - i + 1);
        while (current_sum > target) {
            window_sum -= current_sum;
            current_sum -= input[i++];
        }
        count += j - i + 1;
        total_sum += window_sum;
    }
    return {count, total_sum};
}

long long sum_of_first_k(std::vector<int>& nums, int n, int k) {
    int min_sum = *min_element(nums.begin(), nums.end());
    int max_sum = std::accumulate(nums.begin(), nums.end(), 0);
    int left = min_sum;
    int right = max_sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (count_subarrays_sums_below_target(nums, n, mid).first >= k)
            right = mid - 1;
        else
            left = mid + 1;
    }
    auto [count, sum] = count_subarrays_sums_below_target(nums, n, left);
    // There can be more subarrays with the same sum of left.
    return sum - left * (count - k);
}

int range_sum_binary_search_sliding_window(std::vector<int> &nums, int n, int left, int right) {
    int mod{1000000007};
    long long result = (sum_of_first_k(nums, n, right) - sum_of_first_k(nums, n, left - 1)) % mod;
    return (result + mod) % mod;
}


#endif //FUN_WITH_ALGOS_RANGE_SUM_OF_SORTED_SUBARRAYS_H
