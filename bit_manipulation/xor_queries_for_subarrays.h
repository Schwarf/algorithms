//
// Created by andreas on 15.09.24.
//

#ifndef BIT_MANIPULATION_XOR_QUERIES_FOR_SUBARRAYS_H
#define BIT_MANIPULATION_XOR_QUERIES_FOR_SUBARRAYS_H
// You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].
// For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).
// Return an array answer where answer[i] is the answer to the ith query.
#include <vector>

std::vector<int> xor_queries(std::vector<int> & input_array, std::vector<std::vector<int>> & queries)
{
    int n = input_array.size();
    std::vector<int> prefix_xor(n+1);
    prefix_xor[0] = input_array[0];
    for(int i{0}; i < n; ++i)
    {
        prefix_xor[i+1] = prefix_xor[i] ^ input_array[i];
    }
    std::vector<int> result(queries.size());
    for(int i{}; i < queries.size(); ++i)
    {
        result[i] = prefix_xor[queries[i][1]+1] ^ prefix_xor[queries[i][0]];
    }
    return result;

}

#endif //BIT_MANIPULATION_XOR_QUERIES_FOR_SUBARRAYS_H
