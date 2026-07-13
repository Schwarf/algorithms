//
// Created by andreas on 11.07.26.
//

#ifndef ALGORITHMS_MAX_SUM_OF_INCREASING_SUBSEQUENCE_H
#define ALGORITHMS_MAX_SUM_OF_INCREASING_SUBSEQUENCE_H
// Given an array of integers, find the strictly increasing subsequence with the maximum possible sum.
#include <algorithm>
#include <vector>

int maximum_sum_increasing_subsequence(const std::vector<int>& input)
{
    if (input.empty())
        return 0;

    int n = input.size();
    std::vector<int> dp = input;
    for (int i{1}; i < n; ++i)
    {
        for (int j{0}; j < i; ++j)
        {
            if (input[i] > input[j])
                dp[i] = std::max(dp[i], dp[j] + input[i]);
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}

#endif // ALGORITHMS_MAX_SUM_OF_INCREASING_SUBSEQUENCE_H
