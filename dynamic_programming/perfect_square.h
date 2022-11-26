//
// Created by andreas on 22.11.22.
//

#include <vector>
#include <iostream>
// Given an integer n, return the least number of perfect square numbers needed that sum to n.
// perfect squares: 1, 4, 9, 16,
// https://leetcode.com/problems/perfect-squares/discuss/2837605/Complete-Intuition-Explained-oror-Recursion-greaterMemo-greaterDP
int number_of_perfect_square_summands_needed(int target)
{
	std::vector<int> dp(target + 1, 1000000);
	dp[0] = 0;
	for (int i = 1; i <= target; ++i)
		for (int j{}; j * j <= i; ++j)
			dp[i] = std::min(dp[i], dp[i - j * j] + 1); // We subtract perfect squares from i
	return dp[target];
}
