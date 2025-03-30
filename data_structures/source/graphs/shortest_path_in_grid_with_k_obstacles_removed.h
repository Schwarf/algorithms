//
// Created by andreas on 10.01.25.
//

#ifndef SHORTEST_PATH_IN_GRID_WITH_OBSTACLES_H
#define SHORTEST_PATH_IN_GRID_WITH_OBSTACLES_H

// You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle).
// You can move up, down, left, or right from and to an empty cell in one step.
// Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1)
// given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
#include <queue>
#include <vector>
// Use BFS
int shortest_path_with_k_obstactles_removed(std::vector<std::vector<int>> grid, int k)
{
    int rows = grid.size(), columns = grid[0].size();
    if(rows == 0 || columns == 0)
        return -1;
    // If the grid is only one cell, it's already the destination.
    if(rows == 1 && columns == 1)
        return 0;

    // 3D visited vector: visited[i][j][r] indicates whether cell (i, j) has been visited with r remaining eliminations
    std::vector<std::vector<std::vector<bool>>> visited(rows, std::vector<std::vector<bool>>(columns, std::vector<bool>(k + 1, false)));
    // Queue for BFS: each element is (i, j, remaining, steps)
    std::queue<std::tuple<int, int, int, int>> queue;
    queue.push({0, 0, k, 0});
    visited[0][0][k] = true;
    std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!queue.empty()) {
        auto [row, column, obstacles, steps] = queue.front();
        queue.pop();

        // Check if we've reached the target.
        if (row == rows - 1 && column == columns - 1)
            return steps;

        // Explore all 4 directions.
        for (auto [x, y] : directions) {
            int new_row = row + x;
            int new_column = column + y;

            // Skip out-of-bound cells.
            if (new_row < 0 || new_row >= rows || new_column < 0 || new_column >= columns)
                continue;

            int new_obstacles = obstacles;
            // If the cell is an obstacle:
            if (grid[new_row][new_column] == 1) {
                if (new_obstacles > 0)
                    new_obstacles--;
                else
                    continue; // Can't eliminate any more obstacles.
            }

            // If this state hasn't been visited, add it to the queue.
            if (!visited[new_row][new_column][new_obstacles]) {
                visited[new_row][new_column][new_obstacles] = true;
                queue.push({new_row, new_column, new_obstacles, steps + 1});
            }
        }
    }

    // No valid path found.
    return -1;
}

#endif //SHORTEST_PATH_IN_GRID_WITH_OBSTACLES_H
