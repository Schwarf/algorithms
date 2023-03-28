//
// Created by andreas on 11.03.23.
//

#ifndef HELD_KARP_ALGORITHM_H
#define HELD_KARP_ALGORITHM_H
#include <vector>
#include <cmath>
#include <limits>
#include "used_concepts.h"

template<typename CoordinatesType>
requires RequireCoordinates<CoordinatesType>
double distance(const CoordinatesType &location1, const CoordinatesType &location2)
{
	double distance{};
	for (size_t index{}; index < location1.size(); index++) {
		auto difference = static_cast<double>(location1[index] - location2[index]);
		distance += difference * difference;
	}
	return std::sqrt(distance);
}

template<typename ContainerType>
requires RequireIndexedContainer<ContainerType>
double held_karp_algorithm(const ContainerType &locations)
{
	const int number_of_locations = locations.size();
	const int number_of_location_sets = 1 << number_of_locations;
	std::vector<std::vector<double>> distance_memoization
		(number_of_location_sets, std::vector<double>(number_of_locations, std::numeric_limits<double>::max()));

	// The distance to the first city to itself is 0
	distance_memoization[1][0] = 0.0;
	for (int subset_bit_mask = 2; subset_bit_mask < number_of_location_sets; ++subset_bit_mask) {
		for (int location_index1{}; location_index1 < number_of_locations; ++location_index1) {
			if (subset_bit_mask & (1 << location_index1))
				for (int location_index2{}; location_index2 < number_of_locations; ++location_index2) {
					if (location_index1 != location_index2 && (subset_bit_mask & (1 << location_index2))) {
						distance_memoization[subset_bit_mask][location_index1] =
							std::min(distance_memoization[subset_bit_mask][location_index1],
									 distance_memoization[subset_bit_mask - (1 << location_index1)][location_index2]
										 + distance(locations[location_index2], locations[location_index1]));

					}
				}
		}
	}
	double minimal_distance = std::numeric_limits<double>::max();
	for (int i = 1; i < number_of_locations; i++) {
		minimal_distance = std::min(minimal_distance, distance_memoization[number_of_location_sets - 1][i] +
			distance(locations[i], locations[0]));
	}
	return minimal_distance;
}

#endif //HELD_KARP_ALGORITHM_H
