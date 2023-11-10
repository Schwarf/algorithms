//
// Created by andreas on 10.11.23.
//
#include "gtest/gtest.h"
#include "graphs/reconstruct_array_from_adjacent_pairs.h"

TEST(ReconstructArrayFromAdjacentPairs, simple1)
{
	std::vector<std::vector<unsigned int>> input{{2, 1}, {3, 4}, {3, 2}};
	const std::vector<unsigned int> expected_result{1, 2, 3, 4};
	auto result = reconstruct_array_from_adjacent_pairs(input);
	std::reverse(result.begin(), result.end());
	EXPECT_EQ(expected_result, result);
}

TEST(ReconstructArrayFromAdjacentPairs, simple2)
{
	std::vector<std::vector<int>> input{{4, -2}, {1, 4}, {-3, 1}};
	const std::vector<int> expected_result{-2, 4, 1, -3};
	auto result = reconstruct_array_from_adjacent_pairs(input);
	std::reverse(result.begin(), result.end());
	EXPECT_EQ(expected_result, result);
}

