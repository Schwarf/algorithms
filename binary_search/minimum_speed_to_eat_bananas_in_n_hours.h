//
// Created by andreas on 09.03.23.
//

#ifndef MINIMUM_SPEED_TO_EAT_BANANAS_IN_N_HOURS_H
#define MINIMUM_SPEED_TO_EAT_BANANAS_IN_N_HOURS_H
#include "used_concepts.h"
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
// The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k.
// Each hour, she chooses some pile of bananas and eats k bananas from that pile.
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//Return the minimum integer k such that she can eat all the bananas within h hours.

template<typename Container>
requires IndexedContainerWithUnsignedIntegralElements<Container>
bool is_enough_time_to_eat_all_bananas(const Container &banana_piles, int max_time, int speed)
{
	int time{};
	for (const auto &pile: banana_piles)
		time += (pile - 1) / speed + 1;

	return time <= max_time;
}

template<typename Container>
requires IndexedContainerWithUnsignedIntegralElements<Container>
int minimum_speed_to_eat_bananas_in_n_hours(const Container &banana_piles, int max_time)
{
	int minimum_eating_speed{1};
	int maximum_eating_speed = static_cast<int>(*std::ranges::max_element(banana_piles));
	while (minimum_eating_speed < maximum_eating_speed) {
		int current_speed_guess = (maximum_eating_speed + minimum_eating_speed) / 2;
		if (is_enough_time_to_eat_all_bananas(banana_piles, max_time, current_speed_guess))
			maximum_eating_speed = current_speed_guess;
		else
			minimum_eating_speed = current_speed_guess + 1;
	}
	return maximum_eating_speed;
}

#endif //MINIMUM_SPEED_TO_EAT_BANANAS_IN_N_HOURS_H
