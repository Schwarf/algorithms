//
// Created by andreas on 14.03.24.
//

#ifndef COUNT_SUBARRAYS_WITH_TARGET_H
#define COUNT_SUBARRAYS_WITH_TARGET_H
// Given a binary array input and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.
#include <vector>

int count_subarrays_with_target(const std::vector<int> &input, int target) {
    int left{};
    int prefix_zeros{};
    int current_sum{};
    int count{};
    // Use two pointer
    for (int right = 0; right < input.size(); ++right) {
        current_sum += input[right];

        // Sliding window
        while (left < right && (input[left] == 0 || current_sum > target)) {
            // Count prefix zeros
            if (input[left] == 1) {
                prefix_zeros = 0;
            } else {
                prefix_zeros += 1;
            }

            current_sum -= input[left];
            left += 1;
        }

        // Count subarrays when window sum matches the goal and add number of prefix_zeros
        if (current_sum == target) {
            count += 1 + prefix_zeros;
        }
    }
    return count;
}

#endif //COUNT_SUBARRAYS_WITH_TARGET_H
