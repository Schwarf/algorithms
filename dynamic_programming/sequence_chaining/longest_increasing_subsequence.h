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

void build_subsequences(int index, const std::vector<int>& input,
                        const std::vector<std::vector<int>>& predecessor_indices,
                        std::vector<int> & current,
                        std::vector<std::vector<int>>& result)
{
    current.push_back(input[index]);
    if (predecessor_indices[index].empty())
    {
        auto sequence = current;
        std::reverse(sequence.begin(), sequence.end());
        result.push_back(sequence);
    }
    else
    {
        for (int predecessor_index : predecessor_indices[index])
        {
            build_subsequences(predecessor_index, input, predecessor_indices, current, result);
        }
    }
    current.pop_back();
}

// multiple results
std::vector<std::vector<int>> multiple_longest_increasing_subsequence(const std::vector<int>& input)
{
    if (input.empty())
        return {};
    if (input.size() == 1)
        return {input};

    int n = input.size();
    std::vector<int> sizes(n, 1);
    std::vector<std::vector<int>> predecessor_indices(n);
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (input[i] > input[j])
            {
                if (sizes[j] + 1 > sizes[i])
                {
                    sizes[i] = sizes[j] + 1;
                    predecessor_indices[i].clear();
                    predecessor_indices[i].push_back(j);
                }
                else if ((sizes[j] + 1) == sizes[i])
                    predecessor_indices[i].push_back(j);
            }
        }
    }
    int max_size = *std::max_element(sizes.begin(), sizes.end());
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    for (int i = 0; i < n; ++i)
    {
        if (sizes[i] == max_size)
            build_subsequences(i, input, predecessor_indices, current, result);
    }
    return result;
}


#endif // BEHAVIORAL_PATTERNS_LONGEST_INCREASING_SUBSEQUENCE_H
