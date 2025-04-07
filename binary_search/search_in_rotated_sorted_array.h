//
// Created by andreas on 07.04.25.
//

#ifndef SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define SEARCH_IN_ROTATED_SORTED_ARRAY_H
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
// or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.
#include <vector>

int search(const std::vector<int>& input, int target)
{
    int size = input.size();
    int left{};
    int right{size - 1};
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        // case1: target found
        if (input[mid] == target)
        {
            return mid;
        }
        // case2: subarray on mid's left is sorted
        else if (input[mid] >= target)
        {
            if (target >= input[left] && target < input[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            // case3: subarray on mid's right is sorted
            if (target <= input[right] && target > input[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

#endif //SEARCH_IN_ROTATED_SORTED_ARRAY_H
