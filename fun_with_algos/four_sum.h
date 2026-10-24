//
// Created by andreas on 19.01.26.
//

#ifndef ALGORITHMS_FOUR_SUM_H
#define ALGORITHMS_FOUR_SUM_H
// Given a non-empty array of distinct integers, write a function that finds all quadruples that
// in the array that add up to a provided target-sum.

#include <unordered_map>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> four_sum(std::vector<int>& input, int target)
{
    std::unordered_map<int, std::vector<std::pair<int, int>>> map;
    std::vector<std::vector<int>> result;
    int n = input.size();
    for (int i{1}; i < n - 1; ++i)
    {
        for (int j{i + 1}; j < n; ++j)
        {
            auto current_sum = input[i] + input[j];
            auto diff = target - current_sum;
            if (map.contains(diff))
            {
                for (const auto& [first, second] : map[diff])
                {
                    result.push_back({first, second, input[i], input[j]});
                }
            }
        }
        for (int k{}; k < i; ++k)
        {
            const int sum = input[k] + input[i];
            map[sum].push_back({input[k], input[i]});
        }
    }
    return result;
}

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
// such that:
//
//     0 <= a, b, c, d < n
//     a, b, c, and d are distinct.
//     nums[a] + nums[b] + nums[c] + nums[d] == target
//
// You may return the answer in any order.

std::vector<std::vector<int>> four_sum_unique(std::vector<int>& input, int target)
{
    int n = input.size();
    std::sort(input.begin(), input.end());
    std::vector<std::vector<int>> result;
    for (int i{}; i < n - 3; ++i)
    {
        if (i > 0 && input[i] == input[i - 1])
            continue;
        for (int j{i + 1}; j < n - 2; ++j)
        {
            if (j > i + 1 && input[j] == input[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                long long sum = static_cast<long long>(input[i]) + static_cast<long long>(input[j]) +
                    static_cast<long long>(input[left]) + static_cast<long long>(input[right]);
                if (sum < target)
                    ++left;
                else if (sum > target)
                    --right;
                else
                {
                    result.push_back({input[i], input[j], input[left], input[right]});
                    ++left;
                    --right;
                    while (left < right && input[left] == input[left-1])
                        ++left;
                    while (left < right && input[right] == input[right+1])
                        --right;
                }
            }
        }
    }
    return result;
}

#endif // ALGORITHMS_FOUR_SUM_H
