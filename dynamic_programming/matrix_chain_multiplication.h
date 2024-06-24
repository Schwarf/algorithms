//
// Created by andreas on 24.06.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_MATRIX_CHAIN_MULTIPLICATION_H
#define DYNAMIC_PROGRAMMING_SAMPLES_MATRIX_CHAIN_MULTIPLICATION_H
// Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is
// (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices
// together such that the total number of element multiplications is minimum.
#include <vector>

int minimal_matrix_chain_multiplications(std::vector<int> &matrix_dimensions, int matrix_index1 = -1,
                                         int matrix_index2 = -1) {
    // Initialization for external call.
    // We have number_of_matrices+1 entries in matrix_dimensions.
    if (matrix_index1 == -1) {
        matrix_index1 = 1;
        matrix_index2 = matrix_dimensions.size() - 1;
    }
    if (matrix_index1 == matrix_index2)
        return 0;
    int minimum = std::numeric_limits<int>::max();
    int count{};
    for (int k{matrix_index1}; k < matrix_index2; ++k) {
        const int to_add =
                matrix_dimensions[matrix_index1 - 1] * matrix_dimensions[k] * matrix_dimensions[matrix_index2];
        count = minimal_matrix_chain_multiplications(matrix_dimensions, matrix_index1, k) +
                minimal_matrix_chain_multiplications(matrix_dimensions, k + 1, matrix_index2) +
                to_add;
        minimum = std::min(minimum, count);
    }
    return minimum;
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_MATRIX_CHAIN_MULTIPLICATION_H
