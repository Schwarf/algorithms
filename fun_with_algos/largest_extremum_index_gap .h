//
// Created by andreas on 13.10.24.
//

#ifndef FUN_WITH_ALGOS_LARGEST_EXTREMUM_INDEX_GAP_H
#define FUN_WITH_ALGOS_LARGEST_EXTREMUM_INDEX_GAP_H
// LC-962
// A min-max-index-gap in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a gap is j - i.
// Given an integer array input, return the maximum min-max-index-gap in input.

#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

template<typename T, typename Comparator = std::less<T>>
int largest_extremum_index_gap_sort(std::vector<T> &input, Comparator comparator = Comparator()) {
    int n = input.size();
    if (n < 2)
        return 0;
    std::vector<int> indices(n);
    std::iota(indices.begin(), indices.end(), 0);
    // Sort indices based on corresponding values in input.
    // Indices are reordered so that input-elements are arranged in increasing order
    std::sort(indices.begin(), indices.end(), [&](int i, int j) {
        return comparator(input[i], input[j]) || (input[i] == input[j] && i < j);
    });

    int min_index_so_far = n;
    int max_gap{};
    for (int i{}; i < n; ++i) {
        max_gap = std::max(max_gap, indices[i] - min_index_so_far);
        min_index_so_far = std::min(min_index_so_far, indices[i]);
    }
    return max_gap;
}

template<typename T, typename Comparator = std::less<T>>
int largest_extremum_index_gap_two_pointers(std::vector<T> &input, Comparator comparator = Comparator()) {
    int n = input.size();
    if (n < 2)
        return 0;
    std::vector<T> right_extremums(n);
    right_extremums[n - 1] = input[n - 1];
    for (int i{n - 2}; i >= 0; i--) {
        if constexpr (std::is_same_v<Comparator, std::less<T>>)
            right_extremums[i] = std::max(right_extremums[i + 1], input[i]);
        else if ((std::is_same_v<Comparator, std::greater<T>>))
            right_extremums[i] = std::min(right_extremums[i + 1], input[i]);
    }
    int left{};
    int right{};
    int max_gap{};
    while (right < n) {
        // Note that std::less and std::greater are NOT symmetric. The call
        // comparator(right_extremums[right], input[left]) is the correct one.
        while (left < right && comparator(right_extremums[right], input[left])) {
            left++;
        }
        max_gap = std::max(max_gap, right - left);
        right++;
    }

    return max_gap;
}

template<typename T>
int largest_min_max_index_gap_stack(std::vector<T> &input) {
    int n = input.size();
    if (n < 2)
        return 0;
    std::stack<int> index_stack;
    // Fill stack with indices in increasing order of values in input
    for (int i{}; i < n; ++i) {
        if (index_stack.empty() || input[index_stack.top()] > input[i]) {
            index_stack.push(i);
        }
    }
    int max_gap{};
    for (int j = n - 1; j > -1; j--) {
        while (!index_stack.empty() && input[index_stack.top()] <= input[j]) {
            max_gap = std::max(max_gap, j - index_stack.top());
            index_stack.pop();
        }
    }
    return max_gap;
}


#endif //FUN_WITH_ALGOS_LARGEST_EXTREMUM_INDEX_GAP_H
