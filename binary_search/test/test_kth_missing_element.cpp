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

TEST(kthMissingElement, simple_1st_2nd_3rd_4th_5th_and_13th_missing)
{
	const std::vector<unsigned int> input {2,3,4,7,11};
	std::map<int, int> k_result;
	k_result[1] = 1;
	k_result[2] = 5;
	k_result[3] = 6;
	k_result[4] = 8;
	k_result[5] = 9;
	k_result[13] = 18;
	for(const auto [k, expected_result] : k_result)
		EXPECT_EQ(find_kth_missing_positive_element(input, k), expected_result);
}

