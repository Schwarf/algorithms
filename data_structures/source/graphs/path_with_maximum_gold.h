//
// Created by andreas on 20.05.24.
//

#ifndef DATA_STRUCTURES_PATH_WITH_MAXIMUM_GOLD_H
#define DATA_STRUCTURES_PATH_WITH_MAXIMUM_GOLD_H
// In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in
// that cell, 0 if it is empty.
// Return the maximum amount of gold you can collect under the conditions:
// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.
#include <vector>

template<typename T>
requires std::is_arithmetic_v<T>
T dfs_backtrack(std::vector<std::vector<T>> &grid, int row, int col, int rows, int columns) {
    const std::vector<int> directions{0, 1, 0, -1, 0};
    if (row < 0 || col < 0 || row > rows - 1 || col > columns - 1 || grid[row][col] == 0)
        return T{};

    T gold{};
    auto original_value = grid[row][col];
    grid[row][col] = T{};
    for (int direction{}; direction < 4; direction++) {
        gold = std::max(gold, dfs_backtrack(grid, row + directions[direction], col + directions[direction + 1],
                                            rows, columns));
    }
    // backtrack
    grid[row][col] = original_value;
    return gold + original_value;
}


template<typename T>
requires std::is_arithmetic_v<T>
T path_with_maximum_gold(std::vector<std::vector<T>> &grid) {
    int rows = grid.size();
    int columns = grid[0].size();
    T max{};
    for (int row{}; row < rows; ++row) {
        for (int col{}; col < columns; ++col) {
            max = std::max(max, dfs_backtrack(grid, row, col, rows, columns));
        }
    }
    return max;
}

#endif //DATA_STRUCTURES_PATH_WITH_MAXIMUM_GOLD_H
