//
// Created by andreas on 13.08.23.
//

#ifndef UNIQUE_PATHS_H
#define UNIQUE_PATHS_H
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
// The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can
// take to reach the bottom-right corner.
//The test cases are generated so that the answer will be less than or equal to 2 * 109.
#include <vector>

int unique_paths_recursive(int rows, int columns)
{
	// We initialize with 1 because at least one path exists from each position
	if (rows == 1 || columns == 1)
		return 1;
	return unique_paths_recursive(rows - 1, columns) + unique_paths_recursive(rows, columns - 1);
}

int top_down(int rows, int columns, std::vector<std::vector<int>> &memo)
{
	if (rows == 1 || columns == 1)
		return 1;
	if (memo[rows][columns] != 0)
		return memo[rows][columns];
	memo[rows][columns] = top_down(rows - 1, columns, memo) + top_down(rows, columns - 1, memo);
	return memo[rows][columns];

}

int unique_paths_top_down(int rows, int columns)
{
	std::vector<std::vector<int>> memo(rows + 1, std::vector<int>(columns + 1, 0));
	return top_down(rows, columns, memo);
}

int unique_paths_bottom_up(int rows, int columns)
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

int unique_paths_bottom_up_optimized(int rows, int columns)
{
	// We initialize with 1 because at least one path exists from each position
	std::vector<int> dp(rows, 1);
	for (int row{1}; row < rows; ++row) {
		for (int col{1}; col < columns; ++col) {
			dp[col] += dp[col - 1];
		}
	}
	return dp[rows - 1];
}


#endif //UNIQUE_PATHS_H
