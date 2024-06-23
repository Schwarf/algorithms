//
// Created by andreas on 18.06.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_CUTTING_ROD_PROBLEM_H
#define DYNAMIC_PROGRAMMING_SAMPLES_CUTTING_ROD_PROBLEM_H

// Kerling Enterprises buys long steel rods and cuts them into shorter rods, which it then sells. Each cut is free.
// The management of Kerling Enterprises wants to know the best way to cut up the rods.
#include <vector>
#include <utility>

int cutting(std::vector<int> &prices, int length) {
    if (length == 0)
        return 0;
    int value{};
    for (int i{1}; i <= length; ++i) {
        int price = (i < prices.size()) ? prices[i] : 0;
        value = std::max(value, price + cutting(prices, length - i));
    }
    return value;
}

int rod_cutting(std::vector<int> &prices, int rod_length) {
    int n = prices.size();
    return cutting(prices, rod_length);
}


int cutting_memo(std::vector<int> &prices, std::vector<int> &memo, int length) {
    if (length == 0)
        return 0;
    if (memo[length] != -1)
        return memo[length];
    int value{};
    for (int i{1}; i <= length; ++i) {
        int price = (i < prices.size()) ? prices[i] : 0;
        value = std::max(value, price + cutting_memo(prices, memo, length - i));
    }
    memo[length] = value;
    return value;
}

int rod_cutting_memo(std::vector<int> &prices, int rod_length) {
    int n = prices.size();
    std::vector<int> memo(rod_length + 1, -1);
    return cutting_memo(prices, memo, rod_length);
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_CUTTING_ROD_PROBLEM_H
