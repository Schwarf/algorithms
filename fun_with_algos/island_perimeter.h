//
// Created by andreas on 20.04.24.
//

#ifndef FUN_WITH_ALGOS_ISLAND_PERIMETER_H
#define FUN_WITH_ALGOS_ISLAND_PERIMETER_H
// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water,
// and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island.
// One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. \
// Determine the perimeter of the island.
#include <vector>

int island_perimeter(const std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int columns = grid[0].size();
    int perimeter{};
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (grid[i][j] == 1) {
                // top
                if (i == 0 || grid[i - 1][j] == 0) perimeter++;
                // bottom
                if (i == rows - 1 || grid[i + 1][j] == 0) perimeter++;
                // left
                if (j == 0 || grid[i][j - 1] == 0) perimeter++;
                // right
                if (j == columns - 1 || grid[i][j + 1] == 0) perimeter++;
            }
        }
    }
    return perimeter;
}

#endif //FUN_WITH_ALGOS_ISLAND_PERIMETER_H
