//
// Created by andreas on 19.12.24.
//

#ifndef SCORE_AFTER_MARKING_ELEMENTS_H
#define SCORE_AFTER_MARKING_ELEMENTS_H
// You are given an array input consisting of positive integers.
//
// Starting with score = 0, apply the following algorithm:
//
//    Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
//    Add the value of the chosen integer to score.
//    Mark the chosen element and its two adjacent elements if they exist.
//    Repeat until all the array elements are marked.
//
// Return the score you get after applying the above algorithm.
#include<vector>
#include<queue>

long long find_score_using_heap(std::vector<int>& input)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    int n = input.size();
    for (int i{}; i < n; ++i)
    {
        q.emplace(input[i], i);
    }
    std::vector<unsigned char> marked(n);
    long long score{};
    while (!q.empty())
    {
        auto [value, index] = q.top();
        q.pop();
        if (!marked[index])
        {
            marked[index] = 1;
            if (index - 1 >= 0)
                marked[index - 1] = 1;
            if (index + 1 < n)
                marked[index + 1] = 1;
            score += value;
        }
    }
    return score;
}

long long find_score_using_sliding_window(std::vector<int>& input)
{
    long long result{};
    int n = input.size();
    for (int i{}; i < n; i += 2)
    {
        int left = i;
        while (i + 1 < n && input[i + 1] < input[i])
        {
            i++;
        }
        for (int right = i; right >= left; right -= 2)
        {
            result += input[right];
        }
    }
    return result;
}

#endif //SCORE_AFTER_MARKING_ELEMENTS_H
