//
// Created by andreas on 09.03.23.
//

#ifndef MINIMUM_SPEED_TO_EAT_BANANAS_IN_N_HOURS_H
#define MINIMUM_SPEED_TO_EAT_BANANAS_IN_N_HOURS_H
#include <concepts>
#include <ranges>
#include <algorithm>

template <typename Container>
concept IndexedContainerWithUnsignedIntegralElements = requires(Container c)
{
	{ c[0] } -> std::same_as<typename Container::value_type&>;
	{ c.size() } -> std::integral;
	requires std::unsigned_integral<typename Container::value_type>;
};

template <typename T>
concept UnsignedInteger64Bit = std::is_unsigned_v<T> && (sizeof(T) * 8 >= 64);

template <typename Container, typename ReturnType>
requires IndexedContainerWithUnsignedIntegralElements<Container>
bool is_enough_time_to_eat_all_bananas(const Container & banana_piles, int max_time, int speed)
{
	int time{};
	for(const auto & pile :banana_piles)
		time += (pile - 1)/speed + 1;

	return time <= max_time;
}

template <typename Container, typename ReturnType>
requires IndexedContainerWithUnsignedIntegralElements<Container> && UnsignedInteger64Bit<ReturnType>
ReturnType minimum_speed_to_eat_bananas_in_n_hours(const Container & banana_piles, int max_time)
{
	 int minimum_eating_speed{1};
	 int maximum_eating_speed = static_cast<int>(*std::ranges::max_element(banana_piles));
	 while(minimum_eating_speed < maximum_eating_speed)
	 {
		 int current_speed_guess = (maximum_eating_speed + minimum_eating_speed)/2;
		 if(is_enough_time_to_eat_all_bananas(banana_piles, max_time, current_speed_guess))
			 maximum_eating_speed = current_speed_guess;
		 else
			 minimum_eating_speed  = current_speed_guess +1;
	 }
	 return maximum_eating_speed;
}

#endif //MINIMUM_SPEED_TO_EAT_BANANAS_IN_N_HOURS_H
