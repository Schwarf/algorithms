//
// Created by andreas on 14.07.23.
//
#include "gtest/gtest.h"
#include "../../knapsack/knapsack_problem_0_1.h"

class SetupKnapsackProblem : public testing::Test
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


TEST_F(SetupKnapsackProblem, knapsack_recursive1)
{
    const auto result = knapsack_problem_recursive(items1, knapsack1);
    constexpr int expected_result{22};
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupKnapsackProblem, knapsack_recursive2)
{
    const auto result = knapsack_problem_recursive(items2, knapsack2);
    constexpr int expected_result{10};
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupKnapsackProblem, knapsack_recursive3)
{
    const auto result = knapsack_problem_recursive(items3, knapsack3);
    // Checked online: https://augustineaykara.github.io/Knapsack-Calculator/
    constexpr int expected_result{76};
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupKnapsackProblem, knapsack_top_down1)
{
    const auto result = knapsack_problem_top_down(items1, knapsack1);
    constexpr int expected_result{22};
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupKnapsackProblem, knapsack_top_down2)
{
    const auto result = knapsack_problem_top_down(items2, knapsack2);
    constexpr int expected_result{10};
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupKnapsackProblem, knapsack_top_down3)
{
    const auto result = knapsack_problem_top_down(items3, knapsack3);
    // Checked online: https://augustineaykara.github.io/Knapsack-Calculator/
    constexpr int expected_result{76};
    EXPECT_EQ(result, expected_result);
}


TEST_F(SetupKnapsackProblem, knapsack_bottom_up1)
{
    const auto result = knapsack_problem_bottom_up(items1, knapsack1);
    constexpr int expected_result{22};
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupKnapsackProblem, knapsack_bottom_up2)
{
    const auto result = knapsack_problem_bottom_up(items2, knapsack2);
    constexpr int expected_result{10};
    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupKnapsackProblem, knapsack_bottom_up3)
{
    const auto result = knapsack_problem_bottom_up(items3, knapsack3);
    // Checked online: https://augustineaykara.github.io/Knapsack-Calculator/
    constexpr int expected_result{76};
    EXPECT_EQ(result, expected_result);
}
