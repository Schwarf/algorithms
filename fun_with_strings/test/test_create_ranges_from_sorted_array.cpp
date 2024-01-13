//
// Created by andreas on 13.01.24.
//
#include "gtest/gtest.h"
#include "./../create_ranges_from_sorted_array.h"

TEST(CreateRangeFromSortedArray, simple1)
{
	const std::vector<int> input{0, 1, 2, 4, 5, 7};
	const std::vector<std::string> expected_output{"0->2", "4->5", "7"};
	EXPECT_EQ(expected_output, create_ranges_from_sorted_array(input));
}

TEST(CreateRangeFromSortedArray, simple2)
{
	const std::vector<int> input{};
	const std::vector<std::string> expected_output{};
	EXPECT_EQ(expected_output, create_ranges_from_sorted_array(input));
}

TEST(CreateRangeFromSortedArray, simple3)
{
	const std::vector<int> input{0, 2, 3, 4, 6, 8, 9};
	const std::vector<std::string> expected_output{"0", "2->4", "6", "8->9"};
	EXPECT_EQ(expected_output, create_ranges_from_sorted_array(input));
}

TEST(CreateRangeFromSortedArray, simple4)
{
	const std::vector<int> input{0,1,2,4,5,7,9,10,12,14,15,16,27,28};
	const std::vector<std::string> expected_output{"0->2","4->5","7","9->10","12","14->16","27->28"};
	EXPECT_EQ(expected_output, create_ranges_from_sorted_array(input));
}
