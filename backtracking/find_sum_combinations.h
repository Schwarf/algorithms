//
// Created by andreas on 22.06.26.
//

#ifndef ALGORITHMS_FIND_ALL_COMBINATIONS_H
#define ALGORITHMS_FIND_ALL_COMBINATIONS_H
#include <vector>
// Given a vector of distinct positive integers candidates and a positive integer target, return all unique combinations
// of values from candidates whose sum equals target.
// You may use each candidate value any number of times in a combination.
// Two combinations are considered different when at least one candidate appears a different number of times.
// The order of values within a combination does not matter, so {2, 2, 3} and {2, 3, 2} represent the same
// combination and must appear only once.
// Return the combinations in any order.
void backtrack(int index, int target, std::vector<int>& current, std::vector<std::vector<int>>& result,
               const std::vector<int>& input)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        result.push_back(current);
        return;
    }

    for (int i{index}; i < input.size(); ++i)
    {
        current.push_back(input[i]);
        backtrack(i, target - input[i], current, result, input);
        current.pop_back();
    }
}


std::vector<std::vector<int>> find_sum_combinations(std::vector<int>& candidates, int target)
{
    std::vector<int> current;
    std::vector<std::vector<int>> result;
    backtrack(0, target, current, result, candidates);
    return result;
}
#endif // ALGORITHMS_FIND_ALL_COMBINATIONS_H
