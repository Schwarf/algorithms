//
// Created by andreas on 01.05.23.
//

#ifndef MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
#define MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
#include <vector>
#include <concepts>

template <typename T, template<typename...> typename CoordinateType>
concept CoordinateTypeTemplate = requires(const CoordinateType<T> &coordinates)
{
	{ coordinates[0] } -> std::same_as<typename CoordinateType<T>::value_type const &>;
	{ coordinates.size() } -> std::same_as<std::size_t>;
};

template<typename Type, typename Function, template<typename...> typename CoordinateType>
concept DistanceFunction = requires(Function function, const CoordinateType<Type> & coordinates)
{
	requires CoordinateTypeTemplate<Type, CoordinateType>;
	std::invocable<Function>;
	{ function(coordinates, coordinates)} ->std::same_as<Type>;
};

template<typename T, typename DistanceFunctionType, template<typename...> typename CoordinateType >
requires std::is_integral_v<T> && DistanceFunction<T, DistanceFunctionType, CoordinateType>
T minimal_costs_to_connect_points(std::vector<std::vector<T>> points, DistanceFunctionType distance_function)
{

	std::vector<std::vector<std::pair<T, T>>> graph(points.size() + 1);
	for(int i{} ; i < points.size(); ++i) {
		for (int j{}; j < points.size(); j++)
		{
			if(i==j)
				continue;
			auto distance = distance_function(points[i], points[j]);
			graph[i].push_back({j , })
		}
	}
}


#endif //MINIMAL_DISTANCE_TO_CONNECT_ALL_POINTS_H
