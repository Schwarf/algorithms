//
// Created by andreas on 24.03.24.
//

#include "./../find_duplicate_in_array.h"
#include "gtest/gtest.h"

TEST(TestFindDuplicate, simple1)
{
	std::vector<int> input {1,3,4,2,2};
	constexpr int expected_output{2};
	EXPECT_EQ(expected_output, find_duplicate(input));
}

TEST(TestFindDuplicate, simple2)
{
	std::vector<int> input {3,1,3,4,2};
	constexpr int expected_output{3};
	EXPECT_EQ(expected_output, find_duplicate(input));
}

TEST(TestFindDuplicate, simple3)
{
	std::vector<int> input {1,1,1,1,1};
	constexpr int expected_output{1};
	EXPECT_EQ(expected_output, find_duplicate(input));
}

TEST(TestFindDuplicate, simple4)
{
	std::vector<int> input {1,2,3,4,5,6,7,7};
	constexpr int expected_output{7};
	EXPECT_EQ(expected_output, find_duplicate(input));
}

TEST(TestFindDuplicate, simple5)
{
	std::vector<int> input {1,1};
	constexpr int expected_output{1};
	EXPECT_EQ(expected_output, find_duplicate(input));
}