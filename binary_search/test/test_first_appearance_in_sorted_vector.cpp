//
// Created by andreas on 22.02.23.
//

#include "gtest/gtest.h"

#include <algorithm>
#include "./../first_appearance_in_sorted_vector.h"

TEST(FirstAppearence, simple)
{
	std::vector<int> input{0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
	int target = 5;
	int expected_result = std::distance(input.begin(), std::lower_bound(input.begin(), input.end(), target));
	int result = first_appearance(input, target);
	EXPECT_EQ(result, expected_result);
}

TEST(FirstAppearence, simple2)
{
	std::vector<int> input{0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
	int target = 11;
	int expected_result = std::distance(input.begin(), std::lower_bound(input.begin(), input.end(), target));
	int result = first_appearance(input, target);
	EXPECT_EQ(result, expected_result);
}

TEST(FirstAppearence, simple3)
{
	std::vector<int> input{0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
	int target = -1;
	int expected_result = std::distance(input.begin(), std::lower_bound(input.begin(), input.end(), target));
	int result = first_appearance(input, target);
	EXPECT_EQ(result, expected_result);
}

TEST(FirstAppearence, simple4)
{
	std::vector<int> input{};
	int target = -1;
	int expected_result = std::distance(input.begin(), std::lower_bound(input.begin(), input.end(), target));
	int result = first_appearance(input, target);
	EXPECT_EQ(result, expected_result);
}