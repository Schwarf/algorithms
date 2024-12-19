//
// Created by andreas on 19.12.24.
//

#ifndef TAKE_GIFTS_FROM_GREATEST_PILE_H
#define TAKE_GIFTS_FROM_GREATEST_PILE_H
// You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
//     Choose the pile with the maximum number of gifts.
//     If there is more than one pile with the maximum number of gifts, choose any.
//     Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
// Return the number of gifts remaining after k seconds.

#include <cmath>
#include <vector>
#include <queue>

long long pick_gifts(std::vector<int>& gifts, int k) {
    std::priority_queue<int> q(gifts.begin(), gifts.end());
    for(int i{}; i < k; ++i)
    {
        int new_value = q.top();
        q.pop();
        q.push(std::sqrt(new_value));
    }
    long long result{};
    while(!q.empty())
    {
        result+= q.top();
        q.pop();
    }
    return result;

}
#endif //TAKE_GIFTS_FROM_GREATEST_PILE_H
