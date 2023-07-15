//
// Created by andreas on 14.07.23.
//
#include "gtest/gtest.h"
#include "knapsack_problem.h"

class SetupKnapsackProblem: public testing::Test
{
protected:
	std::vector<Item<int, int>> items1{{6, 1}, {10, 2}, {12, 3}};
	int knapsack1{5};
	std::vector<Item<int, int>> items2{{3, 2}, {4, 3}, {5, 4}, {6, 5}};
	int knapsack2{8};

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
