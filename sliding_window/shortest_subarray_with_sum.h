    //
// Created by andreas on 17.11.24.
//

#ifndef SMALLEST_SUBARRAY_WITH_SUM_H
#define SMALLEST_SUBARRAY_WITH_SUM_H
#include <algorithm>
#include <vector>
// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
// whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
int shortest_subarray_with_sum(std::vector<int> & input, int target_sum)
{
    int n = input.size();
    int answer = n+1;
    int left{};
    int sum{};
    for(int i{}; i < n; ++i)
    {
        sum += input[i];
        while(sum >= target_sum)
        {
            answer = std::min(answer, i-left+1);
            sum -= input[left++];
        }
    }
    return answer != n+1 ? answer : 0;
}
#endif //SMALLEST_SUBARRAY_WITH_SUM_H
