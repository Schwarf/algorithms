//
// Created by andreas on 07.03.23.
//
#include "gtest/gtest.h"
#include "./../kth_missing_element.h"

TEST(kthMissingElement, simple_first_missing)
{
	const std::vector<unsigned int> input {1,2,4,5,6,7};
	const int expected_result{3};
	const int k{1};
	EXPECT_EQ(find_kth_missing_positive_element(input, k), expected_result);
}

TEST(kthMissingElement, simple_first_missing_outside_vector)
{
	const std::vector<unsigned int> input {1,2,3,4,5,6,7};
	const int expected_result{8};
	const int k{1};
	EXPECT_EQ(find_kth_missing_positive_element(input, k), expected_result);
}
