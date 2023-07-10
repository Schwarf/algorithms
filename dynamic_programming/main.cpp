//
// Created by andreas on 18.07.22.
//
#include <iostream>
#include "minimize_number_of_coins_problem.h"

int main()
{
	const std::vector<int> coins{2};
	const int amount{3};
	std::cout << minimize_number_of_coins(coins, amount) << std::endl;

}