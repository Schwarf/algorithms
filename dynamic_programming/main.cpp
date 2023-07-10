//
// Created by andreas on 18.07.22.
//
#include <iostream>
#include "minimize_number_of_coins_problem.h"

int main()
{
	const std::vector<int> coins{1, 3, 5};
	const int amount{11};
	std::cout << minimize_number_of_coins(coins, amount) << std::endl;
	std::cout << minimize_number_of_coins_memo(coins, amount) << std::endl;

}