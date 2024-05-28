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

TEST(NQueensTest, OneQueens) {
    int board_size = 1;
    auto solutions = solve_queen_problem(board_size);
    EXPECT_EQ(solutions.size(), 1);  // There are 2 solutions for 4-queens
    for(const auto & solution : solutions)
        check_solution_is_valid(solution);
}

TEST(NQueensTest, TwoQueens) {
    int board_size = 2;
    auto solutions = solve_queen_problem(board_size);
    EXPECT_EQ(solutions.size(), 0);  // There are 2 solutions for 4-queens
    for(const auto & solution : solutions)
        check_solution_is_valid(solution);
}

TEST(NQueensTest, ThreeQueens) {
    int board_size = 3;
    auto solutions = solve_queen_problem(board_size);
    EXPECT_EQ(solutions.size(), 0);  // There are 2 solutions for 4-queens
    for(const auto & solution : solutions)
        check_solution_is_valid(solution);
}

TEST(NQueensTest, FourQueens) {
    int board_size = 4;
    auto solutions = solve_queen_problem(board_size);
    EXPECT_EQ(solutions.size(), 2);  // There are 2 solutions for 4-queens
    for(const auto & solution : solutions)
        check_solution_is_valid(solution);
}

TEST(NQueensTest, FiveQueens) {
    int board_size = 5;
    auto solutions = solve_queen_problem(board_size);
    EXPECT_EQ(solutions.size(), 10);  // There are 10 solutions for 5-queens
    for(const auto & solution : solutions)
        check_solution_is_valid(solution);
}

TEST(NQueensTest, SixQueens) {
    int board_size = 6;
    auto solutions = solve_queen_problem(board_size);
    EXPECT_EQ(solutions.size(), 4);  // There are 10 solutions for 5-queens
    for(const auto & solution : solutions)
        check_solution_is_valid(solution);
}

TEST(NQueensTest, SevenQueens) {
    int board_size = 7;
    auto solutions = solve_queen_problem(board_size);
    EXPECT_EQ(solutions.size(), 40);  // There are 10 solutions for 5-queens
    for(const auto & solution : solutions)
        check_solution_is_valid(solution);
}

TEST(NQueensTest, EightQueens) {
    int board_size = 8;
    auto solutions = solve_queen_problem(board_size);
    EXPECT_EQ(solutions.size(), 92);  // There are 10 solutions for 5-queens
    for(const auto & solution : solutions)
        check_solution_is_valid(solution);
}
