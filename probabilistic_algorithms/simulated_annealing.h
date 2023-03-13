//
// Created by andreas on 10.03.23.
//

#ifndef SIMULATED_ANNEALING_H
#define SIMULATED_ANNEALING_H
#include <random>
#include <algorithm>
#include "held_karp_algorithm.h"

template<typename ContainerType>
requires RequireIndexedContainer<ContainerType>
double compute_tour_length(const ContainerType &locations)
{
	const auto number_of_locations = locations.size();
	double tour_length{};
	for (size_t i{}; i < number_of_locations - 1; ++i)
		tour_length += distance(locations[i], locations[i + 1]);
	tour_length += distance(locations[number_of_locations - 1], locations[0]);
	return tour_length;
}

template<typename ContainerType>
requires RequireIndexedContainer<ContainerType>
ContainerType generate_random_tour(ContainerType locations)
{
	std::mt19937 random_generator(std::random_device{}());
	std::ranges::shuffle(locations, random_generator);
	return locations;
}

template<typename ContainerType>
requires RequireIndexedContainer<ContainerType>
void perturbate_tour(ContainerType & locations, int & index1, int & index2)
{
	std::mt19937 random_generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, locations.size() - 1);
	index1 = distribution(random_generator);
	index2 = distribution(random_generator);
	std::swap(locations[index1], locations[index2]);
}

template<typename ContainerType>
requires RequireIndexedContainer<ContainerType>
void undo_perturbation(ContainerType & locations, int index1, int index2)
{
	std::swap(locations[index1], locations[index2]);
}



template<typename ContainerType>
requires RequireIndexedContainer<ContainerType>
double simulated_annealing(const ContainerType &initial_locations, double initial_temperature, double cooling_rate,
						   double minimal_temperature)
{
	auto get_random_double_number = [](){
		std::mt19937 random_generator(std::random_device{}());
		std::uniform_real_distribution<double> distribution(0.0, 1.0);
		return distribution(random_generator);
	};

	auto current_tour = generate_random_tour(initial_locations);
	auto current_tour_length = compute_tour_length(current_tour);
	double temperature = initial_temperature;
	int index1{};
	int index2{};
	while (temperature > minimal_temperature) {
		perturbate_tour(current_tour, index1, index2);
		double new_tour_length = compute_tour_length(current_tour);
		double delta = new_tour_length - current_tour_length;
		if (delta < 0 || std::exp(-delta / temperature) > get_random_double_number())
			current_tour_length = new_tour_length;
		else
			undo_perturbation(current_tour, index1, index2);
		temperature *= cooling_rate;
	}
	return current_tour_length;
}




#endif //SIMULATED_ANNEALING_H
