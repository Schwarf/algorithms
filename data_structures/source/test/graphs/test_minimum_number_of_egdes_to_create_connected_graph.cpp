//
// Created by andreas on 26.03.23.
//
#include "gtest/gtest.h"
#include "graphs/minimum_number_of_egdes_to_create_connected_graph.h"

TEST(FindShortestEdgeInSubgraph, ZeroCase_BFS)
{
	std::vector<std::vector<unsigned short>> input{{0, 3}, {1, 2}, {2, 3}, {3, 4}, {3, 5}};
	int expected_result{0};
	unsigned short number_of_required_vertices{6};
	auto result =
		minimum_number_of_edges_to_create_connected_graph(number_of_required_vertices, input);
	EXPECT_EQ(expected_result, result);
}

TEST(FindShortestEdgeInSubgraph, TwoReconnections_BFS)
{
	std::vector<std::vector<unsigned short>> input{{0, 2}, {1, 2}, {2, 3}, {0, 1}, {0, 3}};
	int expected_result{2};
	unsigned short number_of_required_vertices{6};
	auto result =
		minimum_number_of_edges_to_create_connected_graph(number_of_required_vertices, input);
	EXPECT_EQ(expected_result, result);
}


TEST(FindShortestEdgeInSubgraph, DoesNotWork_BFS)
{
	std::vector<std::vector<unsigned short>> input{{0, 2}, {1, 2}, {2, 3}, {0, 1}};
	int expected_result{-1};
	unsigned short number_of_required_vertices{6};
	auto result =
		minimum_number_of_edges_to_create_connected_graph(number_of_required_vertices, input);
	EXPECT_EQ(expected_result, result);
}


TEST(FindShortestEdgeInSubgraph, ZeroCase_DFS)
{
	std::vector<std::vector<unsigned short>> input{{0, 3}, {1, 2}, {2, 3}, {3, 4}, {3, 5}};
	int expected_result{0};
	unsigned short number_of_required_vertices{6};
	auto result =
		minimum_number_of_edges_to_create_connected_graph(number_of_required_vertices, input, false);
	EXPECT_EQ(expected_result, result);
}

TEST(FindShortestEdgeInSubgraph, TwoReconnections_DFS)
{
	std::vector<std::vector<unsigned short>> input{{0, 2}, {1, 2}, {2, 3}, {0, 1}, {0, 3}};
	int expected_result{2};
	unsigned short number_of_required_vertices{6};
	auto result =
		minimum_number_of_edges_to_create_connected_graph(number_of_required_vertices, input, false);
	EXPECT_EQ(expected_result, result);
}


TEST(FindShortestEdgeInSubgraph, DoesNotWork_DFS)
{
	std::vector<std::vector<unsigned short>> input{{0, 2}, {1, 2}, {2, 3}, {0, 1}};
	int expected_result{-1};
	unsigned short number_of_required_vertices{6};
	auto result =
		minimum_number_of_edges_to_create_connected_graph(number_of_required_vertices, input, false);
	EXPECT_EQ(expected_result, result);
}
