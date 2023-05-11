//
// Created by andreas on 11.05.23.
//

#ifndef TEST_MAXIMUM_NUMBER_OF_UNCROSSING_LINES_CPP
#define TEST_MAXIMUM_NUMBER_OF_UNCROSSING_LINES_CPP
#include "gtest/gtest.h"
#include "maximum_number_of_uncrossing_lines.h"

TEST(MaximumNumberOfUncrossingLines, simple1)
{
	std::vector<size_t> input1{1, 4, 2};
	std::vector<size_t> input2{1, 2, 4};
	int expected_result{2};
	EXPECT_EQ(expected_result, maximum_number_of_uncrossing_lines(input1, input2));
}

TEST(MaximumNumberOfUncrossingLines, simple2)
{
	std::vector<size_t> input1{2, 5, 1, 2, 5};
	std::vector<size_t> input2{10, 5, 2, 1, 5, 2};
	int expected_result{3};
	EXPECT_EQ(expected_result, maximum_number_of_uncrossing_lines(input1, input2));
}

TEST(MaximumNumberOfUncrossingLines, simple3)
{
	std::vector<size_t> input1{1, 3, 7, 1, 7, 5};
	std::vector<size_t> input2{1, 9, 2, 5, 1};
	int expected_result{2};
	EXPECT_EQ(expected_result, maximum_number_of_uncrossing_lines(input1, input2));
}

#endif //TEST_MAXIMUM_NUMBER_OF_UNCROSSING_LINES_CPP
