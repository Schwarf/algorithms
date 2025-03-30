//
// Created by andreas on 20.04.24.
//

#ifndef DATA_STRUCTURES_NUMBER_OF_ISLANDS_H
#define DATA_STRUCTURES_NUMBER_OF_ISLANDS_H
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.
#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int row, int col)
{
    int n = grid.size();
    int m = grid[0].size();
    if (row > n - 1 || col > m - 1 || row < 0 || col < 0)
        return;
    if (grid[row][col] == '0')
        return;
    // Mark as visited by setting the tile to '0'
    grid[row][col] = '0';
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}


int number_of_islands(std::vector<std::vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int number{};
    for (int i{}; i < n; ++i)
    {
        for (int j{}; j < m; ++j)
        {
            if (grid[i][j] == '1')
            {
                number++;
                dfs(grid, i, j);
            }
        }
    }
    return number;
}

#endif //DATA_STRUCTURES_NUMBER_OF_ISLANDS_H
