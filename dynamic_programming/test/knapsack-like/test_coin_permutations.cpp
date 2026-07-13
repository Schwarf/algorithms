//
// Created by andreas on 11.07.26.
//

#include "../../knapsack-like/coin_permutations.h"
#include "gtest/gtest.h"

TEST(CoinPermutations, zero_amount)
{
    std::vector<int> coins{1, 2, 5};
    constexpr int amount{0};
    constexpr int expected_number_of_permutations{1};
    EXPECT_EQ(coin_permutations(coins, amount), expected_number_of_permutations);
}

TEST(CoinPermutations, no_solution)
{
    std::vector<int> coins{5};
    constexpr int amount{4};
    constexpr int expected_number_of_permutations{0};
    EXPECT_EQ(coin_permutations(coins, amount), expected_number_of_permutations);
}

TEST(CoinPermutations, simple_ordered_sequences)
{
    std::vector<int> coins{1, 2, 5};
    constexpr int amount{5};
    constexpr int expected_number_of_permutations{9};
    EXPECT_EQ(coin_permutations(coins, amount), expected_number_of_permutations);
}

TEST(CoinPermutations, unsorted_coins)
{
    std::vector<int> coins{5, 1, 2};
    constexpr int amount{5};
    constexpr int expected_number_of_permutations{9};
    EXPECT_EQ(coin_permutations(coins, amount), expected_number_of_permutations);
}

TEST(CoinPermutations, mixed_coin_values)
{
    std::vector<int> coins{2, 3, 5};
    constexpr int amount{10};
    constexpr int expected_number_of_permutations{14};
    EXPECT_EQ(coin_permutations(coins, amount), expected_number_of_permutations);
}
