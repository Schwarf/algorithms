//
// Created by andreas on 09.01.24.
//

#ifndef COUNT_UNIQUE_BINARY_SEARCH_TREES_H
#define COUNT_UNIQUE_BINARY_SEARCH_TREES_H
#include <vector>
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes
// of unique values from 1 to n.
// For n=1,3 the numbers are 1 and 5

int count_unique_BST_recursive(int n)
{
	if (n == 0 || n == 1)
		return 1;

	int count{};
	for (int i{1}; i <= n; ++i) {
// The key observation is for a binary search: If you pick a number i with 1 <= i <= n as root-value then the left tree
// has i-1 values (1.. i-1) and the right tree has n-i values (i+1..n). Now since each value between 1..n can be the
// root value we multiply the number of left-values and right-values for each i and add them up.
		count += count_unique_BST_recursive(i - 1) * count_unique_BST_recursive(n - i);
	}
	return count;
}

int memoization(int n, std::vector<int> &memo)
{
	if (memo[n] != 0)
		return memo[n];
	int count{};
	for (int i{1}; i <= n; ++i) {
		count += memoization(i - 1, memo) * memoization(n - i, memo);
	}
	return count;

}

int count_unique_BST_top_down(int n)
{
	std::vector<int> memo(n + 1, 0);
	memo[0] = 1;
	memo[1] = 1;
	return memoization(n, memo);
}

int count_unique_BST_bottom_up(int n)
{
	std::vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i{2}; i <= n; ++i) {
		for (int j{1}; j <= i; ++j) {
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}


#endif //COUNT_UNIQUE_BINARY_SEARCH_TREES_H
