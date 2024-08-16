//
// Created by andreas on 16.08.24.
//

#ifndef FUN_WITH_ALGOS_MAXIMUM_DISTANCE_IN_ARRAYS_H
#define FUN_WITH_ALGOS_MAXIMUM_DISTANCE_IN_ARRAYS_H
// You are given m arrays, where each array is sorted in ascending order.
// You can pick up two integers from two different arrays (each array picks one) and calculate the distance.
// We define the distance between two integers a and b to be their absolute difference |a - b|.
// Return the maximum distance.
#include <vector>

int get_maximum_distance_brute_force(std::vector<std::vector<int>> &input) {
    int max_distance = std::numeric_limits<int>::min();
    int n = input.size();
    // Iterate over all pairs of input
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_distance = std::max(max_distance, std::abs(input[i].back() - input[j].front()));
        }
    }
    return max_distance;
}

int get_maximum_distance(std::vector<std::vector<int>> &input) {
    auto min = input.front().front();
    auto max = input.front().back();
    int n = input.size();
    int max_distance{};
    for (int i{1}; i < n; ++i) {
        max_distance = std::max(std::abs(input[i].back()-min), max_distance);
        max_distance = std::max(std::abs(max - input[i].front()), max_distance);
        min = std::min(min, input[i].front());
        max = std::max(max, input[i].back());
    }
    return max_distance;
}


#endif //FUN_WITH_ALGOS_MAXIMUM_DISTANCE_IN_ARRAYS_H
