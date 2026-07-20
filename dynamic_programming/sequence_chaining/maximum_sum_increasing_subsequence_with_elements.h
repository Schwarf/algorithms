//
// Created by andreas on 20.07.26.
//

#ifndef ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H
#define ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H

// Given a non-empty array of integers, return:
// The maximum sum obtainable from a strictly increasing subsequence.
// One strictly increasing subsequence that produces that sum.

#include <vector>

std::vector<std::vector<int>> longest_increasing_subsequence(const std::vector<int> & input)
{
    int n = input.size();
    if (n ==0)
        return {{0}, {}};

    std::vector<int> dp = input;
    std::vector<std::vector<int>> elements(n);
    for (int i{}; i < n; ++i)
    {
        elements[i].push_back(input[i]);
    }

    int sum = input[0];
    int index = 0;
    for (int i=1; i < n; ++i)
    {
        for (int j=0; j < i; ++j)
        {
            if (input[i] > input[j] && (dp[j] + input[i] > dp[i]))
            {
                dp[i] = dp[j] + input[i];
                elements[i] = elements[j];
                elements[i].push_back(input[i]);
            }
        }
        if (dp[i] > sum)
        {
            sum = dp[i];
            index = i;
        }
    }
    return {{sum}, elements[index]};
}


#endif // ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H
