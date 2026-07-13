//
// Created by andreas on 23.06.26.
//

#ifndef ALGORITHMS_SUBSETS_WITH_DUPLICATES_H
#define ALGORITHMS_SUBSETS_WITH_DUPLICATES_H
// Given an integer array nums, which may contain duplicate values, return all distinct subsets of nums
#include <vector>

void backtrack(int index, const std::vector<int>& nums, std::vector<int>& current,
               std::vector<std::vector<int>>& result)
{
    result.push_back(current);

    for (int i = index; i < nums.size(); ++i)
    {
        // For elements beyond the start-index we check if they are duplicates
        if (i > index && nums[i] == nums[i - 1])
            continue;
        current.push_back(nums[i]);
        backtrack(i + 1, nums, current, result);
        current.pop_back();
    }
}

std::vector<std::vector<int>> subsets_with_duplicates(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    backtrack(0, nums, current, result);
    return result;
}


#endif // ALGORITHMS_SUBSETS_WITH_DUPLICATES_H
