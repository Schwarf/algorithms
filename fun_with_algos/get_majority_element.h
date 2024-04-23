//
// Created by andreas on 04.12.22.
//

#include <unordered_map>
#include <vector>

#ifndef GET_MAJORITY_ELEMENT_H
#define GET_MAJORITY_ELEMENT_H

// The majority element in an array of length n appears at least n/2 times in the array. Find it. input-element between
// +/- 10^9
template<typename T>
T get_majority_element_hashmap(const std::vector <T> &input) {
    std::unordered_map<T, int> counter;
    for (const auto &element: input) {
        if (++counter[element] > input.size() / 2)
            return element;
    }
    return {};
}

// Works only for integral types because we manipulate bits
template<typename T>
requires std::is_integral_v<T>

T get_majority_element_bit_manipulation(const std::vector <T> &input) {
    T majority_element{};
    // Works because we are between +/-10**9
    for (int i{}; i < 32; ++i) {
        int current_bit = 1 << i;
        int current_bit_count{};
        for (const auto &element: input)
            current_bit_count += (element & current_bit) ? 1 : 0;
        // Set bit in majority_element
        if (current_bit_count > input.size() / 2)
            majority_element |= current_bit;
    }
    return majority_element;
}

// Should work for all types
template<typename T>
T get_majority_element_boyer_moore(const std::vector <T> &input, T initial_candidate) {
    int count{};
    // Works because we are between +/-10**9
    T candidate = initial_candidate;
    for (const auto &element: input) {
        candidate = (count == 0) ? element : candidate;
        count += (element == candidate) ? 1 : -1;
    }
    return candidate;
}


#endif //GET_MAJORITY_ELEMENT_H
