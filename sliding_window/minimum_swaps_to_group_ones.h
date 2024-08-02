//
// Created by andreas on 02.08.24.
//

#ifndef SLIDING_WINDOW_MINIMUM_SWAPS_TO_GROUP_ONES_H
#define SLIDING_WINDOW_MINIMUM_SWAPS_TO_GROUP_ONES_H

#include <vector>

// Given a binary array. Find the minimum number of swaps to cluster all 1’s together.
// The 1’s can be clustered across the array boundaries (like a circular array)
int sliding_window_analysis(const std::vector<int> &input, int val);

int swaps_needed(const std::vector<int> &input) {
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
