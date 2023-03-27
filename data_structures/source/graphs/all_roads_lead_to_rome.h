//
// Created by andreas on 26.03.23.
//

#ifndef ALL_ROADS_LAD_TO_ROME_H
#define ALL_ROADS_LAD_TO_ROME_H
#include <vector>
#include "used_concepts.h"
// There are n cities from 0 to n-1 with n-1 roads. Rome is city 0. There is only one way to travel between the
// cities and they are all one-way roads. Last year some roads were reoriented. This year a big event happens in Rome
// and people from all cities want to travel to Rome. The task is to reorient some roads such that each path
// of the n-1 cities ends in Rome. A one-way road from city a to city b is given as [a, b].
template<VertexRequirement T>
void depth_first_search(T node, T parent, const std::vector<std::vector<std::pair<T, int>>> &graph, int &count)
{
	for (const auto &[child, sign]: graph[node]) {
		if (child != parent) {
			count += sign;
			depth_first_search(child, node, graph, count);
		}
	}
}

template<VertexRequirement T>
int all_roads_lead_to_rome(T n, std::vector<std::vector<T>> &roads)
{
	std::vector<std::vector<std::pair<T, int>>> graph(n);
	for (const auto &road: roads) {
		graph[road[0]].push_back({road[1], 1});
		graph[road[1]].push_back({road[0], 0});
	}
	int count{};
	depth_first_search({}, n + 1, graph, count);
	return count;
}


#endif //ALL_ROADS_LAD_TO_ROME_H
