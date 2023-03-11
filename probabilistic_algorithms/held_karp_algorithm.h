//
// Created by andreas on 11.03.23.
//

#ifndef HELD_KARP_ALGORITHM_H
#define HELD_KARP_ALGORITHM_H
#include <vector>
#include <cmath>
#include <limits>
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
