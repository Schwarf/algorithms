//
// Created by andreas on 02.05.23.
//
#include "gtest/gtest.h"
#include "graphs/minimal_distance_to_connect_all_points.h"

TEST(TestMinimalDistanceToConnectAllPooints, five_points_manhatten_distance)
{
	std::vector<std::vector<int>> input{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
	int expected_result{20};
	auto result = minimal_costs_to_connect_points<int, std::vector<int>>(input);
	EXPECT_EQ(expected_result, result);
}

TEST(TestMinimalDistanceToConnectAllPooints, three_points_manhatten_distance)
{
	std::vector<std::vector<int>> input{{3, 12}, {-2, 5}, {-4, 1}};
	int expected_result{18};
	auto result = minimal_costs_to_connect_points<int, std::vector<int>>(input);
	EXPECT_EQ(expected_result, result);
}

TEST(TestMinimalDistanceToConnectAllPooints, one_point_manhatten_distance)
{
	std::vector<std::vector<int>> input{{3, 12}};
	int expected_result{0};
	auto result = minimal_costs_to_connect_points<int, std::vector<int>>(input);
	EXPECT_EQ(expected_result, result);
}