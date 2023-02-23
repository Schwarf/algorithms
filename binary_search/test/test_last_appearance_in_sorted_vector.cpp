//
// Created by andreas on 22.02.23.
//

#include "gtest/gtest.h"

#include <algorithm>
#include "./../last_appearance_in_sorted_vector.h"

TEST(LastAppearance, simple)
{
	std::vector<int> input{0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7};
	int target = 5;
	int expected_result = std::distance(input.begin(), std::upper_bound(input.begin(), input.end(), target));
	int result = last_appearance(input, target);
	EXPECT_EQ(result, expected_result);
}

TEST(LastAppearance, simple2)
{
	std::vector<int> input{0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7};
	int target = 11;
	int expected_result = std::distance(input.begin(), std::upper_bound(input.begin(), input.end(), target));
	int result = last_appearance(input, target);
	EXPECT_EQ(result, expected_result);
}

TEST(LastAppearance, simple3)
{
	std::vector<int> input{0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7};
	int target = -1;
	int expected_result = std::distance(input.begin(), std::upper_bound(input.begin(), input.end(), target));
	int result = last_appearance(input, target);
	EXPECT_EQ(result, expected_result);
}

TEST(LastAppearance, simple4)
{
	std::vector<int> input{};
	int target = -1;
	int expected_result = std::distance(input.begin(), std::upper_bound(input.begin(), input.end(), target));
	int result = last_appearance(input, target);
	EXPECT_EQ(result, expected_result);
}