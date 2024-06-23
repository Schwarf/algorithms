//
// Created by andreas on 12.08.23.
//

//
#include "gtest/gtest.h"
#include "./../coin_combinations.h"

TEST(CoinCombinationsRecursive, simple1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{5};
    constexpr int expected_number_of_combinations{4};
    EXPECT_EQ(coin_combinations_recursive(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsRecursive, simple2) {
    const std::vector<int> coins{5};
    constexpr int amount{4};
    constexpr int expected_number_of_combinations{0};
    EXPECT_EQ(coin_combinations_recursive(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsRecursive, simple3) {
    const std::vector<int> coins{1};
    constexpr int amount{7};
    constexpr int expected_number_of_combinations{1};
    EXPECT_EQ(coin_combinations_recursive(coins, amount), expected_number_of_combinations);
}


TEST(CoinCombinationsRecursive, complex1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{500};
    constexpr int expected_number_of_combinations{12701};
    EXPECT_EQ(coin_combinations_recursive(coins, amount), expected_number_of_combinations);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(CoinCombinationsRecursive2, simple1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{5};
    constexpr int expected_number_of_combinations{4};
    EXPECT_EQ(coin_combinations_recursive2(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsRecursive2, simple2) {
    const std::vector<int> coins{5};
    constexpr int amount{4};
    constexpr int expected_number_of_combinations{0};
    EXPECT_EQ(coin_combinations_recursive2(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsRecursive2, simple3) {
    const std::vector<int> coins{1};
    constexpr int amount{7};
    constexpr int expected_number_of_combinations{1};
    EXPECT_EQ(coin_combinations_recursive2(coins, amount), expected_number_of_combinations);
}


TEST(CoinCombinationsRecursive2, complex1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{500};
    constexpr int expected_number_of_combinations{12701};
    EXPECT_EQ(coin_combinations_recursive2(coins, amount), expected_number_of_combinations);
}

// Recursive run takes long
/*
TEST(CoinCombinationsRecursive, complex2)
{
	const std::vector<int> coins{3, 5, 7, 8, 9, 10, 11};
	constexpr int amount{1000};
	constexpr int expected_number_of_combinations{1952879228};
	EXPECT_EQ(coin_combinations_top_down(coins, amount), expected_number_of_combinations);
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(CoinCombinationsTopDown, simple1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{5};
    constexpr int expected_number_of_combinations{4};
    EXPECT_EQ(coin_combinations_top_down(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsTopDown, simple2) {
    const std::vector<int> coins{5};
    constexpr int amount{4};
    constexpr int expected_number_of_combinations{0};
    EXPECT_EQ(coin_combinations_top_down(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsTopDown, simple3) {
    const std::vector<int> coins{1};
    constexpr int amount{7};
    constexpr int expected_number_of_combinations{1};
    EXPECT_EQ(coin_combinations_top_down(coins, amount), expected_number_of_combinations);
}


TEST(CoinCombinationsTopDown, complex1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{500};
    constexpr int expected_number_of_combinations{12701};
    EXPECT_EQ(coin_combinations_top_down(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsTopDown, complex2) {
    const std::vector<int> coins{3, 5, 7, 8, 9, 10, 11};
    constexpr int amount{1000};
    constexpr int expected_number_of_combinations{1952879228};
    EXPECT_EQ(coin_combinations_top_down(coins, amount), expected_number_of_combinations);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


TEST(CoinCombinationsTopDown2, simple1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{5};
    constexpr int expected_number_of_combinations{4};
    EXPECT_EQ(coin_combinations_top_down2(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsTopDown2, simple2) {
    const std::vector<int> coins{5};
    constexpr int amount{4};
    constexpr int expected_number_of_combinations{0};
    EXPECT_EQ(coin_combinations_top_down2(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsTopDown2, simple3) {
    const std::vector<int> coins{1};
    constexpr int amount{7};
    constexpr int expected_number_of_combinations{1};
    EXPECT_EQ(coin_combinations_top_down2(coins, amount), expected_number_of_combinations);
}


TEST(CoinCombinationsTopDown2, complex1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{500};
    constexpr int expected_number_of_combinations{12701};
    EXPECT_EQ(coin_combinations_top_down2(coins, amount), expected_number_of_combinations);
}

//TEST(CoinCombinationsTopDown2, complex2) {
//    const std::vector<int> coins{3, 5, 7, 8, 9, 10, 11};
//    constexpr int amount{1000};
//    constexpr int expected_number_of_combinations{1952879228};
//    EXPECT_EQ(coin_combinations_top_down2(coins, amount), expected_number_of_combinations);
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


TEST(CoinCombinationsBottomUp, simple1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{5};
    constexpr int expected_number_of_combinations{4};
    EXPECT_EQ(coin_combinations_bottom_up(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsBottomUp, simple2) {
    const std::vector<int> coins{5};
    constexpr int amount{4};
    constexpr int expected_number_of_combinations{0};
    EXPECT_EQ(coin_combinations_bottom_up(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsBottomUp, simple3) {
    const std::vector<int> coins{1};
    constexpr int amount{7};
    constexpr int expected_number_of_combinations{1};
    EXPECT_EQ(coin_combinations_bottom_up(coins, amount), expected_number_of_combinations);
}


TEST(CoinCombinationsBottomUp, complex1) {
    const std::vector<int> coins{1, 2, 5};
    constexpr int amount{500};
    constexpr int expected_number_of_combinations{12701};
    EXPECT_EQ(coin_combinations_bottom_up(coins, amount), expected_number_of_combinations);
}

TEST(CoinCombinationsBottomUp, complex2) {
    const std::vector<int> coins{3, 5, 7, 8, 9, 10, 11};
    constexpr int amount{1000};
    constexpr int expected_number_of_combinations{1952879228};
    EXPECT_EQ(coin_combinations_bottom_up(coins, amount), expected_number_of_combinations);
}
