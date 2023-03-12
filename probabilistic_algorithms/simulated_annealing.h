//
// Created by andreas on 10.03.23.
//

#ifndef SIMULATED_ANNEALING_H
#define SIMULATED_ANNEALING_H
#include <random>
#include <algorithm>
#include "held_karp_algorithm.h"

template <typename ContainerType>
requires RequireIndexedContainer<ContainerType>
double compute_tour_length(const ContainerType & locations)
{
	const auto number_of_locations = locations.size();
	double tour_length{};
	for(int i{}; i < number_of_locations-1;++i)
		tour_length += distance(locations[i], locations[i+1]);
	tour_length += distance(locations[number_of_locations-1], locations[0]);
	return tour_length;
}

template <typename ContainerType>
requires RequireIndexedContainer<ContainerType>
double generate_random_tour(ContainerType & locations)
{
	std::mt19937 random_generator(std::random_device{}());
	std::ranges::shuffle(locations, random_generator);
}






#endif //SIMULATED_ANNEALING_H
