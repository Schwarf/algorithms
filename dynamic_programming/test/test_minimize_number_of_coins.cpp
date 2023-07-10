//
// Created by andreas on 10.07.23.
//
#include "gtest/gtest.h"
#include "./../minimize_number_of_coins.h"

TEST(MinimizeClassic, simple1)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{11};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, minimize_number_of_coins(coins, amount));
}

TEST(MinimizeClassic, empty)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{0};
	constexpr int expected_result{0};
	EXPECT_EQ(expected_result, minimize_number_of_coins(coins, amount));
}


TEST(MinimizeClassic, one)
{
	const std::vector<int> coins{1, 2, 4, 5, 6};
	constexpr int amount{6};
	constexpr int expected_result{1};
	EXPECT_EQ(expected_result, minimize_number_of_coins(coins, amount));
}

TEST(MinimizeClassic, simple2)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{30};
	constexpr int expected_result{6};
	EXPECT_EQ(expected_result, minimize_number_of_coins(coins, amount));
}


TEST(MinimizeBottomUp, simple1)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{11};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, minimize_number_of_coins_bottom_up(coins, amount));
}

TEST(MinimizeBottomUp, empty)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{0};
	constexpr int expected_result{0};
	EXPECT_EQ(expected_result, minimize_number_of_coins_bottom_up(coins, amount));
}


TEST(MinimizeBottomUp, one)
{
	const std::vector<int> coins{1, 2, 4, 5, 6};
	constexpr int amount{6};
	constexpr int expected_result{1};
	EXPECT_EQ(expected_result, minimize_number_of_coins_bottom_up(coins, amount));
}

TEST(MinimizeBottomUp, simple2)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{30};
	constexpr int expected_result{6};
	EXPECT_EQ(expected_result, minimize_number_of_coins_bottom_up(coins, amount));
}


TEST(MinimizeBottomUp, complex)
{
	const std::vector<int> coins{186, 419, 83, 408};
	constexpr int amount{6249};
	constexpr int expected_result{20};
	EXPECT_EQ(expected_result, minimize_number_of_coins_bottom_up(coins, amount));
}

TEST(MinimizeBottomUp, complex2)
{
	const std::vector<int> coins{411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};
	constexpr int amount{9864};
	constexpr int expected_result{24};
	EXPECT_EQ(expected_result, minimize_number_of_coins_bottom_up(coins, amount));
}


TEST(MinimizeTopDown, simple1)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{11};
	constexpr int expected_result{3};
	EXPECT_EQ(expected_result, minimize_number_of_coins_top_down(coins, amount));
}

TEST(MinimizeTopDown, empty)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{0};
	constexpr int expected_result{0};
	EXPECT_EQ(expected_result, minimize_number_of_coins_top_down(coins, amount));
}


TEST(MinimizeTopDown, one)
{
	const std::vector<int> coins{1, 2, 4, 5, 6};
	constexpr int amount{6};
	constexpr int expected_result{1};
	EXPECT_EQ(expected_result, minimize_number_of_coins_top_down(coins, amount));
}

TEST(MinimizeTopDown, simple2)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{30};
	constexpr int expected_result{6};
	EXPECT_EQ(expected_result, minimize_number_of_coins_top_down(coins, amount));
}


TEST(MinimizeTopDown, complex)
{
	const std::vector<int> coins{186, 419, 83, 408};
	constexpr int amount{6249};
	constexpr int expected_result{20};
	EXPECT_EQ(expected_result, minimize_number_of_coins_top_down(coins, amount));
}

TEST(MinimizeTopDown, complex2)
{
	const std::vector<int> coins{411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};
	constexpr int amount{9864};
	constexpr int expected_result{24};
	EXPECT_EQ(expected_result, minimize_number_of_coins_top_down(coins, amount));
}
