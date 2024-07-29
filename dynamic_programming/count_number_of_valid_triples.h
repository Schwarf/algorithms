//
// Created by andreas on 29.07.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_COUNT_NUMBER_OF_VALID_TRIPLES_H
#define DYNAMIC_PROGRAMMING_SAMPLES_COUNT_NUMBER_OF_VALID_TRIPLES_H
// There are n number in an array. Each number has a unique value.
// You have to form valid triple:
// A valid triple with indices (i, j, k) is valid (array[i], array[j], array[k]).
// if: (array[i] < array[j] < array[k]) or (array[i] > array[j] > array[k]) where (0 <= i < j < k < n).
// Return the number of valid triples you can form given the conditions.
#include <vector>

// Brute force O(N^3)
int valid_triple(std::vector<int> &input) {
    int n = input.size();
    int count_valid_triples{};
    for (int i{}; i < n - 2; ++i) {
        for (int j{i + 1}; j < n - 1; ++j) {
            bool is_greater = input[i] > input[j];
            for (int k{j + 1}; k < n; ++k) {
                if ((is_greater && input[j] > input[k]) || (!is_greater && input[j] < input[k]))
                    count_valid_triples++;
            }
        }
    }
    return count_valid_triples;
}


#endif //DYNAMIC_PROGRAMMING_SAMPLES_COUNT_NUMBER_OF_VALID_TRIPLES_H
