//
// Created by andreas on 06.10.24.
//

#ifndef PREFIX_SUMS_MAKE_DIVISIBLE_BY_VALUE_H
#define PREFIX_SUMS_MAKE_DIVISIBLE_BY_VALUE_H
// Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of
// the remaining elements is divisible by p. It is not allowed to remove the whole array.
// Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
// A subarray is defined as a contiguous block of elements in the array.
#include <vector>
#include <numeric>
#include <unordered_map>

// O(N^2)
int min_size_of_subarray_brute_force(std::vector<int> &input, int value) {
    int n = input.size();
    long long sum = std::accumulate(input.begin(), input.end(), 0LL);
    if (value > sum)
        return -1;
    if (sum % value == 0)
        return 0;

    auto min_length{n};
    for (int start{}; start < n; ++start) {
        long long sub_sum{};
        for (int end = start; end < n; ++end) {
            sub_sum += input[end];  // Calculate the subarray sum

                // Check if removing this subarray makes the remaining sum divisible by p
            long long remaining_sum = (sum - sub_sum) % value;
            if (remaining_sum == 0) {
                min_length = std::min(min_length, end - start + 1);  // Update the smallest subarray length
            }
        }
    }
    // If no valid subarray is found, return -1
    return min_length == n ? -1 : min_length;
}

int min_size_of_subarray(std::vector<int> &input, int value) {
    int n = input.size();
    int totalSum{};

    // Step 1: Calculate total sum and target remainder
    for (auto element: input) {
        totalSum = (totalSum + element) % value;
    }

    int target = totalSum % value;
    if (target == 0) return 0;  // The array is already divisible by p

    // Step 2: Use a hash map to track prefix sum mod p
    std::unordered_map<int, int> modulo_map;
    modulo_map[0] = -1;  // To handle the case where the whole prefix is the answer
    int current_sum{};
    int min_length{n};

    // Step 3: Iterate over the array
    for (int i{}; i < n; ++i) {
        current_sum = (current_sum + input[i]) % value;

        // Calculate what we need to remove
        int needed = (current_sum - target + value) % value;

        // If we have seen the needed remainder, we can consider this subarray
        if (modulo_map.find(needed) != modulo_map.end()) {
            min_length = std::min(min_length, i - modulo_map[needed]);
        }
        // Store the current remainder and index
        modulo_map[current_sum] = i;
    }
    // Step 4: Return result
    return min_length == n ? -1 : min_length;
}

#endif //PREFIX_SUMS_MAKE_DIVISIBLE_BY_VALUE_H
