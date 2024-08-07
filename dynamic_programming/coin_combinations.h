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

int coin_combinations_recursive(const std::vector<int> &coins, int amount, int index = 0) {
    if (amount == 0) {
        return 1;
    }
    if (amount < 0 || index >= coins.size()) {
        return 0;
    }
    int include_current_coin = coin_combinations_recursive(coins, amount - coins[index], index);
    int exclude_current_coin = coin_combinations_recursive(coins, amount, index + 1);
    return include_current_coin + exclude_current_coin;
}

int coin_combinations_recursive2(const std::vector<int> &coins, int amount, int index = 0) {
    if (amount < 0)
        return 0;
    if (amount == 0)
        return 1;
    int result{};
    for (int i{index}; i < coins.size(); ++i) {
        result += coin_combinations_recursive2(coins, amount - coins[i], i);
    }
    return result;
}


int memoization(const std::vector<int> &coins, int amount, std::vector<std::vector<int>> &memo, int index) {
    if (amount < 0 || index >= coins.size()) {
        return 0;
    }
    if (memo[index][amount] != -1)
        return memo[index][amount];
    if (amount == 0)
        return 1;
    int include_current_coin = memoization(coins, amount - coins[index], memo, index);
    int exclude_current_coin = memoization(coins, amount, memo, index + 1);
    memo[index][amount] = include_current_coin + exclude_current_coin;
    return memo[index][amount];
}

int memoization2(const std::vector<int> &coins, std::vector<int> &memo, int amount, int index = 0) {
    if (amount < 0)
        return 0;
    if (amount == 0)
        return 1;
    if (memo[amount * coins.size() + index] != -1)
        return memo[amount * coins.size() + index];
    int result{};
    for (int i{index}; i < coins.size(); ++i) {
        result += coin_combinations_recursive2(coins, amount - coins[i], i);
    }
    memo[amount * coins.size() + index] = result;
    return result;
}

int coin_combinations_top_down2(const std::vector<int> &coins, int amount, int index = 0) {
    std::vector<int> memo(coins.size() * (amount + 1), -1);
    return memoization2(coins, memo, amount, index);
}


int coin_combinations_top_down(const std::vector<int> &coins, int amount, int index = 0) {
    std::vector<std::vector<int>> memo(coins.size(), std::vector<int>(amount + 1, -1));
    return memoization(coins, amount, memo, index);
}

int coin_combinations_bottom_up(const std::vector<int> &coins, int amount) {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (const auto &coin: coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}


#endif //COIN_COMBINATIONS_H
