//
// Created by andreas on 27.12.24.
//

#ifndef MAXIMIZE_INDEX_VALUE_PAIR_H
#define MAXIMIZE_INDEX_VALUE_PAIR_H
#include <vector>
// You are given an integer array values inputs[i]. Return the maximum pair  inputs[i] + inputs[j] + i - j
// with i < j.

int max_index_value_pair(std::vector<int>& inputs) {
    int n = inputs.size();
    std::vector<int> max_left(n);
    max_left[0] = inputs[0];
    int max{};
    for(int i{1}; i < n; ++i)
    {
        const int current_right = inputs[i] - i;
        max = std::max(max, max_left[i-1]+ current_right);
        const int current_left = inputs[i] + i;
        max_left[i] = std::max(max_left[i-1], current_left);
    }
    return max;
}


#endif //MAXIMIZE_INDEX_VALUE_PAIR_H
