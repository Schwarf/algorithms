//
// Created by andreas on 03.01.24.
//

#ifndef SHORTEST_PATH_ALGORITHMS_H
#define SHORTEST_PATH_ALGORITHMS_H
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

template<typename VertexType, typename DistanceType>
requires std::is_unsigned_v<VertexType> && std::is_arithmetic_v<DistanceType>
std::vector<DistanceType> distances_from_source_bellman_ford_matrix(VertexType source,
																	const std::vector<std::vector<DistanceType>> &graph)
{
	VertexType number_of_vertices = graph.size();
	std::vector<DistanceType> distances(number_of_vertices, std::numeric_limits<DistanceType>::max());
	distances[source] = static_cast<DistanceType>(0);

	for (VertexType i = 0; i < number_of_vertices - 1; ++i) {
		for (VertexType u = 0; u < number_of_vertices; ++u) {
			for (VertexType v = 0; v < number_of_vertices; ++v) {
				if (graph[u][v] != std::numeric_limits<DistanceType>::max() &&
					distances[u] != std::numeric_limits<DistanceType>::max() &&
					distances[u] + graph[u][v] < distances[v]) {
					distances[v] = distances[u] + graph[u][v];
				}
			}
		}
	}

	// Check for negative-weight cycles
	for (VertexType u = 0; u < number_of_vertices; ++u) {
		for (VertexType v = 0; v < number_of_vertices; ++v) {
			if (graph[u][v] != std::numeric_limits<DistanceType>::max() &&
				distances[u] != std::numeric_limits<DistanceType>::max() &&
				distances[u] + graph[u][v] < distances[v]) {
				throw std::runtime_error("Graph contains a negative-weight cycle");
			}
		}
	}

	return distances;
}

template<typename VertexType, typename DistanceType>
requires std::is_unsigned_v<VertexType> && std::is_arithmetic_v<DistanceType>
std::vector<DistanceType> distances_from_source_bellman_ford(VertexType source,
															 const std::vector<std::vector<std::pair<VertexType,
																									 DistanceType>>> &graph)
{
	auto number_of_vertices = graph.size();
	std::vector<DistanceType> distances(number_of_vertices, std::numeric_limits<DistanceType>::max());
	distances[source] = static_cast<DistanceType>(0);
	for (VertexType i{}; i < number_of_vertices - 1; ++i) {
		for (VertexType u{}; u < number_of_vertices; ++u) {
			for (const auto &[v, distance]: graph[u]) {
				//prevent overflow by fist condition
				if (distances[u] != std::numeric_limits<DistanceType>::max()
					&& distances[u] + distance < distances[v]) {
					distances[v] = distances[u] + distance;
				}
			}
		}
	}
	// Check for negative-weight cycles
	for (VertexType u = 0; u < number_of_vertices; ++u) {
		for (const auto &[v, weight]: graph[u]) {
			if (distances[u] != std::numeric_limits<DistanceType>::max() && distances[u] + weight < distances[v]) {
				throw std::runtime_error("Graph contains a negative-weight cycle");
			}
		}
	}
	return distances;
}

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

template<typename VertexType, typename DistanceType>
requires std::is_unsigned_v<VertexType> && std::is_arithmetic_v<DistanceType>
std::vector<DistanceType> distances_from_source_dijkstra_matrix(VertexType source,
																const std::vector<std::vector<DistanceType>> &graph)
{
	VertexType number_of_vertices = graph.size();
	std::vector<DistanceType> distances(number_of_vertices, std::numeric_limits<DistanceType>::max());
	std::set<std::pair<DistanceType, VertexType>> ordered_set;

	distances[source] = static_cast<DistanceType>(0);
	ordered_set.insert({0, source});

	while (!ordered_set.empty()) {
		VertexType u = ordered_set.begin()->second;
		ordered_set.erase(ordered_set.begin());

		for (VertexType v = 0; v < number_of_vertices; ++v) {
			if (graph[u][v] != std::numeric_limits<DistanceType>::max()) {
				if (distances[u] + graph[u][v] < distances[v]) {
					ordered_set.erase({distances[v], v});
					distances[v] = distances[u] + graph[u][v];
					ordered_set.insert({distances[v], v});
				}
			}
		}
	}

	return distances;
}

template<typename DistanceType>
requires std::is_arithmetic_v<DistanceType>
std::vector<std::vector<DistanceType>> distances_floyd_warshall_matrix(std::vector<std::vector<DistanceType>> graph)
{
	int number_of_vertices = graph.size();
	for (int k = 0; k < number_of_vertices; ++k) {
		for (int i = 0; i < number_of_vertices; ++i) {
			for (int j = 0; j < number_of_vertices; ++j) {
				if (graph[i][k] != std::numeric_limits<DistanceType>::max() &&
					graph[k][j] != std::numeric_limits<DistanceType>::max() &&
					graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	return graph;
}

// Note the Floyd-Warhall algorithm operates on adjacency matrix. Therefore, adjacency lists have to be converted.
template<typename VertexType, typename DistanceType>
requires std::is_unsigned_v<VertexType> && std::is_arithmetic_v<DistanceType>
std::vector<std::vector<DistanceType>> distances_floyd_warshall(std::vector<std::vector<std::pair<VertexType,
																								  DistanceType>>> &graph)
{
	auto number_of_vertices = graph.size();
	std::vector<std::vector<DistanceType>> graph_matrix
		(number_of_vertices, std::vector<DistanceType>(number_of_vertices, std::numeric_limits<DistanceType>::max()));

	for (VertexType u{}; u < number_of_vertices; ++u) {
		graph_matrix[u][u] = static_cast<DistanceType>(0);
		for (const auto &[v, distance]: graph[u]) {
			graph_matrix[u][v] = distance;
		}
	}
	return distances_floyd_warshall_matrix<DistanceType>(graph_matrix);
}


#endif //SHORTEST_PATH_ALGORITHMS_H
