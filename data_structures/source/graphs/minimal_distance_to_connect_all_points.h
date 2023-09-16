//
// Created by andreas on 01.05.23.
//

#ifndef MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
#define MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
#include <vector>
#include <concepts>
#include <queue>
#include <limits>
// You are given an array points representing integer coordinates of some points on a 2D-plane,
// where points[i] = [xi, yi].
// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them:
// |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
// Return the minimum cost to make all points connected. All points are connected if
// there is exactly one simple path between any two points.

template<typename T, typename ContainerType, typename DistanceFunctionType>
requires std::is_integral_v<T> && std::same_as<T, typename ContainerType::value_type> &&
	std::same_as<T, std::invoke_result_t<DistanceFunctionType, ContainerType, ContainerType>>
T minimal_costs_to_connect_points(std::vector<std::vector<T>> points, DistanceFunctionType distance_function)
{
	std::vector<T> distances(points.size(), std::numeric_limits<T>::max());
	T answer{};
	for (int i{}; i < points.size() - 1; ++i) {
		for (int j{i + 1}; j < points.size(); ++j) {
			// We find the minimum distances from point i to all points (not yet considered j = i+1...max_index)
			distances[j] =
				std::min(distances[j], std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]));
			// the point j that has the minimum distance with point i shall be considered next, so we swap the points
			// j (the one we want) with one currently coming next (i+1)
			if (distances[j] < distances[i + 1]) {
				std::swap(points[j], points[i + 1]);
				std::swap(distances[j], distances[i + 1]);
			}
		}
		// we add the distance from i to i+1 to the answer
		answer += distances[i + 1];
	}
	return answer;
}


#endif //MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
