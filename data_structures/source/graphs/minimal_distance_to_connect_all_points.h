//
// Created by andreas on 01.05.23.
//

#ifndef MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
#define MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
#include <vector>
#include <concepts>
#include <queue>


template<typename T, typename ContainerType, typename DistanceFunctionType>
requires std::is_integral_v<T> && std::same_as<T, typename ContainerType::value_type> &&
	std::same_as<T, std::invoke_result_t<DistanceFunctionType, ContainerType, ContainerType>>
T minimal_costs_to_connect_points(std::vector<std::vector<T>> points, DistanceFunctionType distance_function)
{

	auto comparator = [](const std::pair<T, T> &p1, const std::pair<T, T> &p2)
	{
		return p1.second > p2.second;
	};

	std::vector<std::priority_queue<std::pair<T, T>, std::vector<std::pair<T, T>>, decltype(comparator)>>
		graph(points.size(),
			  std::priority_queue<std::pair<T, T>, std::vector<std::pair<T, T>>, decltype(comparator)>(comparator));
	std::unordered_map<T, T> id_weight;
	for (int i{}; i < points.size(); ++i) {
		for (int j{i + 1}; j < points.size(); ++j) {
			T distance = distance_function(points[i], points[j]);
			graph[i].push({j, distance});
			graph[j].push({i, distance});
		}
		id_weight[i] = std::numeric_limits<T>::max();
	}


	std::vector<bool> visited(graph.size(), false);
	int index{};
	T total_distance{};
	while (!visited[index]) {
		visited[index] = true;
		T distance{};
		while (true) {
			if (!visited[graph[index].top().first]) {
				distance = graph[index].top().second;
				break;
			}
			else if (graph[index].empty())
				break;
			graph[index].pop();
		}
		index = graph[index].top().first;
		total_distance += distance;
	}
	return total_distance;
}


#endif //MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
