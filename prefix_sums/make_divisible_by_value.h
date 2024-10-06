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

// O(N^2)
int min_size_of_subarray_brute_force(std::vector<int> & input, int value)
{
    int n= input.size();
    long long sum = std::accumulate(input.begin(), input.end(), 0LL);
    if (value > sum)
        return -1;
    if(sum % value == 0)
        return 0;

    auto min_length{n};
    for (int start{}; start < n; ++start) {
        long long sub_sum{};
        for (int end = start; end < n; ++end) {
            sub_sum += input[end];  // Calculate the subarray sum

            // Check if removing this subarray makes the remaining sum divisible by p
            long long remaining_sum = (sum - sub_sum) % value;
            if (remaining_sum == 0) {
                min_length = std::min(min_length,  end - start + 1);  // Update the smallest subarray length
            }
        }
    }
    // If no valid subarray is found, return -1
    return min_length == n ? -1 : min_length;

}

#endif //PREFIX_SUMS_MAKE_DIVISIBLE_BY_VALUE_H
