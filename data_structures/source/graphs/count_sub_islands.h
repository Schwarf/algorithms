//
// Created by andreas on 31.08.24.
//

#ifndef DATA_STRUCTURES_COUNT_SUB_ISLANDS_H
#define DATA_STRUCTURES_COUNT_SUB_ISLANDS_H
// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water)
// and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical).
// Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all
// the cells that make up this island in grid2.  Return the number of islands in grid2 that are considered sub-islands.
#include <vector>
#include <queue>
#include <stack>

bool bfs(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2,
         std::vector<std::vector<bool>>& visited, int row, int col)
{
    int rows = grid1.size();
    int columns = grid1[0].size();
    int directions[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    visited[row][col] = true;
    std::queue<std::pair<int, int>> q;
    q.emplace(row, col);
    bool answer = true;
    while (!q.empty())
    {
        auto [c_row, c_col] = q.front();
        q.pop();
        if (!grid1[c_row][c_col])
            answer = false;

        for (auto& direction : directions)
        {
            int x = c_row + direction[0];
            int y = c_col + direction[1];
            if (x > -1 && y > -1 && x < rows && y < columns &&
                !visited[x][y] && grid2[x][y])
            {
                q.emplace(x, y);
                visited[x][y] = true;
            }
        }
    }
    return answer;
}


int count_sub_islands_bfs(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2)
{
    int rows = grid1.size();
    int columns = grid1[0].size();
    int count{};
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns));
    for (int row{}; row < rows; ++row)
    {
        for (int col{}; col < columns; ++col)
        {
            if (visited[row][col])
                continue;
            if (grid2[row][col] && bfs(grid1, grid2, visited, row, col))
            {
                count++;
            }
        }
    }
    return count;
}


bool dfs(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2,
         std::vector<std::vector<bool>>& visited, int row, int col)
{
    int rows = grid1.size();
    int columns = grid1[0].size();
    int directions[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    visited[row][col] = true;
    std::stack<std::pair<int, int>> q;
    q.emplace(row, col);
    bool answer = true;
    while (!q.empty())
    {
        auto [c_row, c_col] = q.top();
        q.pop();
        if (!grid1[c_row][c_col])
            answer = false;

        for (auto& direction : directions)
        {
            int x = c_row + direction[0];
            int y = c_col + direction[1];
            if (x > -1 && y > -1 && x < rows && y < columns &&
                !visited[x][y] && grid2[x][y])
            {
                q.emplace(x, y);
                visited[x][y] = true;
            }
        }
    }
    return answer;
}


int count_sub_islands_dfs(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2)
{
    int rows = grid1.size();
    int columns = grid1[0].size();
    int count{};
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns));
    for (int row{}; row < rows; ++row)
    {
        for (int col{}; col < columns; ++col)
        {
            if (visited[row][col])
                continue;
            if (grid2[row][col] && dfs(grid1, grid2, visited, row, col))
            {
                count++;
            }
        }
    }
    return count;
}

#endif //DATA_STRUCTURES_COUNT_SUB_ISLANDS_H
