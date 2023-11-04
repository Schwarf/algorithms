//
// Created by andreas on 04.11.23.
//
#include "gtest/gtest.h"
#include "sort_according_to_hamming_weight.h"


TEST(SortAccordingToHammingWeight, simple1)
{
	std::vector<int> input{0,1,2,3,4,5,6,7,8};
	std::vector<int> expected_result{0,1,2,4,8,3,5,6,7};
	sort_according_to_hamming_weight(input, get_hamming_weight_inefficient<int>);
	EXPECT_EQ(input, expected_result);
}