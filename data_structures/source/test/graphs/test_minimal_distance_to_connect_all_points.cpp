//
// Created by andreas on 02.05.23.
//
#include "gtest/gtest.h"
#include "graphs/minimal_distance_to_connect_all_points.h"

TEST(TestMinimalDistanceToConnectAllPooints, five_points_manhatten_distance)
{
	std::vector<std::vector<int>> input{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
	int expected_result{20};
	auto distance_function = [](const std::vector<int> &v1, const std::vector<int> &v2)
	{
		return std::abs(v1[0] - v2[0]) + std::abs(v1[1] - v2[1]);
	};
	auto result =
		minimal_costs_to_connect_points<int, std::vector<int>, decltype(distance_function)>(input, distance_function);
	EXPECT_EQ(expected_result, result);
}