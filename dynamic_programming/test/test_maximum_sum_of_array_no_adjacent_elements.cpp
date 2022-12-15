//
// Created by andreas on 14.12.22.
//
#include "gtest/gtest.h"
#include "./../maximum_sum_of_array_no_adjacent_elements.h"
#include <vector>

TEST(test_maximum_sum_of_array_no_neighbors, scenario1)
{
	auto input = std::vector<int>{1, 2, 3, 1};
	auto result = 4;
	EXPECT_EQ(get_maximum_sum_no_adjacent_elements_sum(input), result);
}

TEST(test_maximum_sum_of_array_no_neighbors, scenario2)
{
	auto input = std::vector<int>{2, 7, 9, 3, 1};
	auto result = 12;
	EXPECT_EQ(get_maximum_sum_no_adjacent_elements_sum(input), result);
}

TEST(test_maximum_sum_of_array_no_neighbors, scenario3)
{
	auto input = std::vector<int>{10, 1, 10, 20, 2};
	auto result = 30;
	EXPECT_EQ(get_maximum_sum_no_adjacent_elements_sum(input), result);
}