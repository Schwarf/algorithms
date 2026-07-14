//
// Created by andreas on 14.07.26.
//

#ifndef ALGORITHMS_MAX_CONSECUTIVE_ONES_H
#define ALGORITHMS_MAX_CONSECUTIVE_ONES_H

#include <vector>

// Given a binary array nums and an integer k, find the length of the longest contiguous subarray that contains at most k zeros.
int max_consecutive_ones(const std::vector<int> & input, int k)
{
    int left = 0;
    int max_length = 0;
    int zero_count = 0;
    for (int right = 0; right < input.size(); ++right)
    {
        if(input[right] ==0)
            zero_count++;
        while (zero_count > k)
        {
            if(input[left] ==0)
                zero_count--;
            left++;
        }

        max_length = std::max(max_length, right-left+1);
    }
    return max_length;
}

#endif // ALGORITHMS_MAX_CONSECUTIVE_ONES_H
