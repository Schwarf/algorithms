//
// Created by andreas on 21.11.24.
//

#ifndef MAX_SUM_OF_DISTINCT_SUBARRAYS_WITH_GIVEN_LENGTH_H
#define MAX_SUM_OF_DISTINCT_SUBARRAYS_WITH_GIVEN_LENGTH_H

// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
//     The length of the subarray is k, and
//     All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
// A subarray is a contiguous non-empty sequence of elements within an array.
#include <vector>
#include <unordered_map>
long long max_subarray_sum(std::vector<int>& input, int subarray_length) {
    long long result{};
    long long current_sum{};
    int begin{};
    int end{};

    std::unordered_map<int, int> value_to_index_map;

    while (end < input.size()) {
        int current_value = input[end];
        int last_occurrence =  (value_to_index_map.count(current_value) ? value_to_index_map[current_value] : -1);

        // if current window already has number or if window is too big,
        // adjust window
        while (begin <= last_occurrence || end - begin + 1 > subarray_length) {
            current_sum -= input[begin];
            begin++;
        }
        value_to_index_map[current_value] = end;
        current_sum += input[end];
        if (end - begin + 1 == subarray_length) {
            result = std::max(result, current_sum);
        }
        end++;
    }
    return result;
}
#endif //MAX_SUM_OF_DISTINCT_SUBARRAYS_WITH_GIVEN_LENGTH_H
