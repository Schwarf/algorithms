//
// Created by andreas on 18.04.25.
//

#ifndef ROTTEN_ORANGES_H
#define ROTTEN_ORANGES_H
// You are given an m x n grid where each cell can have one of three values:
//    0 representing an empty cell,
//    1 representing a fresh orange, or
//    2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
#include <vector>
#include <queue>
int rotten_oranges(std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    int columns = grid[0].size();
    std::queue<std::pair<int, int>> rotten;
    int not_rotten_counter{};
    for(int row{}; row< rows; ++row)
    {
        for(int col{}; col< columns; ++col)
        {
            if(grid[row][col] == 2)
            {
                rotten.emplace(row, col);
            }
            if(grid[row][col] == 1)
            {
                not_rotten_counter++;
            }
        }
    }
    if(not_rotten_counter ==0)
        return 0;
    std::vector<std::pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int time{};
    while(!rotten.empty())
    {
        auto size = rotten.size();
        time++;
        for(int i{}; i < size; ++i)
        {
            auto [row, col] = rotten.front();
            rotten.pop();
            for(const auto [x, y]: directions)
            {
                auto new_row = row+ x;
                auto new_col = col+ y;
                if(new_row < 0 || new_row > rows-1 || new_col <0 || new_col > columns-1 || grid[new_row][new_col] == 2 || grid[new_row][new_col] == 0)
                    continue;
                grid[new_row][new_col] = 2;
                rotten.emplace(new_row, new_col);
                not_rotten_counter--;
            }

        }

        if(not_rotten_counter ==0)
            return time;
    }

    return not_rotten_counter ==0 ? time : -1;

}

#endif //ROTTEN_ORANGES_H
