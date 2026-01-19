//
// Created by andreas on 19.01.26.
//

#ifndef ALGORITHMS_FOUR_SUM_H
#define ALGORITHMS_FOUR_SUM_H
// Given a non-empty array of distinct integers, write a function that finds all quadruples that
// in the array that add up to a provided target-sum.

#include <unordered_map>
#include <vector>

std::vector<std::vector<int>> four_sum(std::vector<int>& input, int target)
{
    std::unordered_map<int, std::vector<std::pair<int, int>>> map;
    std::vector<std::vector<int>> result;
    int n = input.size();
    for (int i{1}; i < n-1; ++i )
    {
        for (int j{i+1}; j < n; ++j)
        {
            auto current_sum = input[i] + input[j];
            auto diff = target - current_sum;
            if (map.contains(diff))
            {
                for (const auto & [first, second] : map[diff])
                {
                    result.push_back({first, second, input[i], input[j]});
                }
            }
        }
        for (int k{}; k < i; ++k)
        {
            const int sum = input[k] + input[i];
            map[sum].push_back({input[k], input[i]});
        }
    }
    return result;
}
#endif //ALGORITHMS_FOUR_SUM_H