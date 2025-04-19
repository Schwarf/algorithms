//
// Created by andreas on 19.04.25.
//
#include "./../search_word_in_character_grid.h"
#include "gtest/gtest.h"

TEST(TestSearchWordInCharacterGrid, simple1)
{
    std::vector<std::vector<char>> grid = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word = "ABCCED";
    EXPECT_TRUE(search_word_character_grid(grid, word));
}

TEST(TestSearchWordInCharacterGrid, simple2)
{
    std::vector<std::vector<char>> grid = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word = "SEE";
    EXPECT_TRUE(search_word_character_grid(grid, word));
}

TEST(TestSearchWordInCharacterGrid, simple3)
{
    std::vector<std::vector<char>> grid = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    std::string word = "ABAC";
    EXPECT_FALSE(search_word_character_grid(grid, word));
}
