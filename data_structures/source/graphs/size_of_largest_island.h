//
// Created by andreas on 15.07.22.
//

#ifndef GRAPH_RELATED_ALGORITHMS_SIZE_OF_LARGEST_ISLAND_H
#define GRAPH_RELATED_ALGORITHMS_SIZE_OF_LARGEST_ISLAND_H

#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

/*
You are given an m x n binary matrix grid, the quadrant_map. An island is a group of 1's (representing land)
 connected 4-directionally
 (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.
*/

void
dfs_iterative_max_area(std::vector<std::vector<int>>& quadrant_map, std::vector<std::vector<bool>>& visited,
                       int& max_area,
                       int row, int column)
{
    if (!quadrant_map[row][column])
        return;
    if (visited[row][column])
        return;

    std::stack<std::pair<int, int>> help;
    help.push(std::make_pair(row, column));
    int area{};

    while (!help.empty())
    {
        auto current = help.top();
        help.pop();
        if (visited[current.first][current.second])
            continue;
        if ((current.first - 1 > -1) && quadrant_map[current.first - 1][current.second])
            help.push(std::make_pair(current.first - 1, current.second));
        if ((current.first + 1 < quadrant_map.size()) && quadrant_map[current.first + 1][current.second])
            help.push(std::make_pair(current.first + 1, current.second));
        if ((current.second - 1 > -1) && quadrant_map[current.first][current.second - 1])
            help.push(std::make_pair(current.first, current.second - 1));
        if ((current.second + 1 < quadrant_map[0].size()) && quadrant_map[current.first][current.second + 1])
            help.push(std::make_pair(current.first, current.second + 1));
        visited[current.first][current.second] = true;
        area++;
    }
    if (area > max_area)
        max_area = area;
}

int size_of_largest_island(std::vector<std::vector<int>>& quadrant_map)
{
    int n = quadrant_map.size();
    int m = quadrant_map[0].size();
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    int max_area{};
    for (int row = 0; row < quadrant_map.size(); ++row)
    {
        for (int column = 0; column < quadrant_map[0].size(); ++column)
        {
            dfs_iterative_max_area(quadrant_map, visited, max_area, row, column);
        }
    }
    return max_area;
}


int dfs_recursive_max_area(std::vector<std::vector<int>>& quadrant_map, int row, int column)
{
    if (row < 0 || row > quadrant_map.size() - 1 || column < 0 || column > quadrant_map[0].size() - 1)
        return 0;
    if (!quadrant_map[row][column])
        return 0;
    quadrant_map[row][column] = 0;
    return 1 + dfs_recursive_max_area(quadrant_map, row + 1, column) + dfs_recursive_max_area(
            quadrant_map, row - 1, column) +
        dfs_recursive_max_area(quadrant_map, row, column - 1) + dfs_recursive_max_area(quadrant_map, row, column + 1);
}

int size_of_largest_island_recursive(std::vector<std::vector<int>>& quadrant_map)
{
    int n = quadrant_map.size();
    int m = quadrant_map[0].size();
    int max_area{};
    int area{};
    for (int row = 0; row < n; ++row)
        for (int column = 0; column < m; ++column)
        {
            if (quadrant_map[row][column])
                area = dfs_recursive_max_area(quadrant_map, row, column);

            max_area = std::max(max_area, area);
        }
    return max_area;
}

#endif //GRAPH_RELATED_ALGORITHMS_SIZE_OF_LARGEST_ISLAND_H
