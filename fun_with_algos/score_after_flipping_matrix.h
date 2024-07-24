//
// Created by andreas on 20.05.24.
//

#ifndef FUN_WITH_ALGOS_SCORE_AFTER_FLIPPING_MATRIX_H
#define FUN_WITH_ALGOS_SCORE_AFTER_FLIPPING_MATRIX_H
// You are given an m x n binary matrix grid.
// A move consists of choosing any row or column and toggling each value in that row or column
// (i.e., changing all 0's to 1's, and all 1's to 0's).
// Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
// Return the highest possible score after making any number of moves (including zero moves).
#include <vector>

int matrix_score_after_flipping(std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int columns = grid[0].size();

    // Set first column
    for (int row = 0; row < rows; row++) {
        if (grid[row][0] == 0) {
            // Flip row
            for (int col = 0; col < columns; col++) {
                grid[row][col] = 1 - grid[row][col];
            }
        }
    }

    // Optimize columns except first column
    for (int col = 1; col < columns; col++) {
        int count_zeros{};
        // Count zeros
        for (int row = 0; row < rows; row++) {
            if (grid[row][col] == 0) {
                count_zeros++;
            }
        }
        // Flip the column if there are more zeros for better score
        if (count_zeros > rows - count_zeros) {
            for (int row = 0; row < rows; row++) {
                grid[row][col] = 1 - grid[row][col];
            }
        }
    }

    // Calculate the final score considering bit positions
    int score{};
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            // Left shift bit by place value of column to find column contribution
            int column_score = grid[row][col] << (columns - col - 1);
            // Add contribution to score
            score += column_score;
        }
    }
    return score;
}

#endif //FUN_WITH_ALGOS_SCORE_AFTER_FLIPPING_MATRIX_H
