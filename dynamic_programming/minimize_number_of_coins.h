
//
// Created by andreas on 09.07.23.
//

#ifndef MINIMIZE_NUMBER_OF_COINS_H
#define MINIMIZE_NUMBER_OF_COINS_H
// Given a set of coins and an amount find the minimal number of coins to get the amount
#include <vector>


int minimize_number_of_coins(const std::vector<int> &coins, int amount)
{
	if (amount == 0)
		return 0;
	int number_of_coins{amount + 1};
	for (const auto &coin: coins) {
		if (amount >= coin) {
			auto sub_count = std::min(number_of_coins, minimize_number_of_coins(coins, amount - coin));
			if (sub_count != -1)
				number_of_coins = std::min(number_of_coins, 1 + sub_count);
		}
	}
	return number_of_coins == amount + 1 ? -1 : number_of_coins;
}

int minimize_top_down(const std::vector<int> &coins, int amount, std::vector<int> &memo)
{
	if (memo[amount] != -1)
		return memo[amount];
	if (amount == 0)
		return 0;
	int number_of_coins{amount + 1};
	for (const auto &coin: coins) {
		if (amount >= coin) {
			auto sub_count = std::min(number_of_coins, minimize_top_down(coins, amount - coin, memo));
			if (sub_count != -1)
				number_of_coins = std::min(number_of_coins, 1 + sub_count);
		}
	}
	memo[amount] = number_of_coins != amount + 1 ? number_of_coins : -1;
	return memo[amount];
}

int minimize_number_of_coins_top_down(const std::vector<int> &coins, int amount)
{
	std::vector<int> memo(amount + 1, -1);
	return minimize_top_down(coins, amount, memo);
}

// Bottom up or tabulation approach
int minimize_number_of_coins_bottom_up(const std::vector<int> &coins, int amount)
{
	if (amount == 0)
		return 0;
	std::vector<int> dp(amount + 1, amount + 1);
	for (const auto &coin: coins) {
		if (coin <= amount)
			dp[coin] = 1;
	}
	for (int i{1}; i <= amount; ++i) {
		for (const auto &coin: coins) {
			if (coin <= i)
				dp[i] = std::min(dp[i], 1 + dp[i - coin]);
		}
	}
	return dp[amount] == amount + 1 ? -1 : dp[amount];
}

#endif //MINIMIZE_NUMBER_OF_COINS_H
