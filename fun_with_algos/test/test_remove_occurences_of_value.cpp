//
// Created by andreas on 05.06.23.
//

#include <gtest/gtest.h>
#include "./../remove_occurences_of_value.h"

TEST(RemoveOccurencesOfValue, simple1)
{
	std::vector<int> input{3, 2, 1, 2, 3, 3, 5, 6, 7};
	constexpr int value_to_remove{3};
	constexpr int expected_length{6};
	std::vector<int> expected_output{2, 1, 2, 5, 6, 7};
	EXPECT_EQ(remove_value(input, value_to_remove), expected_length);
	for (int i{}; i < expected_length; i++) {
		EXPECT_EQ(expected_output[i], input[i]);
	}
}

TEST(RemoveOccurencesOfValue, simple2)
{
	std::vector<int> input{0, 1, 2, 2, 3, 0, 4, 2};
	constexpr int value_to_remove{2};
	constexpr int expected_length{5};
	std::vector<int> expected_output{0, 1, 3, 0, 4};
	EXPECT_EQ(remove_value(input, value_to_remove), expected_length);
	for (int i{}; i < expected_length; i++) {
		EXPECT_EQ(expected_output[i], input[i]);
	}
}
