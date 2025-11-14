//
// Created by andreas on 18.10.25.
//

#ifndef ALGORITHMS_MAX_NUMBER_OF_DIFF_ELEMENTS_H
#define ALGORITHMS_MAX_NUMBER_OF_DIFF_ELEMENTS_H
// You are given an integer array nums and an integer k.
//
// You are allowed to perform the following operation on each element of the array at most once:
//
//     Add an integer in the range [-k, k] to the element.
//
// Return the maximum possible number of distinct elements in nums after performing the operations.
#include <vector>
#include <algorithm>
#include <limits>

int max_distinct_elements(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int cnt = 0;
    int prev = std::numeric_limits<int>::min();
    for (int num : nums) {
        // greedily make the current element as small as possible to generate as many different elements as possible
        int curr = std::min(std::max(num - k, prev + 1), num + k);
        if (curr > prev) {
            cnt++;
            prev = curr;
        }
    }
    return cnt;
}
#endif //ALGORITHMS_MAX_NUMBER_OF_DIFF_ELEMENTS_H