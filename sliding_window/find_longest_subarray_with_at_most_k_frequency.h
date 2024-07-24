//
// Created by andreas on 28.03.24.
//

#ifndef FIND_LONGEST_SUBARRAY_WITH_AT_MOST_K_FREQUENCY_H
#define FIND_LONGEST_SUBARRAY_WITH_AT_MOST_K_FREQUENCY_H
// You are given an integer array nums and an integer k.
// The frequency of an element x is the number of times it occurs in an array.
// An array is called good if the frequency of each element in this array is less than or equal to k.
// Return the length of the longest good subarray of nums.
// A subarray is a contiguous non-empty sequence of elements within an array.
#include <vector>
#include <unordered_map>

int max_subarray_length(const std::vector<int> &input, int max_frequency) {
    int result{};
    int left{-1};
    std::unordered_map<int, int> frequency;
    for (int right{}; right < input.size(); right++) {
        frequency[input[right]]++;
        while (frequency[input[right]] > max_frequency) {
            left++;
            frequency[input[left]]--;
        }
        result = std::max(result, right - left);
    }
    return result;

}

#endif //FIND_LONGEST_SUBARRAY_WITH_AT_MOST_K_FREQUENCY_H
