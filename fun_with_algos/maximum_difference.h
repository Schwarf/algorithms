//
// Created by andreas on 16.06.25.
//

#ifndef MAXIMUM_DIFFERENCE_H
#define MAXIMUM_DIFFERENCE_H
// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]),
// such that 0 <= i < j < n and nums[i] < nums[j].
#include <vector>

int maximum_difference(std::vector<int>& input)
{
    int result{-1};
    int prefix_minimum = input[0];
    for (int i{1}; i < input.size(); ++i)
    {
        if (input[i] > prefix_minimum)
            result = std::max(result, input[i] - prefix_minimum);
        else
            prefix_minimum = input[i];
    }
#endif //MAXIMUM_DIFFERENCE_H
