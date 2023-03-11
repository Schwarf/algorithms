//
// Created by andreas on 11.03.23.
//

#ifndef HELD_KARP_ALGORITHM_H
#define HELD_KARP_ALGORITHM_H
#include <vector>
#include <cmath>
#include <limits>

template <typename Container>
concept IndexedContainer = requires(Container c)
{
	{ c[0] } -> std::same_as<typename Container::value_type&>;
	{ c.size() } -> std::same_as<std::size_t>;
};


template <typename Coordinates>
concept IndexedSameDimensionCoordinates = requires(const Coordinates & coordinates1, const Coordinates & coordinates2)
{
	{ coordinates1[0] } -> std::same_as<typename Coordinates::value_type&>;
	{ coordinates2[0] } -> std::same_as<typename Coordinates::value_type&>;
	{ coordinates1.size() } -> std::same_as<std::size_t>;
	{ coordinates2.size() } -> std::same_as<std::size_t>;
	coordinates1.size() == coordinates2.size();
	{static_cast<double> (coordinates1[0])};
	{static_cast<double> (coordinates2[0])};
};


template <typename Coordinates>
requires IndexedSameDimensionCoordinates<Coordinates>
double distance(const Coordinates & location1, const Coordinates & location2)
{
	double distance{};
	for(size_t index{}; index < location1.size(); index++)
	{
		auto difference = static_cast<double>(location1[index] - location2[index]);
		distance += difference*difference;
	}
	return std::sqrt(distance);
}

template <typename Coordinates>
requires IndexedSameDimensionCoordinates<Coordinates> && IndexedContainer<IndexedSameDimensionCoordinates<Coordinates>>
double held_karp_algorithm(const IndexedContainer<IndexedSameDimensionCoordinates<Coordinates>> & locations)
{

}

struct City {
	double x, y;
};

double dist(City a, City b) {
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double held_karp(const std::vector<City>& cities) {
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
