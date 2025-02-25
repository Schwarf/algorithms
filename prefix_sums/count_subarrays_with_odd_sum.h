//
// Created by andreas on 25.02.25.
//

#ifndef COUNT_SUBARRAYS_WITH_ODD_SUM_H
#define COUNT_SUBARRAYS_WITH_ODD_SUM_H
// Given an array of integers arr, return the number of subarrays with an odd sum.
// Since the answer can be very large, return it modulo 109 + 7.
#include <vector>
int count_odd_subarray_sums_brute_force(const std::vector<int>& input)
{
    constexpr int mod{1000000007};
    int count{};
    for(int i{}; i < input.size(); i++)
    {
        int sum{};
        for(int j{i}; j < input.size(); j++)
        {
          sum += input[j];
          if(sum & 1)
            count++;
        }
        count %= mod;
    }
    return count;
}


#endif //COUNT_SUBARRAYS_WITH_ODD_SUM_H
