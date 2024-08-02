//
// Created by andreas on 02.08.24.
//

#ifndef SLIDING_WINDOW_MINIMUM_SWAPS_TO_GROUP_ONES_H
#define SLIDING_WINDOW_MINIMUM_SWAPS_TO_GROUP_ONES_H

#include <vector>

// Given a binary array. Find the minimum number of swaps to cluster all 1’s together.
// The 1’s can be clustered across the array boundaries (like a circular array)

int swaps_needed_brute_force(const std::vector<int> &input){
    int n = input.size();
    int total_ones = 0;
    for (int num : input) {
        if (num == 1) {
            total_ones++;
        }
    }

    if (total_ones == 0 || total_ones == n) return 0; // No need to swap if no 1's or all are 1's

    int number_of_swaps = n; // Initialize with the maximum possible swaps, which cannot exceed the array size.

    // Check every possible block of 'total_ones' length
    for (int start = 0; start < n; start++) {
        int onesCount = 0;

        // Calculate the number of 1's in the current block of length 'total_ones'
        for (int i = 0; i < total_ones; i++) {
            if (input[(start + i) % n] == 1) {
                onesCount++;
            }
        }

        int currentSwaps = total_ones - onesCount; // The number of 0's in the block that need to be swapped with 1's outside the block
        number_of_swaps = std::min(number_of_swaps, currentSwaps);
    }

    return number_of_swaps;
};



int sliding_window_analysis(const std::vector<int> &input, int val);

int swaps_needed_sliding_window(const std::vector<int> &input) {
    return std::min(sliding_window_analysis(input, 1), sliding_window_analysis(input, 0));
}

int sliding_window_analysis(const std::vector<int> &input, int val) {
    int total{};
    int size = input.size();
    for (int i{}; i < size; ++i) {
        if (input[i] == val)
            total++;
    }
    if (total == size || total == 0)
        return 0;

    int end_index{};
    int start_index{};
    int current{};

    // build sliding window-size
    while (end_index < total) {
        if (input[end_index++] == val)
            current++;
    }
    int max_value_in_window{current};
    while (end_index < size) {
        if (input[end_index++] == val)
            current++;
        if (input[start_index++] == val)
            current--;
        max_value_in_window = std::max(max_value_in_window, current);
    }
    // For the 1's case we need to count the 0's and vice versa. So we return total - count
    return total - max_value_in_window;
}

#endif //SLIDING_WINDOW_MINIMUM_SWAPS_TO_GROUP_ONES_H
