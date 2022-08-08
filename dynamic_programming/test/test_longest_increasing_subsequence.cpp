//
// Created by andreas on 08.08.22.
//
#include <utility>
#include <vector>
#include "gtest/gtest.h"
#include "./../longest_increasing_subsequence.h"

class SetupLongestIncreasingSubsequence : public testing::Test
{
protected:
	std::vector<int> input1{10,9,2,5,3,7,101,18};
	int result1{4};
	std::vector<int> input2{0,1,0,3,2,3};
	int result2{4};
	std::vector<int> input3{1, 12, 419, 181, 17, 19, 0, 71, 26, 1, 2, 3, 4, 5, 6, 7};
	int result3{8};
};


TEST_F(SetupLongestIncreasingSubsequence, test_first_implementation_scenario1)
{
	auto output1 = size_of_longest_increasing_subsequence(input1);
	EXPECT_EQ(result1, output1);
}

TEST_F(SetupLongestIncreasingSubsequence, test_first_implementation_scenario2)
{
	auto output2 = size_of_longest_increasing_subsequence(input2);
	EXPECT_EQ(result2, output2);
}

TEST_F(SetupLongestIncreasingSubsequence, test_first_implementation_scenario3)
{
	auto output3 = size_of_longest_increasing_subsequence(input3);
	EXPECT_EQ(result3, output3);
}
