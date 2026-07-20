//
// Created by andreas on 20.07.26.
//

#ifndef ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H
#define ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H

// Given a non-empty array of integers, return:
// The maximum sum obtainable from a strictly increasing subsequence.
// One strictly increasing subsequence that produces that sum.
std::vector<std::vector<int>> longest_increasing_subsequence(const std::vector<int> & input)
{
    int n = input.size();
    if (n ==0)
        return {{0}, {}};
}

#endif // ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H
