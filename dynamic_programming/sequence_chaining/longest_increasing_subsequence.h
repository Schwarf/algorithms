//
// Created by andreas on 20.09.26.
//

#ifndef BEHAVIORAL_PATTERNS_LONGEST_INCREASING_SUBSEQUENCE_H
#define BEHAVIORAL_PATTERNS_LONGEST_INCREASING_SUBSEQUENCE_H

// Given an array of integers, return the longest strictly increasing subsequence.
// A subsequence does not need to consist of contiguous elements, but the relative order of the selected elements must
// remain the same as in the input array. If multiple longest increasing subsequences exist, return any one of them.
#include <algorithm>
#include <vector>

std::vector<int> longest_increasing_subsequence(const std::vector<int>& input)
{
    if (input.empty())
        return {};
    if (input.size() == 1)
        return input;

    int n = input.size();
    std::vector<int> sizes(n, 1);
    std::vector<int> predecessor_index(n, -1);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (input[i] > input[j] && sizes[j] + 1 > sizes[i])
            {
                sizes[i] = sizes[j] + 1;
                predecessor_index[i] = j;
            }
        }
    }

    int max_index = std::distance(sizes.begin(), std::max_element(sizes.begin(), sizes.end()));
    std::vector<int> result;
    while (max_index != -1)
    {
        result.push_back(input[max_index]);
        max_index = predecessor_index[max_index];
    }
    std::reverse(result.begin(), result.end());
    return result;
}


#endif // BEHAVIORAL_PATTERNS_LONGEST_INCREASING_SUBSEQUENCE_H
