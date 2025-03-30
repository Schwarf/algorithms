//
// Created by andreas on 28.03.25.
//

#ifndef SWIM_IN_WATER_H
#define SWIM_IN_WATER_H
// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
// The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
// Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
#include <vector>
#include <queue>

int swim_in_water(std::vector<std::vector<int>>& grid)
{
    int n = grid.size();
    // 2D visited array to ensure we don't process a cell more than once.
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

    // Priority queue holds tuple: (current_cost, x, y)
    // current_cost = max(grid[x][y] encountered so far along the path.
    using tuple = std::tuple<int, int, int>;
    std::priority_queue<tuple, std::vector<tuple>, std::greater<tuple>> pq;

    pq.push({grid[0][0], 0, 0});
    visited[0][0] = true;

    // Directions: up, down, left, right.
    std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!pq.empty())
    {
        auto [cost, row, column] = pq.top();
        pq.pop();

        // If we reached the target cell, cost is our answer.
        if (row == n - 1 && column == n - 1)
            return cost;

        // Check all 4-directional moves.
        for (auto& [x, y] : directions)
        {
            int new_row = row + x;
            int new_column = column + y;
            // Check boundaries.
            if (new_row >= 0 && new_row < n && new_column >= 0 && new_column < n && !visited[new_row][new_column])
            {
                visited[new_row][new_column] = true;
                // The cost to move to neighbor is the maximum of the current path cost and neighbor's elevation.
                int new_cost = std::max(cost, grid[new_row][new_column]);
                pq.push({new_cost, new_row, new_column});
            }
        }
    }
    return -1; // Should never happen given problem constraints.
}
#endif //SWIM_IN_WATER_H
