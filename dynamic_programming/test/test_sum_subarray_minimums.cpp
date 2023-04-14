//
// Created by andreas on 27.11.22.
//
#include "gtest/gtest.h"
#include <vector>
#include "./../sum_subarray_minimums.h"

TEST(ComputeSumSubArrayMinimums, Test1)
{
	std::vector<int> input{3, 1, 2, 4};
	long result{17};
	EXPECT_EQ(result, sum_of_subarray_minimums(input));
}

TEST(ComputeSumSubArrayMinimums, Test2)
{
	std::vector<int> input{11, 81, 94, 43, 3};
	long result{444};
	EXPECT_EQ(result, sum_of_subarray_minimums(input));
}


TEST(ComputeSumSubArrayMinimums, Test3)
{
	std::vector<int> input{11, 2190, 2, 12, 190, 9, 23819, 3, 31, 12, 10190, 89, 679, 6730, 9890};
	long result{62961};
	EXPECT_EQ(result, sum_of_subarray_minimums(input));
}
