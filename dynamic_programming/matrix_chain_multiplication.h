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


int top_down_multiplications(std::vector<int> &matrix_dimensions, std::vector<std::vector<int>> &memo,
                             int matrix_index1, int matrix_index2) {
    // Initialization for external call.
    // We have number_of_matrices+1 entries in matrix_dimensions.
    if (matrix_index1 == matrix_index2)
        return 0;
    if (memo[matrix_index1][matrix_index2] != -1)
        return memo[matrix_index1][matrix_index2];
    int minimum = std::numeric_limits<int>::max();
    int count{};
    for (int k{matrix_index1}; k < matrix_index2; ++k) {
        const int to_add =
                matrix_dimensions[matrix_index1 - 1] * matrix_dimensions[k] * matrix_dimensions[matrix_index2];
        count = top_down_multiplications(matrix_dimensions, memo, matrix_index1, k) +
                top_down_multiplications(matrix_dimensions, memo, k + 1, matrix_index2) +
                to_add;
        minimum = std::min(minimum, count);
    }
    memo[matrix_index1][matrix_index2] = minimum;
    return minimum;
}

int top_down_approach(std::vector<int> &matrix_dimensions) {
    int matrix_index1 = 1;
    int matrix_index2 = matrix_dimensions.size() - 1;
    std::vector<std::vector<int>> memo(matrix_dimensions.size(), std::vector<int>(matrix_dimensions.size(), -1));
    return top_down_multiplications(matrix_dimensions, memo, matrix_index1, matrix_index2);
}

int bottom_up_approach(const std::vector<int> &matrix_dimensions) {
    int n = matrix_dimensions.size() - 1; // number of matrices
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i < n - length + 1; ++i) {
            int j = i + length - 1;
            dp[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] +
                           matrix_dimensions[i] * matrix_dimensions[k + 1] * matrix_dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[0][n - 1];
}


#endif //DYNAMIC_PROGRAMMING_SAMPLES_MATRIX_CHAIN_MULTIPLICATION_H
