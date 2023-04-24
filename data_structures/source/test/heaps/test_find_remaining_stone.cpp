//
// Created by andreas on 24.04.23.
//
#include <numeric>
#include "gtest/gtest.h"
#include "heaps/find_remaining_stone.h"

TEST(FindRemainingStone, one_large_stones)
{
	std::vector<int> stones{1000, 1, 2, 3};
	const int expected_answer{994};
	auto result = find_remaining_stone<int, 4>(stones);
	EXPECT_EQ(expected_answer, result);
}

TEST(FindRemainingStone, one_large_stone_many_small)
{
	std::vector<int> stones(1000);
	std::iota(stones.begin(), stones.end(), 1);
	stones.push_back(1000000);
	const int expected_answer{1000000 - 1000 * 1001 / 2};
	auto result = find_remaining_stone<int, 1001>(stones);
	EXPECT_EQ(expected_answer, result);
}

TEST(FindRemainingStone, several_stones)
{
	std::vector<int> stones{2, 7, 4, 1, 8, 1};
	const int expected_answer{1};
	auto result = find_remaining_stone<int, 6>(stones);
	EXPECT_EQ(expected_answer, result);
}

TEST(FindRemainingStone, one_stone)
{
	std::vector<int> stones{2};
	const int expected_answer{2};
	auto result = find_remaining_stone<int, 1>(stones);
	EXPECT_EQ(expected_answer, result);
}
