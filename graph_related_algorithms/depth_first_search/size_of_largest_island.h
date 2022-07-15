//
// Created by andreas on 15.07.22.
//

#ifndef GRAPH_RELATED_ALGORITHMS_SIZE_OF_LARGEST_ISLAND_H
#define GRAPH_RELATED_ALGORITHMS_SIZE_OF_LARGEST_ISLAND_H
#include <vector>
#include <stack>
#include <utility>
/*
You are given an m x n binary matrix grid, the earth. An island is a group of 1's (representing land)
 connected 4-directionally
 (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.
*/

void dfs_iterative_max_area(std::vector<std::vector<int>> & earth, std::vector<std::vector<bool>> & visited, int & max_area, int row, int column)
{
    if(!earth[row][column])
        return;
    if(visited[row][column])
        return;

    std::stack<std::pair<int, int>> help;
    help.push(std::make_pair(row, column));
    visited[row][column] = true;
    int area{};

    while(!help.empty())
    {
        auto current = help.top();
        help.pop();
        visited[current.first][current.second] = true;
        if((current.first -1  > 0) && earth[current.first-1][current.second])
            help.push(std::make_pair(current.first-1, current.second));
        if((current.first +1  < earth.size()) && earth[current.first+1][current.second])
            help.push(std::make_pair(current.first+1, current.second));
        if((current.second -1 > 0) && earth[current.first][current.second-1])
            help.push(std::make_pair(current.first, current.second-1));
        if((current.second +1  < earth[0].size()) && earth[current.first][current.second+1])
            help.push(std::make_pair(current.first, current.second+1));
    }
    if(area > max_area)
        area=max_area;
}

int size_of_largest_island(std::vector<std::vector<int>> & earth)
{
    int n = earth.size();
    int m = earth[0].size();
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    int max_area{};
    dfs_iterative_max_area(earth, visited, max_area, 0, 0);
}


#endif //GRAPH_RELATED_ALGORITHMS_SIZE_OF_LARGEST_ISLAND_H
