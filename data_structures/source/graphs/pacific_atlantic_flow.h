//
// Created by andreas on 06.04.25.
//

#ifndef PACIFIC_ATLANTIC_FLOW_H
#define PACIFIC_ATLANTIC_FLOW_H
// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean.
// The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where
// heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east,
// and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow
// from any cell adjacent to an ocean into the ocean.
// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can
// flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
#include <vector>

bool dfs(std::vector<std::vector<bool>> & ocean, int row, int col, std::vector<std::vector<int>> & heights)
{
  if(row < 0 || row >= heights.size() || col < 0 || col >= heights[row].size() || heights[row][col] > 10000)
    return false;
  if(ocean[row][col])
    return true;
  heights[row][col] = 100000;
   

}


std::vector<std::vector<int>> pacific_atlanctic_flow(std::vector<std::vector<int>> & heights)
{
  int rows = heights.size();
  int columns = heights[0].size();
  std::vector<std::vector<bool>> pacific(rows, std::vector<bool>(columns, false));
  std::vector<std::vector<bool>> atlantic(rows, std::vector<bool>(columns, false));
  for (int row=0; row<rows; ++row){
    pacific[row][0]=true;
    atlantic[row][columns-1]=true;
  }
  for (int col=0; col<columns; ++col){
    pacific[0][col]=true;
    atlantic[rows-1][col]=true;
  }
  std::vector<std::vector<int>> result;
  for (int row=0; row<rows; row++){
    for (int col=0; col<columns; col++){
        if (dfs(pacific,row,col,heights) && dfs(atlantic,row,col,heights))
          result.push_back({row,col});
    }
  }
  return result;


}
#endif //PACIFIC_ATLANTIC_FLOW_H
