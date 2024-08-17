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

// O(N^2 *M) N is number of columns, M number of rows, Space-complexity O(N*M)
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


// O(N*M) N is number of columns, M number of rows, Space-complexity O(N*M
long long get_maximum_cost_dp(std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    std::vector<long long> previous_row(columns);
    for (int col{}; col < columns; ++col) {
        previous_row[col] = matrix[0][col];
    }
    for (int row{}; row < rows - 1; ++row) {
        std::vector<long long> left_maxima(columns);
        std::vector<long long> right_maxima(columns);
        std::vector<long long> current_row(columns);

        left_maxima[0] = previous_row[0];
        // We compute all the maxima left of the col-index. If the value in the previous row is the largest
        // it is chosen. If the any value left of the current index is the largest (including the subtraction) we find it.
        for (int col{1}; col < columns; ++col) {
            left_maxima[col] = std::max(left_maxima[col - 1] - 1, previous_row[col]);
        }
        // Now the same for right
        right_maxima[columns - 1] = previous_row[columns - 1];
        for (int col{columns - 2}; col > -1; --col) {
            right_maxima[col] = std::max(right_maxima[col + 1] - 1, previous_row[col]);
        }
        // Now we find the maximum for the current row
        for (int col{}; col < columns; ++col) {
            current_row[col] = matrix[row + 1][col] + std::max(left_maxima[col], right_maxima[col]);
        }
        previous_row = current_row;
    }
    return *std::max_element(previous_row.begin(), previous_row.end());
}


#endif //DYNAMIC_PROGRAMMING_SAMPLES_MAXIMUM_NUMBER_OF_POINTS_WITH_COSTS_H


