//
// Created by andreas on 01.03.25.
//

#ifndef FIND_KSUM_IN_ARRAY_H
#define FIND_KSUM_IN_ARRAY_H
// You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.
// We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).
// Return the K-Sum of the array.
// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// Note that the empty subsequence is considered to have a sum of 0.
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

long long find_ksum_in_array(std::vector<int>& input, int k)
{
    int n = input.size();
    long long max{};
    //subtract stores the sum which needs to be subtracted from the maximum sum
    std::vector<long long> subtract;
    //find the maxsum and update nums so that all elements are positive
    for (int i = 0; i < n; i++)
    {
        if (input[i] >= 0)
        {
            max += input[i];
        }
        else
        {
            input[i] = std::abs(input[i]);
        }
    }
    //sorting nums as per absolute values
    std::sort(input.begin(), input.end());

    //Initialize priority queue (minheap) to store current least value which needs to be
    //subtracted from maxsum and the index of nums we are currently at.
    using input_index = int;
    std::priority_queue<std::pair<long long, input_index>, std::vector<std::pair<long long, input_index>>, std::greater<std::pair<
                            long long, input_index>>> pq;
    //start from index 0 with minimum value as nums[0]
    pq.push({input[0], 0});
    while (!pq.empty() && subtract.size() < k - 1)
    {
        std::pair<long long, input_index> current = pq.top();
        pq.pop();
        long long to_subtract = current.first;
        input_index index = current.second;
        //push this value to subtract array
        subtract.push_back(to_subtract);
        //if we are not at last idx then we can add further values to pq
        if (index < n - 1)
        {
            pq.push({to_subtract + input[index + 1], index + 1});
            pq.push({input[index + 1] + (to_subtract - input[index]), index + 1});
        }
    }

    //ans stores all the largest sum in decreasing order
    std::vector<long long> ans;
    ans.push_back(max);
    for (long long subt : subtract)
    {
        ans.push_back(max - subt);
    }
    //return Kth largest sum
    return ans[k - 1];
}


#endif //FIND_KSUM_IN_ARRAY_H
