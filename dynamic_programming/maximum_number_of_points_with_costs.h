//
// Created by andreas on 17.08.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_MAXIMUM_NUMBER_OF_POINTS_WITH_COSTS_H
#define DYNAMIC_PROGRAMMING_SAMPLES_MAXIMUM_NUMBER_OF_POINTS_WITH_COSTS_H

// You are given a n x m matrix. The goal is to maximize your point score. Yuo can pick one element from
// each row of the matrix and add it to your score. But for each score added you have to subtract a cost value.
// The cost value is given as the absolute difference of column indices between the column in the current row and
// and the column chosen in the row before.
#include <vector>

// O(N^2 *M) N is number of columns, M number of rows
long long get_maximum_cost_dp_brute_force(std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    std::vector<std::vector<long long>> dp(rows, std::vector<long long>(columns));
    for (int col{}; col < columns; ++col) {
        dp[0][col] = matrix[0][col];
    }
    for (int row{1}; row < rows; ++row) {
        for (int col{}; col < columns; ++col) {
            for (int col_before{}; col_before < columns; ++col_before) {
                dp[row][col] = std::max(dp[row][col],
                                        dp[row - 1][col_before] + matrix[row][col] - std::abs(col - col_before));
            }

        }
    }
    return *std::max_element(dp[rows - 1].begin(), dp[rows - 1].end());
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_MAXIMUM_NUMBER_OF_POINTS_WITH_COSTS_H

