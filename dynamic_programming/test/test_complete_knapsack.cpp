//
// Created by andreas on 18.05.25.
//
#include "gtest/gtest.h"
#include "../knapsack/complete_knapsack.h"


class SetupCompleteKnapsackProblem : public testing::Test
{
protected:
    std::vector<Item<int, int>> items1{
        {6, 1},
        {10, 2},
        {12, 3}
    };
    int knapsack1{5};
    std::vector<Item<int, int>> items2{
        {3, 2},
        {4, 3},
        {5, 4},
        {6, 5}
    };
    int knapsack2{8};
    std::vector<Item<int, int>> items3{
        {9, 4},
        {7, 3},
        {5, 2},
        {12, 5},
        {14, 6},
        {2, 1},
        {6, 3},
        {17, 8},
        {21, 9},
        {16, 7},
        {12, 5},
        {10, 4},
        {15, 6},
        {7, 3},
        {5, 2},
        {13, 5},
        {9, 4},
        {16, 6},
        {4, 2},
        {2, 1}
    };
    int knapsack3{30};
};

TEST_F(SetupCompleteKnapsackProblem, knapsack_bottom_up_complete1)
{
    const auto result = complete_knapsack_problem_bottom_up(items1, knapsack1);
    // Adjusted expected result for Complete Knapsack
    constexpr int expected_result{30};  // Update this based on the new problem type
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupCompleteKnapsackProblem, knapsack_bottom_up_complete2)
{
    const auto result = complete_knapsack_problem_bottom_up(items2, knapsack2);
    // Adjusted expected result for Complete Knapsack
    constexpr int expected_result{12};  // Update this based on the new problem type
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupCompleteKnapsackProblem, knapsack_bottom_up_complete3)
{
    const auto result = complete_knapsack_problem_bottom_up(items3, knapsack3);
    // Adjusted expected result for Complete Knapsack
    constexpr int expected_result{118};  // Update this based on the new problem type
    EXPECT_EQ(result, expected_result);
}
