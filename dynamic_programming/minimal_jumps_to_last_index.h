//
// Created by andreas on 13.07.23.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_JUMPS_TO_LAST_INDEX_H
#define DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_JUMPS_TO_LAST_INDEX_H
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.
#include <concepts>
#include <vector>
#include <iostream>

template<typename T>
requires std::is_unsigned_v<T>
T minimal_jumps_to_last_index_recursive(std::vector<T> &distances, T start = 0) {
    if (start == distances.size() - 1)
        return 0;
    T min{1000000000};
    for (int i{1}; i <= distances[start]; ++i) {
        if (start + i <= (distances.size() - 1)) {
            min = std::min(min, 1 + minimal_jumps_to_last_index_recursive(distances, start + i));
        }
    }
    return min;
}

template<typename T>
requires std::is_unsigned_v<T>
int memoization(std::vector<T> &distances, T start, std::vector<int> &memo) {
    if (start == distances.size() - 1)
        return 0;
    if (memo[start] != -1)
        return memo[start];
    int min{1000000000};
    for (int i{1}; i <= distances[start]; ++i) {
        if (start + i <= distances.size() - 1) {
            min = std::min(min, 1 + memoization(distances, start + i, memo));
        }
    }
    memo[start] = min;
    return min;

}

template<typename T>
requires std::is_unsigned_v<T>
int minimal_jumps_to_last_index_top_down(std::vector<T> &distances) {
    std::vector<int> memo(distances.size(), -1);
    return memoization(distances, T{}, memo);
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_JUMPS_TO_LAST_INDEX_H
