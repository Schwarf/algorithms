//
// Created by andreas on 29.03.25.
//

#ifndef SHORTEST_PATH_IN_GRID_WITH_OBSTACLES_H
#define SHORTEST_PATH_IN_GRID_WITH_OBSTACLES_H

// I have a binary m x n grid. A 0 represents a free tile while a 1 represents an obstacle.
// I also provide the coordinates of a source and a target tile.
// Now I want to check if I can reach the target tile and if so in how many steps given that
// I can move up,down,left and right. If it is not possible return -1.
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>


int manhattan_distance(int x1, int y1, int x2, int y2)
{
    return std::abs(x1 - x2) + abs(y1 - y2);
}

// AStar
int shortest_path_in_grid_with_obstacles(const std::vector<std::vector<int>>& grid, std::pair<int, int> source,
                                         std::pair<int, int> target)
{
    int rows = grid.size();
    if (rows == 0)
        return -1;

    int columns = grid[0].size();
    if (columns == 0)
        return -1;

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));

    auto [source_row, source_column] = source;
    auto [target_row, target_column] = target;

    if (grid[source_row][source_column] == 1 || grid[target_row][target_column] == 1)
        return -1;

    // min-heap: (f = g + h, g, x, y)
    using State = std::tuple<int, int, int, int>;
    std::priority_queue<State, std::vector<State>, std::greater<>> pq;
    pq.emplace(manhattan_distance(source_row, source_column, target_row, target_column), 0, source_row, source_column);
    visited[source_row][source_column] = true;
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty())
    {
        auto [total_estimate, steps, row, column] = pq.top();
        pq.pop();

        if (row == target_row && column == target_column)
            return steps;

        for (auto [x, y] : directions)
        {
            auto new_row = row + x;
            auto new_column = column + y;

            if (new_row >= 0 && new_column >= 0 && new_row < rows && new_column < columns &&
                grid[new_row][new_column] == 0 && !visited[new_row][new_column])
            {
                int new_steps = steps + 1;
                int heuristic = manhattan_distance(new_row, new_column, target_row, target_column);
                visited[new_row][new_column] = true;
                pq.emplace(new_steps + heuristic, new_steps, new_row, new_column);

            }
        }
    }

    return -1;
}

// BFS
int shortest_path_in_grid_with_obstacles_bfs(const std::vector<std::vector<int>>& grid,
                                             const std::pair<int, int>& start,
                                             const std::pair<int, int>& end)
{
    int rows = grid.size();
    if (rows == 0)
        return -1;

    int columns = grid[0].size();
    if (columns == 0)
        return -1;

    auto [start_row, start_col] = start;
    auto [end_row, end_col] = end;

    if (grid[start_row][start_col] != 0 || grid[end_row][end_col] != 0)
        return -1;

    std::queue<std::tuple<int, int, int>> q;
    q.emplace(start_row, start_col, 0);

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
    visited[start_row][start_col] = true;

    const std::vector<std::pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty())
    {
        auto [row, column, steps] = q.front();
        q.pop();

        if (row == end_row && column == end_col)
        {
            return steps;
        }

        for (const auto& [x, y] : directions)
        {
            int new_row = row + x;
            int new_column = column + y;
            if (new_row >= 0 && new_row < rows &&
                new_column >= 0 && new_column < columns &&
                !visited[new_row][new_column] &&
                grid[new_row][new_column] == 0)
            {
                visited[new_row][new_column] = true;
                q.emplace(new_row, new_column, steps + 1);
            }
        }
    }

    return -1; // No path found
}


#endif //SHORTEST_PATH_IN_GRID_WITH_OBSTACLES_H
