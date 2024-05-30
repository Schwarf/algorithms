//
// Created by andreas on 24.11.22.
//

#ifndef SEARCH_WORD_IN_CHARACTER_GRID_H
#define SEARCH_WORD_IN_CHARACTER_GRID_H

#include <vector>
#include <string>
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.


bool dfs(std::vector<std::vector<char>> &board, const std::string &word, int row, int col, int word_index) {
    if (row < 0 || col < 0 || row > board.size() - 1 || col > board[0].size() - 1)
        return false;
    if (board[row][col] != word[word_index] || board[row][col] == '.')
        return false;
    if (word_index == word.size() - 1)
        return true;
    // remember original character
    const auto cache = board[row][col];
    // replace character with invalid character for now to avoid double counting
    board[row][col] = '.';
    const auto doesExist = dfs(board, word, row + 1, col, word_index + 1) ||
                           dfs(board, word, row - 1, col, word_index + 1) ||
                           dfs(board, word, row, col + 1, word_index + 1) ||
                           dfs(board, word, row, col - 1, word_index + 1);
    board[row][col] = cache;
    return doesExist;
}

bool exist(std::vector<std::vector<char>> &board, const std::string &word) {
    for (int row{}; row < board.size(); ++row) {
        for (int col{}; col < board[0].size(); ++col) {
            if (dfs(board, word, row, col, 0))
                return true;
        }
    }
    return false;
}

#endif //SEARCH_WORD_IN_CHARACTER_GRID_H
