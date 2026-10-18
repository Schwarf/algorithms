//
// Created by andreas on 04.12.22.
//
#include <algorithm>
#include <set>
#include <vector>

#ifndef THREE_SUM_H
#define THREE_SUM_H

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k,
// and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
std::vector<std::vector<int>> three_sum(std::vector<int>& nums)
{
    auto size = nums.size();
    auto result = std::set<std::vector<int>>{};
    auto vector_result = std::vector<std::vector<int>>{};
    if (size < 3)
        return vector_result;
    std::sort(nums.begin(), nums.end());

    for (int i{}; i < size; ++i)
    {
        int start = i + 1;
        int end = size - 1;
        while (start < end)
        {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum == 0)
            {
                auto current = std::vector<int>{nums[i], nums[start], nums[end]};
                result.insert(current);
                start++;
                end--;
            }
            else
                sum > 0 ? end-- : start++;
        }
    }

    for (auto& element : result)
    {
        vector_result.emplace_back(element);
    }
    return vector_result;
}

std::vector<std::vector<int>> three_sum_optimal(std::vector<int>& nums)
{
    auto size = nums.size();
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i{}; i < size-2; ++i)
    {
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        int left = i+1;
        int right = size-1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left-1])
                    ++left;
                while (left < right && nums[right] == nums[right+1])
                    --right;
            }
        }

    }
    return result;
}


#endif // THREE_SUM_H
