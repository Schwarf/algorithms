//
// Created by andreas on 13.08.23.
//

#ifndef UNIQUE_PATHS_WITH_OBSTACLES_H
#define UNIQUE_PATHS_WITH_OBSTACLES_H
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
// The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can
// take to reach the bottom-right corner.
//The test cases are generated so that the answer will be less than or equal to 2 * 109.
#include <vector>

int unique_paths_with_obstacles_recursive(const std::vector<std::vector<int>> &matrix, int row = 0, int col = 0)
{
	// We initialize with 1 because at least one path exists from each position
	if (row > matrix.size() - 1 || col > matrix[0].size() - 1)
		return 0;
	if (matrix[row][col] == 1)
		return 0;
	if (row == matrix.size() - 1 && col == matrix[0].size() - 1)
		return 1;
	return unique_paths_with_obstacles_recursive(matrix, row + 1, col)
		+ unique_paths_with_obstacles_recursive(matrix, row, col + 1);
}
/*
int top_down(const std::vector<std::vector<int>> &matrix, int row, int col, std::vector<std::vector<int>> &memo)
{
	if (matrix[row][col] == 1)
		return 0;
	if (row == 1 || col == 1)
		return 1;
	if(memo[row][col] != -1)

	return unique_paths_with_obstacles_recursive(matrix, row - 1, col)
		+ unique_paths_with_obstacles_recursive(matrix, row, col - 1);

}

int unique_paths_with_obstacles_top_down(const std::vector<std::vector<int>> &matrix, int row, int col)
{
	int rows
	std::vector<std::vector<int>> memo(rows + 1, std::vector<int>(columns + 1, -1));
	return top_down(matrix, rows, columns, memo);
}

int unique_paths_with_obstacles_bottom_up(int rows, int columns)
{
	// We initialize with 1 because at least one path exists from each position
	std::vector<std::vector<int>> dp(rows, std::vector<int>(columns, 1));
	for (int row{1}; row < rows; ++row) {
		for (int col{1}; col < columns; ++col) {
			dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
		}
	}
	return dp[rows - 1][columns - 1];
}

int unique_paths_with_obstacles_bottom_up_optimized(int rows, int columns)
{
	// We initialize with 1 because at least one path exists from each position
	std::vector<int> dp(rows, 1);
	for (int col{1}; col < columns; ++col) {
		for (int row{1}; row < rows; ++row) {
			dp[row] += dp[row - 1];
		}
	}
	return dp[rows - 1];
}

*/
#endif //unique_paths_with_obstacles_WITH_OBSTACLES_H
