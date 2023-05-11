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

TEST(MaximumNumberOfUncrossingLines, large1)
{
	std::vector<size_t> input1
		{8, 9, 2, 18, 7, 8, 3, 7, 15, 7, 18, 5, 9, 12, 18, 15, 9, 10, 8, 1, 15, 2, 6, 2, 15, 8, 6, 2, 4, 20, 5, 6, 2,
		 16, 18, 20, 17, 4, 19, 9, 13, 9, 13, 18, 4, 10, 18, 7, 12, 4, 12, 1, 9, 9, 3, 3, 17, 20, 13, 4, 20, 5, 4, 4,
		 11, 4, 11, 15, 3, 12, 16, 12, 2, 6, 1, 20, 9, 11, 12, 18, 3, 10, 13, 7, 15, 11, 13, 18, 1, 7, 5, 10, 19, 14,
		 12, 11, 4, 20, 8, 13, 15, 3, 1, 16, 20, 6, 15, 11, 4, 5, 19, 14, 6, 20, 2, 3, 1, 19, 19, 14, 17, 13, 10, 18, 3,
		 14, 13, 18, 13, 4, 8, 14, 1, 18, 19, 5, 1, 8, 12, 13, 9, 14, 19, 20, 17, 13, 19, 9, 13, 6, 3, 3, 14, 12, 5, 11,
		 11, 14, 8, 11, 4, 19, 15, 20, 3, 18, 6, 7, 7, 17, 15, 3, 12, 18, 12, 13, 9, 9, 12, 13, 12, 8, 15, 16, 3, 17,
		 20, 17, 7, 7, 11, 10, 17, 1, 20, 18, 10, 13, 11, 19};
	std::vector<size_t> input2
		{6, 15, 18, 7, 6, 15, 7, 12, 11, 2, 8, 16, 15, 2, 11, 3, 18, 2, 14, 2, 3, 2, 2, 12, 18, 5, 13, 15, 7, 8, 15, 20,
		 15, 8, 9, 1, 12, 15, 10, 7, 14, 7, 14, 7, 15, 8, 18, 2, 1, 16};
	int expected_result{30};
	EXPECT_EQ(expected_result, maximum_number_of_uncrossing_lines(input1, input2));
}


#endif //TEST_MAXIMUM_NUMBER_OF_UNCROSSING_LINES_CPP
