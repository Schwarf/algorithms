//
// Created by andreas on 03.01.24.
//
#include "gtest/gtest.h"
#include "graphs/shortest_path_algorithms.h"

class SetupShortestGraphTests: public testing::Test
{
public:
	SetupShortestGraphTests() = default;
	static constexpr auto max_int = std::numeric_limits<int>::max();
	static constexpr auto max_float = std::numeric_limits<float>::max();
	static std::tuple<std::vector<std::vector<std::pair<unsigned int, float>>>,
					  std::vector<std::vector<float>>,
					  std::vector<std::vector<float>>> case1()
	{
		std::vector<std::vector<float>> adjacency_matrix = {
			{0.0, 2.5, 1.8, max_float, max_float},
			{2.5, 0.0, 2.0, 3.1, max_float},
			{1.8, 2.0, 0.0, max_float, 1.6},
			{max_float, 3.1, max_float, 0.0, 2.3},
			{max_float, max_float, 1.6, 2.3, 0.0}
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

	static std::tuple<std::vector<std::vector<std::pair<unsigned int, int>>>,
					  std::vector<std::vector<int>>,
					  std::vector<std::vector<unsigned int>>> case2()
	{


		std::vector<std::vector<int>> adjacency_matrix = {
			{0, 4, max_int, 6, max_int, max_int, max_int, max_int, max_int, max_int},
			{4, 0, 3, max_int, max_int, 8, 4, max_int, max_int, max_int},
			{max_int, 3, 0, 2, max_int, max_int, 2, max_int, max_int, max_int},
			{6, max_int, 2, 0, 4, max_int, max_int, max_int, max_int, max_int},
			{max_int, max_int, max_int, 4, 0, max_int, max_int, 12, max_int, 7},
			{max_int, 8, max_int, max_int, max_int, 0, max_int, max_int, 5, 3},
			{max_int, 4, 2, max_int, max_int, max_int, 0, max_int, max_int, max_int},
			{max_int, max_int, max_int, max_int, 12, max_int, max_int, 0, 4, max_int},
			{max_int, max_int, max_int, max_int, max_int, 5, max_int, 4, 0, max_int},
			{max_int, max_int, max_int, max_int, 7, 3, max_int, max_int, max_int, 0}
		};
		std::vector<std::vector<std::pair<unsigned int, int>>> adjacency_list = {
			{{1, 4}, {3, 6}},
			{{0, 4}, {2, 3}, {5, 8}, {6, 4}},
			{{1, 3}, {3, 2}, {6, 2}},
			{{0, 6}, {2, 2}, {4, 4}},
			{{3, 4}, {7, 12}, {9, 7}},
			{{1, 8}, {8, 5}, {9, 3}},
			{{1, 4}, {2, 2}},
			{{4, 12}, {8, 4}},
			{{5, 5}, {7, 4}},
			{{4, 7}, {5, 3}}
		};
		std::vector<std::vector<unsigned int>> distance_matrix = {
			{0, 4, 7, 6, 10, 12, 8, 21, 17, 15},
			{4, 0, 3, 5, 9, 8, 4, 17, 13, 11},
			{7, 3, 0, 2, 6, 11, 2, 18, 16, 13},
			{6, 5, 2, 0, 4, 13, 4, 16, 18, 11},
			{10, 9, 6, 4, 0, 10, 8, 12, 15, 7},
			{12, 8, 11, 13, 10, 0, 12, 9, 5, 3},
			{8, 4, 2, 4, 8, 12, 0, 20, 17, 15},
			{21, 17, 18, 16, 12, 9, 20, 0, 4, 12},
			{17, 13, 16, 18, 15, 5, 17, 4, 0, 8},
			{15, 11, 13, 11, 7, 3, 15, 12, 8, 0}
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
		for (unsigned int i{}; i < number_of_vertices; ++i) {
			EXPECT_FLOAT_EQ(result[i], distance_list[start_vertex][i]);
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
		for (unsigned int i{}; i < number_of_vertices; ++i) {
			EXPECT_FLOAT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


TEST_F(SetupShortestGraphTests, TestDijkstraAdjacencyMatrixCase1)
{
	auto tuple = case1();
	auto adjacency_matrix = std::get<1>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{5U};
	for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex) {
		auto result = distances_from_source_dijkstra_matrix(start_vertex, adjacency_matrix);
		for (unsigned int i{}; i < 5; ++i) {
			EXPECT_FLOAT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


TEST_F(SetupShortestGraphTests, TestBellmannFordAdjacencyMatrixCase1)
{
	auto tuple = case1();
	auto adjacency_matrix = std::get<1>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{5U};
	for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex) {
		auto result = distances_from_source_bellman_ford_matrix(start_vertex, adjacency_matrix);
		for (unsigned int i{}; i < number_of_vertices; ++i) {
			EXPECT_FLOAT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


TEST_F(SetupShortestGraphTests, TestDijkstraAdjacencyListCase2)
{
	auto tuple = case2();
	auto adjacency_list = std::get<0>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{10U};
	for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex) {
		auto result = distances_from_source_dijkstra(start_vertex, adjacency_list);
		for (unsigned int i{}; i < number_of_vertices; ++i) {
			EXPECT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


TEST_F(SetupShortestGraphTests, TestBellmannFordAdjacencyListCase2)
{
	auto tuple = case2();
	auto adjacency_list = std::get<0>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{10U};
	for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex) {
		auto result = distances_from_source_bellman_ford(start_vertex, adjacency_list);
		for (unsigned int i{}; i < number_of_vertices; ++i) {
			EXPECT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


TEST_F(SetupShortestGraphTests, TestDijkstraAdjacencyMatrixCase2)
{
	auto tuple = case2();
	auto adjacency_matrix = std::get<1>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{10U};
	for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex) {
		auto result = distances_from_source_dijkstra_matrix(start_vertex, adjacency_matrix);
		for (unsigned int i{}; i < number_of_vertices; ++i) {
			EXPECT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


TEST_F(SetupShortestGraphTests, TestBellmannFordAdjacencyMatrixCase2)
{
	auto tuple = case2();
	auto adjacency_matrix = std::get<1>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{10U};
	for (unsigned int start_vertex{}; start_vertex < number_of_vertices; ++start_vertex) {
		auto result = distances_from_source_bellman_ford_matrix(start_vertex, adjacency_matrix);
		for (unsigned int i{}; i < number_of_vertices; ++i) {
			EXPECT_EQ(result[i], distance_list[start_vertex][i]);
		}
	}
}


TEST_F(SetupShortestGraphTests, TestFloydWarshallAdjacencyListCase1)
{
	auto tuple = case1();
	auto adjacency_list = std::get<0>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{5U};
	auto result = distances_floyd_warshall(adjacency_list);

	for (unsigned int i{}; i < number_of_vertices; ++i) {
		for (unsigned int j{}; j < number_of_vertices; ++j) {
			EXPECT_FLOAT_EQ(result[i][j], distance_list[i][j]);
		}

	}
}


TEST_F(SetupShortestGraphTests, TestFloydWarshallAdjacencyListCase2)
{
	auto tuple = case2();
	auto adjacency_list = std::get<0>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{10U};
	auto result = distances_floyd_warshall(adjacency_list);

	for (unsigned int i{}; i < number_of_vertices; ++i) {
		for (unsigned int j{}; j < number_of_vertices; ++j) {
			EXPECT_EQ(result[i][j], distance_list[i][j]);
		}

	}
}


TEST_F(SetupShortestGraphTests, TestFloydWarshallAdjacencyMatrixCase1)
{
	auto tuple = case1();
	auto adjacency_matrix = std::get<1>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{5U};
	auto result = distances_floyd_warshall_matrix(adjacency_matrix);

	for (unsigned int i{}; i < number_of_vertices; ++i) {
		for (unsigned int j{}; j < number_of_vertices; ++j) {
			EXPECT_FLOAT_EQ(result[i][j], distance_list[i][j]);
		}

	}
}


TEST_F(SetupShortestGraphTests, TestFloydWarshallAdjacencyMatrixCase2)
{
	auto tuple = case2();
	auto adjacency_matrix = std::get<1>(tuple);
	auto distance_list = std::get<2>(tuple);
	constexpr unsigned int number_of_vertices{10U};
	auto result = distances_floyd_warshall_matrix(adjacency_matrix);

	for (unsigned int i{}; i < number_of_vertices; ++i) {
		for (unsigned int j{}; j < number_of_vertices; ++j) {
			EXPECT_EQ(result[i][j], distance_list[i][j]);
		}

	}
}
