//
// Created by andreas on 05.11.23.
//

#ifndef FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H
#define FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H

#include <vector>
#include <algorithm>
#include <unordered_map>

// An integer array original is transformed into a doubled array changed by appending twice
// the value of every element in original, and then randomly shuffling the resulting array.
// Given an array changed, return original if changed is a doubled array.
// If the changed array is not a doubled array, return an empty array.
// The elements in original may be returned in any order.
template<typename T, typename = typename std::enable_if<std::is_arithmetic_v<T>>>
std::vector<T> find_array_from_doubled_arrays(std::vector<T> &input) {
    if (input.size() & 1)
        return {};
    std::unordered_map<T, int> counter;
    for (const auto &element: input) {
        counter[element]++;
    }
    std::sort(input.begin(), input.end());
    std::vector<T> result;
    for (int i{}; i < input.size(); ++i) {
        auto current = input[i];
        if (counter[current] == 0)
            continue;
        if (counter.find(2 * current) == counter.end() || counter[2 * current] < 1) {
            return {};
        } else {
            counter[current]--;
            counter[2 * current]--;
            result.push_back(current);
        }
    }
    return result;
}

#endif //FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H
