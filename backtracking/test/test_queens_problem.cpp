//
// Created by andreas on 23.05.24.
//
#include "gtest/gtest.h"
#include "../queens_problem.h"

void check_solution_is_valid(const std::vector<std::vector<int>> &board) {
    int n = board.size();
    std::vector<bool> columns(n, false);
    std::vector<bool> forward_diagonals(2 * n - 1, false);
    std::vector<bool> backward_diagonals(2 * n - 1, false);

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (board[row][col]) {
                EXPECT_FALSE(columns[col]);
                EXPECT_FALSE(backward_diagonals[col + row]);
                EXPECT_FALSE(forward_diagonals[col - row + n - 1]);

                columns[col] = true;
                backward_diagonals[col + row] = true;
                forward_diagonals[col - row + n - 1] = true;
            }
        }
    }
}

TEST(NQueensTest, FourQueens) {
    int board_size = 4;
    auto solution = solve_queen_problem(board_size);
    EXPECT_EQ(solution.size(), 2);  // There are 2 solutions for 4-queens
    check_solution_is_valid(solution);
}
