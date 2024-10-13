//
// Created by andreas on 13.10.24.
//

#ifndef FUN_WITH_ALGOS_LARGEST_MIN_MAX_INDEX_GAP_H
#define FUN_WITH_ALGOS_LARGEST_MIN_MAX_INDEX_GAP_H
// LC-962
// A min-max-index-gap in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a gap is j - i.
// Given an integer array input, return the maximum min-max-index-gap in input.

#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

template<typename T>
T largest_min_max_index_gap_sort(std::vector<T> &input) {
    int n = input.size();
    if (n < 2)
        return 0;
    std::vector<int> indices(n);
    std::iota(indices.begin(), indices.end(), 0);
    // Sort indices based on corresponding values in input.
    // Indices are reordered so that input-elements are arranged in increasing order
    std::sort(indices.begin(), indices.end(), [&](int i, int j) {
        return input[i] != input[j] ? input[i] < input[j] : i < j;
    });

    int min_index_so_far = n;
    int max_gap = 0;
    for (int i{}; i < n; ++i) {
        max_gap = std::max(max_gap, indices[i] - min_index_so_far);
        min_index_so_far = std::min(min_index_so_far, indices[i]);
    }
    return max_gap;
}

template<typename T>
T largest_min_max_index_gap_two_pointers(std::vector<T> &input) {
    int n = input.size();
    if (n < 2)
        return 0;
    std::vector<T> right_maximums(n);
    right_maximums[n-1] = input[n-1];
    for(int i{n-2}; i>=0; i--)
    {
        right_maximums[i] = std::max(right_maximums[i+1], input[i]);
    }
    int left{};
    int right{};
    int max_gap{};
    while(right < n)
    {
        while(left < right && input[left] > right_maximums[right])
        {
            left++;
        }
        max_gap = std::max(max_gap, right -left);
        right++;
    }

    return max_gap;
}


#endif //FUN_WITH_ALGOS_LARGEST_MIN_MAX_INDEX_GAP_H
