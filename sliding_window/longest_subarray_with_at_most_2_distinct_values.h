//
// Created by andreas on 16.07.26.
//

#ifndef ALGORITHMS_LONGEST_SUBARRAY_WITH_AT_MOST_2_DISTINCT_VALUES_H
#define ALGORITHMS_LONGEST_SUBARRAY_WITH_AT_MOST_2_DISTINCT_VALUES_H

#include <algorithm>
#include <unordered_map>
#include <vector>

// Given an integer array values, return the length of the longest contiguous subarray
// that contains at most two distinct values.


int longest_subarray_with_at_most_2_distinct_values(const std::vector<int>& input)
{
    std::unordered_map<int, int> value_counts;

    int left = 0;
    int longest = 0;

    for (int right = 0; right < input.size(); ++right)
    {
        ++value_counts[input[right]];
        while (value_counts.size() > 2)
        {
            --value_counts[input[left]];
            if (value_counts[input[left]] == 0)
                value_counts.erase(input[left]);
            ++left;
        }
        longest = std::max(longest, right - left + 1);
    }
    return longest;
}


#endif // ALGORITHMS_LONGEST_SUBARRAY_WITH_AT_MOST_2_DISTINCT_VALUES_H
