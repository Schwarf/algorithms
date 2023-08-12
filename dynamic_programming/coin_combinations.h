//
// Created by andreas on 11.08.23.
//

#ifndef COIN_COMBINATIONS_H
#define COIN_COMBINATIONS_H
// You are given an integer array coins representing coins of different denominations and an integer amount
// representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any
// combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.
#include <vector>
#include <limits>
int coin_combinations_recursive(const std::vector<int> &coins, int amount)
{
	if (amount == 0) return 0;
	int combinations = std::numeric_limits<int>::max();

	for (int coin: coins) {
		if (amount - coin >= 0) {
			int result = coin_combinations_recursive(coins, amount - coin);
			if (result != -1)
				combinations = std::min(combinations, result + 1);
		}
	}

	return (combinations == std::numeric_limits<int>::max()) ? -1 : combinations;
}

int top_down(const std::vector<int> &coins, int amount, std::vector<int> &memo)
{
	if (amount == 0) return 0;
	if (memo[amount] != -2) return memo[amount];

	int combinations = std::numeric_limits<int>::max();

	for (int coin: coins) {
		if (amount - coin >= 0) {
			int result = top_down(coins, amount - coin, memo);
			if (result != -1)
				combinations = std::min(combinations, result + 1);
		}
	}

	memo[amount] = (combinations == std::numeric_limits<int>::max()) ? -1 : combinations;
	return memo[amount];
}

int coin_combinations_top_down(const std::vector<int> &coins, int amount)
{
	std::vector<int> memo(amount + 1, -2); // -2 represents not calculated
	return top_down(coins, amount, memo);
}

int coin_combinations_bottom_up(const std::vector<int> &coins, int amount)
{
	std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
	dp[0] = 0;

	for (int i = 1; i <= amount; ++i) {
		for (int coin: coins) {
			if (i - coin >= 0 && dp[i - coin] != std::numeric_limits<int>::max())
				dp[i] = std::min(dp[i], dp[i - coin] + 1);
		}
	}

	return (dp[amount] == std::numeric_limits<int>::max()) ? -1 : dp[amount];
}


#endif //COIN_COMBINATIONS_H
