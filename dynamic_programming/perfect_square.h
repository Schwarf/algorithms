//
// Created by andreas on 22.11.22.
//

#include <vector>
// Given an integer n, return the least number of perfect square numbers needed that sum to n.
// perfect squares: 1, 4, 9, 16,
// https://leetcode.com/problems/perfect-squares/discuss/2837605/Complete-Intuition-Explained-oror-Recursion-greaterMemo-greaterDP
int number_of_perfect_square_summands_needed(int target)
{
	std::vector<int> dp(target+1, target);
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2; i <= target; ++target)
		for(int j = 1; j < i*i; ++j)
			dp[i] = std::min(dp[i], dp[i-j*j] + 1); // We subtract perfect squares from i
	return dp[target];
}
