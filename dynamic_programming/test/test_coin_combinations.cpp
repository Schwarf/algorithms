//
// Created by andreas on 12.08.23.
//

//
#include "gtest/gtest.h"
#include "./../coin_combinations.h"

TEST(CoinCombinations, simple1)
{
	const std::vector<int> coins{1, 2, 5};
	constexpr int amount{5};
	constexpr int expected_number_of_combinations{4};
	EXPECT_EQ(coin_combinations_recursive(coins, amount), expected_number_of_combinations);

}
