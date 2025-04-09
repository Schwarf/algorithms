//
// Created by andreas on 18.06.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_CUTTING_ROD_PROBLEM_H
#define DYNAMIC_PROGRAMMING_SAMPLES_CUTTING_ROD_PROBLEM_H

// Kerling Enterprises buys long steel rods and cuts them into shorter rods, which it then sells. Each cut is free.
// The management of Kerling Enterprises wants to know the best way to cut up the rods.
// Given a rod of a certain length, and list of prices where a rod of length i provides the price
// prices[i] obtain the maximum total price for the rod. Cutting is free.

#include <vector>

int cutting(std::vector<int> &prices, int current_length) {
    if (current_length == 0)
        return 0;
    int value{};
    for (int cut_length{1}; cut_length <= current_length; ++cut_length) {
        int price = (cut_length < prices.size()) ? prices[cut_length] : 0;
        value = std::max(value, price + cutting(prices, current_length - cut_length));
    }
    return value;
}

int rod_cutting(std::vector<int> &prices, int rod_length) {
    return cutting(prices, rod_length);
}


int cutting_memo(std::vector<int> &prices, std::vector<int> &memo, int current_length) {
    if (current_length == 0)
        return 0;
    if (memo[current_length] != -1)
        return memo[current_length];
    int value{};
    for (int cut_length{1}; cut_length <= current_length; ++cut_length) {
        int price = (cut_length < prices.size()) ? prices[cut_length] : 0;
        value = std::max(value, price + cutting_memo(prices, memo, current_length - cut_length));
    }
    memo[current_length] = value;
    return value;
}

int rod_cutting_memo(std::vector<int> &prices, int rod_length) {
    std::vector<int> memo(rod_length + 1, -1);
    return cutting_memo(prices, memo, rod_length);
}


int rod_cutting_bottom_up(std::vector<int> &prices, int rod_length) {
    std::vector<int> dp(rod_length + 1, 0);
    for (int current_length{}; current_length <= rod_length; ++current_length) {
        for (int cut_length{}; cut_length <= current_length; ++cut_length) {
            int price = cut_length < prices.size() ? prices[cut_length] : 0;
            dp[current_length] = std::max(dp[current_length], dp[current_length - cut_length] + price);
        }
    }
    return dp[rod_length];
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_CUTTING_ROD_PROBLEM_H
