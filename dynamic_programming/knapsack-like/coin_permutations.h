//
// Created by andreas on 11.07.26.
//

#ifndef ALGORITHMS_COIN_PERMUTATIONS_H
#define ALGORITHMS_COIN_PERMUTATIONS_H

// Given a vector of distinct positive integers `coins` and a non-negative integer `target`,
// return the number of ordered sequences of coin values whose sum equals `target`.
// Each coin may be used any number of times.
// Different orders count as different sequences.

// NOTE for the bottom-up solution see the difference between permutations and combinations (see coin_combinations.h)
#include <vector>

int coin_permutations(const std::vector<int>& coins, int amount)
{
    std::vector<long> dp(amount + 1);
    dp[0] = 1;
    for (int t{1}; t <= amount; ++t)
    {
        for (const auto n : coins)
        {
            if (n <= t)
                dp[t] += dp[t - n];
        }
    }
    return dp[amount];
}


#endif // ALGORITHMS_COIN_PERMUTATIONS_H
