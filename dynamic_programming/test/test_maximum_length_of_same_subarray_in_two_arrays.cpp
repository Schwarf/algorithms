//
// Created by andreas on 20.09.22.
//
#include "gtest/gtest.h"
#include "./../maximum_length_of_same_subarray_in_two_arrays.h"

class SetupMaximumLengthOfSameSubarrayInTwoArrays : public testing::Test
{
protected:
	std::vector<int> first_array1{1,2,3,7,8,1,2,3,4,9, 10, 167};
	std::vector<int> second_array1{9,8,1,2,3,4,8,9,0};
	int answer1{5};
	std::vector<int> first_array2{};
	std::vector<int> second_array2{};
	int answer2{};
	std::vector<int> first_array3{1};
	std::vector<int> second_array3{2};
	int answer3{};
	std::vector<int> first_array4{1,2,3,4,5};
	std::vector<int> second_array4{2,7,8,9,0};
	int answer4{1};

};


TEST_F(SetupMaximumLengthOfSameSubarrayInTwoArrays, test_array1)
{
	auto result = maximum_length(first_array1, second_array1);
	EXPECT_EQ(result, answer1);
}

TEST_F(SetupMaximumLengthOfSameSubarrayInTwoArrays, test_array2)
{
	auto result = maximum_length(first_array2, second_array2);
	EXPECT_EQ(result, answer2);
}

TEST_F(SetupMaximumLengthOfSameSubarrayInTwoArrays, test_array3)
{
	auto result = maximum_length(first_array3, second_array3);
	EXPECT_EQ(result, answer3);
}

TEST_F(SetupMaximumLengthOfSameSubarrayInTwoArrays, test_array4)
{
	auto result = maximum_length(first_array4, second_array4);
	EXPECT_EQ(result, answer4);
}
