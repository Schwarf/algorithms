//
// Created by andreas on 03.01.24.
//
#include "gtest/gtest.h"
#include "graphs/shortest_path_algorithms.h"

class SetupShortestGraphTests: public testing::Test
{
public:
	SetupShortestGraphTests() = default;

	std::tuple<std::vector<std::vector<std::pair<unsigned int, float>>>,
			   std::vector<std::vector<float>>,
			   std::vector<std::vector<float>>> case1()
	{
		std::vector<std::vector<float>> adjacency_matrix = {
			{0.0, 2.5, 1.8, std::numeric_limits<float>::max(), std::numeric_limits<float>::max()},
			{2.5, 0.0, 2.0, 3.1, std::numeric_limits<float>::max()},
			{1.8, 2.0, 0.0, std::numeric_limits<float>::max(), 1.6},
			{std::numeric_limits<float>::max(), 3.1, std::numeric_limits<float>::max(), 0.0, 2.3},
			{std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), 1.6, 2.3, 0.0}
		};
		std::vector<std::vector<std::pair<unsigned int, float>>> adjacency_list = {
			{{1, 2.5}, {2, 1.8}},
			{{0, 2.5}, {2, 2.0}, {3, 3.1}},
			{{0, 1.8}, {1, 2.0}, {4, 1.6}},
			{{1, 3.1}, {4, 2.3}},
			{{2, 1.6}, {3, 2.3}}
		};
		std::vector<std::vector<float>> distance_matrix = {
			{0.0, 2.5, 1.8, 5.6, 3.4},
			{2.5, 0.0, 2.0, 3.1, 3.6},
			{1.8, 2.0, 0.0, 3.9, 1.6},
			{5.6, 3.1, 3.9, 0.0, 2.3},
			{3.4, 3.6, 1.6, 2.3, 0.0}
		};
		return std::make_tuple(adjacency_list, adjacency_matrix, distance_matrix);
	}

};


TEST_F(SetupShortestGraphTests, TestDijkstraAdjacencyListCase1)
{
	auto tuple = case1();
	auto adjacency_list = std::get<0>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{5U};
	for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex) {
		auto result = distances_from_source_dijkstra(start_vertex, adjacency_list);
		for (int i{}; i < 5; ++i) {
			EXPECT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


TEST_F(SetupShortestGraphTests, TestBellmannFordAdjacencyListCase1)
{
	auto tuple = case1();
	auto adjacency_list = std::get<0>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{5U};
	for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex) {
		auto result = distances_from_source_bellman_ford(start_vertex, adjacency_list);
		for (int i{}; i < 5; ++i) {
			EXPECT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


