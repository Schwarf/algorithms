//
// Created by andreas on 03.04.24.
//

#ifndef DOES_WORD_EXIST_IN_GRID_H
#define DOES_WORD_EXIST_IN_GRID_H
#include <vector>
#include <string>

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells
// are horizontally or vertically neighboring. The same letter cell may not be used more than once.

bool dfs(std::vector<std::vector<char>>& grid, const std::string& word, int row, int col, int word_index)
{
    if (row < 0 || col < 0 || row > grid.size() - 1 || col > grid[0].size() - 1)
        return false;
    if (grid[row][col] != word[word_index] || grid[row][col] == '.')
        return false;
    if (word_index == word.size() - 1)
        return true;
    // remember original character
    const auto original_char = grid[row][col];
    // replace character with invalid character for now to avoid double counting
    grid[row][col] = '.';
    const auto does_exist = dfs(grid, word, row + 1, col, word_index + 1) ||
        dfs(grid, word, row - 1, col, word_index + 1) ||
        dfs(grid, word, row, col + 1, word_index + 1) ||
        dfs(grid, word, row, col - 1, word_index + 1);
    // restore grid for next search
    grid[row][col] = original_char;
    return does_exist;
}

bool does_word_exist(std::vector<std::vector<char>>& grid, const std::string& word)
{
    for (int row{}; row < grid.size(); ++row)
    {
        for (int col{}; col < grid[0].size(); ++col)
        {
            if (grid[row][col] != word[0])
                continue;
            if (dfs(grid, word, row, col, 0))
                return true;
        }
    }
    return false;
}

#endif //DOES_WORD_EXIST_IN_GRID_H
