//
// Created by andreas on 03.04.24.
//
#include "gtest/gtest.h"
#include "graphs/does_word_exist_in_grid.h"

TEST(TestDoesWordExistInGrid, simple1)
{
	std::vector<std::vector<char>> grid{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	const std::string word{"ABCCED"};
	EXPECT_TRUE(does_word_exist(grid, word));
}

TEST(TestDoesWordExistInGrid, simple2)
{
	std::vector<std::vector<char>> grid{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	const std::string word{"ZBCCED"};
	EXPECT_FALSE(does_word_exist(grid, word));
}

TEST(TestDoesWordExistInGrid, simple3)
{
	std::vector<std::vector<char>> grid{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	const std::string word{"SEE"};
	EXPECT_TRUE(does_word_exist(grid, word));
}

TEST(TestDoesWordExistInGrid, simple4)
{
	std::vector<std::vector<char>> grid{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	const std::string word{"X"};
	EXPECT_FALSE(does_word_exist(grid, word));
}
