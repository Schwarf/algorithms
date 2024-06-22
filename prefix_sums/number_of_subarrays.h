//
// Created by andreas on 22.06.24.
//

#ifndef PREFIX_SUMS_NUMBER_OF_SUBARRAYS_H
#define PREFIX_SUMS_NUMBER_OF_SUBARRAYS_H
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.
#include <vector>
#include <unordered_map>
int number_of_sub_arrays(std::vector<int> & input, int number_of_required_odd_elements)
{
    int count_odd{};
    int count_sub_arrays{};
    std::unordered_map<int, int> prefix_sum{};
    // This base case represents a sub-array with 0 odd-numbers, we have at least one of them.
    prefix_sum[0] = 1;
    for(int i{}; i < input.size(); ++i){
        count_odd += (input[i] & 1);
        if(prefix_sum.find(count_odd - number_of_required_odd_elements) != prefix_sum.end())
        {
            count_sub_arrays += prefix_sum[count_odd - number_of_required_odd_elements];
        }
        prefix_sum[count_odd]++;
    }
    return count_sub_arrays;
}

#endif //PREFIX_SUMS_NUMBER_OF_SUBARRAYS_H
