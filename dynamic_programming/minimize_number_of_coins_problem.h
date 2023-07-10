
//
// Created by andreas on 09.07.23.
//

#ifndef MINIMIZE_NUMBER_OF_COINS_PROBLEM_H
#define MINIMIZE_NUMBER_OF_COINS_PROBLEM_H
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


#endif //MINIMIZE_NUMBER_OF_COINS_PROBLEM_H
