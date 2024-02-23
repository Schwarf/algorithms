//
// Created by andreas on 23.02.24.
//

#ifndef FIND_CHEAPEST_FLIGHTS_WITH_K_STOPS_H
#define FIND_CHEAPEST_FLIGHTS_WITH_K_STOPS_H
#include <vector>
#include <queue>
// There are n cities connected by some number of flights. You are given an array flights where
// flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src
// to dst with at most k stops. If there is no such route, return -1.

int find_cheapest_flights(int n,
						  const std::vector<std::vector<int>> &flights,
						  int source,
						  int destination,
						  int max_stops)
{
	std::vector<std::vector<std::pair<int, int>>> graph(n);
	for (const auto &flight: flights) {
		graph[flight[0]].emplace_back(flight[1], flight[2]);
	}
	std::vector<int> distance(n, std::numeric_limits<int>::max());
	std::queue<std::pair<int, int>> q;
	q.emplace(source, 0);
	int stops{};
	while (!q.empty() && stops <= max_stops) {
		int q_size = q.size();
		while (q_size--) {
			auto [current_node, current_distance] = q.front();
			q.pop();
			for (const auto &flight: graph[current_node]) {
				if (flight.second + current_distance < distance[flight.first]) {
					distance[flight.first] = flight.second + current_distance;
					q.emplace(flight.first, current_distance + flight.second);
				}
			}
		}
		stops++;
	}
	return distance[destination] == std::numeric_limits<int>::max() ? -1 : distance[destination];
}
#endif //FIND_CHEAPEST_FLIGHTS_WITH_K_STOPS_H
