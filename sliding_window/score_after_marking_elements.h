//
// Created by andreas on 19.12.24.
//

#ifndef SCORE_AFTER_MARKING_ELEMENTS_H
#define SCORE_AFTER_MARKING_ELEMENTS_H
// You are given an array nums consisting of positive integers.
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
long long find_score(std::vector<int>& nums) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    int n = nums.size();
    for(int i {}; i < n; ++i)
    {
        q.emplace(nums[i], i);
    }
    std::vector<unsigned char> marked(n);
    long long score{};
    while(!q.empty())
    {
        auto [value, index] = q.top();
        q.pop();
        if(!marked[index])
        {
            marked[index] = 1;
            if(index -1 >= 0)
                marked[index-1] = 1;
            if(index +1 < n)
                marked[index+1] = 1;
            score += value;
        }
    }
    return score;
}
#endif //SCORE_AFTER_MARKING_ELEMENTS_H
