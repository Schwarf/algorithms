//
// Created by andreas on 06.04.25.
//

#include "graphs/moves_to_solve_sliding_puzzle.h"
#include "gtest/gtest.h"

TEST(TestMovesToSolveSlidingPuzzle, simple1)
{
    std::vector<std::vector<int>> board = {{1,2,3}, {4, 0, 5}};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, moves_to_solve_sliding_puzzle(board));
}

TEST(TestMovesToSolveSlidingPuzzle, simple2)
{
    std::vector<std::vector<int>> board = {{1,2,3}, {5, 0, 4}};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, moves_to_solve_sliding_puzzle(board));
}
