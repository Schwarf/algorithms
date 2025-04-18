//
// Created by andreas on 17.04.25.
//

#ifndef SLIDING_WINDOW_MAXIMUM_H
#define SLIDING_WINDOW_MAXIMUM_H
// You are given an array of integers nums, there is a sliding window of size k which is moving from
// the very left of the array to the very right. You can only see the k numbers in the window.
// Each time the sliding window moves right by one position.
// Return the max sliding window.
#include <vector>
#include <deque>
std::vector<int> sliding_window_maximum(std::vector<int>& input, int window_size) {
    int n = input.size();
    std::deque<int> deque;
    std::vector<int> result;
    // fille the deque with indices
    for(int i{}; i < window_size; ++i)
    {
        while(!deque.empty() && input[i]>= input[deque.back()]){
            deque.pop_back();
        }
        deque.push_back(i);
    }
    // now index of maximum is at front of deque
    result.push_back(input[deque.front()]);
    for(int i= window_size; i < n; ++i)
    {
        if(deque.front() == i -window_size)
        {
            deque.pop_front();
        }
        while(!deque.empty() && input[i] >= input[deque.back()]){
            deque.pop_back();
        }
        deque.push_back(i);
        result.push_back(input[deque.front()]);
    }
    return result;
}

#endif //SLIDING_WINDOW_MAXIMUM_H
