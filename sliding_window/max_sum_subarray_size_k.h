//
// Created by andreas on 14.07.26.
//

#ifndef ALGORITHMS_MAX_SUM_SUBARRAY_SIZE_K_H
#define ALGORITHMS_MAX_SUM_SUBARRAY_SIZE_K_H

#include <vector>
#include <algorithm>
#include <numeric>

// Given an array of integers input and an integer k, find the maximum sum of any contiguous subarray of exactly k elements.
int max_sum_subarray_size_k(const std::vector<int> & input, int k)
{
    int n = input.size();
    if( n < k || k == 0)
        return 0;
    if(k==1)
        return *std::max_element(input.begin(), input.end());

    int left{};

    int current_sum = std::accumulate(input.begin(), input.begin()+k);
    int max_sum = current_sum;
    for(int right{k}; right < n; ++right)
    {
        current_sum += -input[left]+input[right];
        max_sum = std::max(max_sum, current_sum);
        left++;
    }
    return max_sum;
}

#endif // ALGORITHMS_MAX_SUM_SUBARRAY_SIZE_K_H
