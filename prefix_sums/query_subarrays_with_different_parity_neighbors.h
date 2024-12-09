//
// Created by andreas on 09.12.24.
//

#ifndef QUERY_SUBARRAYS_WITH_DIFFERENT_PARITY_NEIGHBORS_H
#define QUERY_SUBARRAYS_WITH_DIFFERENT_PARITY_NEIGHBORS_H
// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
// You are given an array of integer input and a 2D integer matrix queries, where for queries[i] = [fromi, toi]
// your task is to check that subarray input[fromi..toi] is special or not.
// Return an array of booleans answer such that answer[i] is true if input[fromi..toi] is special.
#include <vector>

std::vector<bool> get_query_results(std::vector<int>& input, std::vector<std::vector<int>>& queries) {
    int n = input.size();
    std::vector<int> arrays(n);
    int index{1};
    if(n==1)
        return std::vector<bool>(queries.size(), true);
    arrays[0] = index;
    for(int i{1}; i < n; ++i)
    {
        if(((input[i] + input[i-1]) & 1))
        {
            arrays[i] = index;
        }
        else
        {
            index++;
            arrays[i] = index;
        }
    }
    std::vector<bool> result;
    for(const auto & query : queries)
    {
        if(arrays[query[0]] == arrays[query[1]])
            result.push_back(true);
        else
            result.push_back(false);
    }
    return result;

}
#endif //QUERY_SUBARRAYS_WITH_DIFFERENT_PARITY_NEIGHBORS_H
