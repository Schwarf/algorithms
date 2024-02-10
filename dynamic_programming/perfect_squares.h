//
// Created by andreas on 22.11.22.
//

#include <vector>
#include <iostream>
// Given an integer n, return the least number of perfect square numbers needed that sum to n.
// perfect squares: 1, 4, 9, 16,
// https://leetcode.com/problems/perfect-squares/discuss/2837605/Complete-Intuition-Explained-oror-Recursion-greaterMemo-greaterDP


int number_of_perfect_square_summands_needed_recursive(int target)
{
	if (target == 0)
		return 0;
	int min_summands{target};
	for (int i{1}; i * i <= target; ++i) {
		min_summands = std::min(min_summands, 1 + number_of_perfect_square_summands_needed_recursive(target - i * i));
	}
	return min_summands;
}

int memoization(int target, std::vector<int> &memo)
{
	if (target == 0)
		return 0;
	int min_summands{target};
	if (memo[target] != -1)
		return memo[target];
	for (int i{1}; i * i <= target; ++i) {
		min_summands = std::min(min_summands, 1 + memoization(target - i * i, memo));
	}
	memo[target] = min_summands;
	return min_summands;
}

int number_of_perfect_square_summands_needed_top_down(int target)
{
	std::vector<int> memo(target + 1, -1);
	return memoization(target, memo);
}

int number_of_perfect_square_summands_needed(int target)
{
	// in this vector we count the number of perfect squares for all number until the target number
	std::vector<int> dp(target + 1, target);
	dp[0] = 0;
	for (int i = 1; i <= target; ++i)
		for (int j{}; j * j <= i; ++j)
			dp[i] = std::min(dp[i], dp[i - j * j] + 1); // We subtract perfect squares from i
	return dp[target];
}
