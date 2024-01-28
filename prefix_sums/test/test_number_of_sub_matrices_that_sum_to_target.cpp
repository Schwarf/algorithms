//
// Created by andreas on 28.01.24.
//
#include "gtest/gtest.h"
#include "number_of_sub_matrices_that_sum_to_target.h"

TEST(TestNumberOfSubMatricesThatSumToTarget, simple1)
{
	const std::vector<std::vector<int>> input {{0,0}, {0,0}};
	constexpr int target{};
	constexpr int expected_result{9};
	EXPECT_EQ(expected_result, number_of_sub_matrices_with_target_sum(input, target));
}