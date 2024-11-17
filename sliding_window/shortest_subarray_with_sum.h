//
// Created by andreas on 17.11.24.
//

#ifndef SMALLEST_SUBARRAY_WITH_SUM_H
#define SMALLEST_SUBARRAY_WITH_SUM_H
#include <algorithm>
#include <vector>
#include <queue>
// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
// whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
int shortest_subarray_with_sum(std::vector<int>& input, int target_sum)
{
    int n = input.size();
    int answer = n + 1;
    int left{};
    int sum{};
    for (int i{}; i < n; ++i)
    {
        sum += input[i];
        while (sum >= target_sum)
        {
            answer = std::min(answer, i - left + 1);
            sum -= input[left++];
        }
    }
    return answer != n + 1 ? answer : 0;
}

// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums
// with a sum of at least k. If there is no such subarray, return -1.
// Now including negative numbers.
int shortest_subarray_with_sum_with_negatives(std::vector<int>& input, int target_sum)
{
    int n = input.size();
    int shortest_subarray_size = INT_MAX;
    long long sum{};
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>>
        prefix_sum_heap;
    for (int i{}; i < n; ++i)
    {
        sum += input[i];
        if (sum >= target_sum)
        {
            shortest_subarray_size = std::min(shortest_subarray_size, i + 1);
        }
        // Remove subarrays from heap that can form a valid subarray and update shortest_subarray_size
        while (!prefix_sum_heap.empty() && sum - prefix_sum_heap.top().first >= target_sum)
        {
            shortest_subarray_size = std::min(shortest_subarray_size, i - prefix_sum_heap.top().second);
            prefix_sum_heap.pop();
        }
        prefix_sum_heap.emplace(sum, i);
    }
    return shortest_subarray_size != n + 1 ? shortest_subarray_size : -1;
}


#endif //SMALLEST_SUBARRAY_WITH_SUM_H
