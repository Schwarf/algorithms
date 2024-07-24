//
// Created by andreas on 04.12.22.
//
#include <vector>
#include <set>
#include <algorithm>

#ifndef THREE_SUM_H
#define THREE_SUM_H

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k,
// and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
std::vector<std::vector<int>> three_sum(std::vector<int> &nums) {
    auto size = nums.size();
    auto result = std::set<std::vector<int>>{};
    auto vector_result = std::vector<std::vector<int>>{};
    if (size < 3)
        return vector_result;
    std::sort(nums.begin(), nums.end());

    for (int i{}; i < size; ++i) {
        int start = i + 1;
        int end = size - 1;
        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum == 0) {
                auto current = std::vector<int>{nums[i], nums[start], nums[end]};
                result.insert(current);
                start++;
                end--;
            } else
                sum > 0 ? end-- : start++;
        }
    }

    for (auto &element: result) {
        vector_result.emplace_back(element);
    }
    return vector_result;

}


#endif //THREE_SUM_H
