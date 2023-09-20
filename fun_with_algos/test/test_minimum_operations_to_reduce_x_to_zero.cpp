//
// Created by andreas on 20.09.23.
//
#include "gtest/gtest.h"
#include "minimum_operations_to_reduce_x_to_zero.h"

TEST(MinimumOperationsToReduceXToZero, simple1)
{
	const std::vector<int> input{1,1,4,3,2};
	constexpr int x{5};
	constexpr int expected_operations{2};
	EXPECT_EQ(expected_operations, minimal_operations_to_reduce_x_to_zero(input, x));
}
