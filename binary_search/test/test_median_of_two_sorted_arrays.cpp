//
// Created by andreas on 02.07.23.
//

#include "gtest/gtest.h"
#include "random"
#include "./../median_of_two_sorted_arrays.h"

TEST(FindMedianOfTwoSortedArrays, simple_first)
{
	const std::vector<int> input1{1, 2, 3, 4, 5, 7, 9};
	const std::vector<int> input2{3, 4, 5, 7, 9, 11, 22, 122};
	constexpr double expected_result{5.0};
	EXPECT_EQ(median_of_sorted_arrays(input1, input2), expected_result);
}


TEST(FindMedianOfTwoSortedArrays, simple_second)
{
	const std::vector<int> input1{1, 2, 3, 4, 5, 7, 9, 12, 190, 1010, 21211};
	const std::vector<int> input2{3, 4, 5, 7, 9, 11, 22, 122};
	constexpr double expected_result{7.0};
	EXPECT_EQ(median_of_sorted_arrays(input1, input2), expected_result);
}

TEST(FindMedianOfTwoSortedArrays, simple_third)
{
	const std::vector<int> input1{1, 3};
	const std::vector<int> input2{2};
	constexpr double expected_result{2.0};
	EXPECT_EQ(median_of_sorted_arrays(input1, input2), expected_result);
}


TEST(FindMedianOfTwoSortedArrays, simple_fourth)
{
	const std::vector<int> input1{1, 3};
	const std::vector<int> input2{2, 4};
	constexpr double expected_result{2.5};
	EXPECT_EQ(median_of_sorted_arrays(input1, input2), expected_result);
}

