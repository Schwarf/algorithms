//
// Created by andreas on 04.05.24.
//

#ifndef FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H
#define FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H

#include <vector>
#include <unordered_set>
#include <bitset>
// Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
// Return the positive integer k. If there is no such integer, return -1.
// Restrictions
// 1 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// nums[i] != 0

int largest_integer_with_its_negative(std::vector<int> &input) {
    std::sort(input.begin(), input.end());
    int left{};
    int right = input.size() - 1;
    while (left != right) {
        if (input[left] / input[right] > 0)
            return -1;
        if (std::abs(input[left]) == input[right])
            return input[right];
        else if (std::abs(input[left]) > input[right])
            left++;
        else
            right--;
    }
    return -1;
}

int largest_integer_with_its_negative_hashset(std::vector<int> &input) {
    int result{-1};
    std::unordered_set<int> seen;
    for (const auto element: input) {
        auto abs = std::abs(element);
        if (abs > result && seen.contains(-element))
            result = abs;
        seen.insert(element);
    }
    return result;
}

int largest_integer_with_its_negative_bitset(std::vector<int> &input) {
    int result{-1};
    std::bitset<2048> seen;
    for (const auto element: input) {
        auto abs = std::abs(element);
        if (abs > result && seen[-element + 1024])
            result = abs;
        seen[element + 1024] = true;
    }
    return result;
}


#endif //FUN_WITH_ALGOS_LARGEST_INTEGER_WITH_ITS_NEGATIVE_H

