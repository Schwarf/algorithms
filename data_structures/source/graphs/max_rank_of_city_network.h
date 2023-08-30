//
// Created by andreas on 30.08.23.
//

#ifndef MAX_RANK_OF_CITY_NETWORK_H
#define MAX_RANK_OF_CITY_NETWORK_H
#include <concepts>
#include <vector>
// There is an infrastructure of n cities with some number of roads connecting these cities.
// Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
// The network rank of two different cities is defined as the total number of directly connected roads to either city.
// If a road is directly connected to both cities, it is only counted once.
// The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
// Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.


template<typename T>
requires std::is_unsigned_v<T>
int compute_network_rank(std::vector<std::vector<T>> &roads)
{
	int n = roads.size();
	std::vector<int> count(n, 0);
	std::vector<std::vector<bool>> directly_connected(n, std::vector<bool>(n, false));
	for (const auto &road: roads) {
		count[road[0]]++;
		count[road[1]]++;
		directly_connected[road[0]][road[1]] = true;
		directly_connected[road[1]][road[0]] = true;
	}
	int max_rank{};
	for (int i{}; i < n; ++i) {
		for (int j{i + 1}; j < n; ++j) {
			auto rank = count[i] + count[j];
			if (directly_connected[i][j])
				rank--;
			max_rank = std::max(rank, max_rank);
		}
	}
	return max_rank;
}
#endif //MAX_RANK_OF_CITY_NETWORK_H
