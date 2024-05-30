//
// Created by andreas on 02.08.23.
//

#ifndef COMPUTE_ALL_PERMUTATIONS_H
#define COMPUTE_ALL_PERMUTATIONS_H

#include <vector>

template<typename T>
void backtrack(std::vector<std::vector<T>> &result, std::vector<T> &current, const std::vector<T> &input) {
    if (current.size() == input.size()) {
        result.push_back(current);
        return;
    }
    for (const auto &element: input) {
        if (std::find(current.begin(), current.end(), element) == current.end()) {
            current.push_back(element);
            backtrack(result, current, input);
            current.pop_back();
        }
    }
}

template<typename T>
std::vector<std::vector<T>> compute_all_permutations(const std::vector<T> &input) {
    std::vector<std::vector<T>> result;
    std::vector<T> current;
    backtrack(result, current, input);
    return result;
}

#endif //COMPUTE_ALL_PERMUTATIONS_H
