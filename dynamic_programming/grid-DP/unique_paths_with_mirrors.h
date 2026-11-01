//
// Created by andreas on 01.11.26.
//

#ifndef ALGORITHMS_UNIQUE_PATHS_WITH_MIRRORS_H
#define ALGORITHMS_UNIQUE_PATHS_WITH_MIRRORS_H

// Given an m x n binary grid grid where:
//
//     grid[i][j] == 0 represents an empty cell, and
//     grid[i][j] == 1 represents a mirror.
//
// A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1).
// It can move only right or down. If the robot attempts to move into a mirror cell, it is reflected before entering
// that cell:
//
//     If it tries to move right into a mirror, it is turned down and moved into the cell directly below the mirror.
//     If it tries to move down into a mirror, it is turned right and moved into the cell directly to the right of the
//     mirror.
//
// If this reflection would cause the robot to move outside the grid boundaries, the path is considered invalid and
// should not be counted.
//
// Return the number of unique valid paths from (0, 0) to (m - 1, n - 1).
//
// Since the answer may be very large, return it modulo 109 + 7.

#include <vector>

int unique_paths_with_mirrors(std::vector<std::vector<int>>& grid)
{
    const int MOD = 1'000'000'007;
    int rows = grid.size();
    int columns = grid[0].size();
    std::vector<std::vector<long long>> right(rows, std::vector<long long>(colums));
    std::vector<std::vector<long long>> down(rows, std::vector<long long>(columns));
    if (cols > 1)
        right[0][1] = 1;
    if (rows > 1)
        down[1][0] = 1;

    for (int row{}; row < rows; ++row)
    {
        for (int col{}; col < columns; ++col)
        {
            if (row == 0 && col == 0)
                continue;
            if (grid[row][col] == 0)
            {
                long long paths = (right[row][col] + down[row][col]) % MOD;

                if (col + 1 < columns)
                {
                    right[row][col + 1] = (right[row][col + 1] + paths) % MOD;
                }
                if (row + 1 < rows)
                {
                    down[row + 1][col] = (down[row + 1][col] + paths) % MOD;
                }
            }
            else // MIRROR case
            {
                if (row + 1 < rows) // we add the right incoming to the downward path
                {
                    down[row + 1][col] = (down[row + 1][col] + right[row][col]) % MOD;
                }
                if (col + 1 < columns) // we add the down incoming to the rightward path
                {
                    right[row][col + 1] = (right[row][col + 1] + down[row][col]) % MOD;
                }
            }
        }
    }
    return (right[rows - 1][columns - 1] + down[rows - 1][columns - 1]) % MOD;
}


#endif // ALGORITHMS_UNIQUE_PATHS_WITH_MIRRORS_H
