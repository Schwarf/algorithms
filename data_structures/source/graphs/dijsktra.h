//
// Created by andreas on 03.01.24.
//

#ifndef DIJSKTRA_H
#define DIJSKTRA_H
#include <iostream>
#include <vector>
#include <queue>
#include <utility>


template<typename VertexType, typename DistanceType>
requires std::is_unsigned_v<VertexType> && std::is_arithmetic_v<DistanceType>
std::vector<DistanceType> distances_from_source_dijkstra(VertexType source,
														 const std::vector<std::vector<std::pair<VertexType,
																								 DistanceType>>> &graph)
{
	int number_of_vertices = graph.size();
	auto distances_from_source_vertex =
		std::vector<DistanceType>(number_of_vertices, std::numeric_limits<DistanceType>::max());
	std::priority_queue<std::pair<DistanceType, VertexType>,
						std::vector<std::pair<DistanceType, VertexType>>,
						std::greater<>> pq;
	pq.emplace(static_cast<DistanceType>(0), source);
	distances_from_source_vertex[source] = static_cast<DistanceType>(0);

	while (!pq.empty()) {
		auto distance = pq.top().first;
		auto current_vertex = pq.top().second;
		pq.pop();

		if (distance > distances_from_source_vertex[current_vertex]) {
			continue;
		}

		for (const auto &edge: graph[current_vertex]) {
			auto next_vertex = edge.first;
			auto next_distance = distance + edge.second;

			if (next_distance < distances_from_source_vertex[next_vertex]) {
				distances_from_source_vertex[next_vertex] = next_distance;
				pq.emplace(next_distance, next_vertex);
			}
		}
	}
	return distances_from_source_vertex;
}


#endif //DIJSKTRA_H
