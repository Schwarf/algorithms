//
// Created by andreas on 11.03.23.
//

#ifndef HELD_KARP_ALGORITHM_H
#define HELD_KARP_ALGORITHM_H
#include <vector>
#include <cmath>
#include <limits>


template<typename CoordinatesType>
concept RequireCoordinates = requires(const CoordinatesType &coordinates1, const CoordinatesType &coordinates2)
{
	// coordinates1 & coordinates2 shall provide the index operator and return the value_type
	{ coordinates1[0] } -> std::same_as<typename CoordinatesType::value_type const &>;
	{ coordinates2[0] } -> std::same_as<typename CoordinatesType::value_type const &>;
	// coordinates1 & coordinates2 shall provide the size method
	{ coordinates1.size() } -> std::same_as<std::size_t>;
	{ coordinates2.size() } -> std::same_as<std::size_t>;
	// coordinates1 & coordinates2 shall be of the same size
	coordinates1.size() == coordinates2.size();
	// The values stored in coordinates1 & coordinates2 shall be cast to double
	{ static_cast<double> (coordinates1[0]) };
	{ static_cast<double> (coordinates2[0]) };
};

template<typename ContainerType>
concept RequireIndexedContainer = requires(const ContainerType &container)
{
	{ container[0] } -> std::same_as<typename ContainerType::value_type const &>;
	{ container.size() } -> std::same_as<std::size_t>;
};

template<typename FunctionType, typename ContainerType>
concept RequireDistanceFunction = requires(FunctionType function,
										   const ContainerType &container1,
										   const ContainerType &container2)
{
	requires std::same_as< typename std::invoke_result_t<FunctionType,
											   typename ContainerType::value_type,
											   typename ContainerType::value_type>, double>;
	requires RequireCoordinates<ContainerType>;

};
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
		(number_of_location_sets,std::vector<double>(number_of_locations, std::numeric_limits<double>::max()));

	// The distance to the first city to itself is 0
	distance_memoization[1][0] = 0.0;
	for (int subset_bit_mask = 2; subset_bit_mask < number_of_location_sets; ++subset_bit_mask )
	{
		for(int location_index1{}; location_index1 < number_of_locations; ++location_index1)
		{
			if(subset_bit_mask & (1 << location_index1))
			for(int location_index2{}; location_index2 < number_of_locations; ++location_index2)
			{
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

struct City
{
	double x, y;
};

double dist(City a, City b)
{
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double held_karp(const std::vector<City> &cities)
{
	const int n = cities.size();
	const int N = 1 << n;

	// Initialize memoization table
	std::vector<std::vector<double>> memo(N, std::vector<double>(n, std::numeric_limits<double>::max()));
	memo[1][0] = 0.0;

	// Compute all subproblems
	for (int s = 2; s < N; s++) {
		for (int i = 0; i < n; i++) {
			if (s & (1 << i)) {
				for (int j = 0; j < n; j++) {
					if (i != j && (s & (1 << j))) {
						memo[s][i] = std::min(memo[s][i], memo[s - (1 << i)][j] + dist(cities[j], cities[i]));
					}
				}
			}
		}
	}

	// Compute optimal tour distance
	double min_dist = std::numeric_limits<double>::max();
	for (int i = 1; i < n; i++) {
		min_dist = std::min(min_dist, memo[N - 1][i] + dist(cities[i], cities[0]));
	}

	return min_dist;
}

#endif //HELD_KARP_ALGORITHM_H
