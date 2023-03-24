//
// Created by andreas on 22.03.23.
//
#include "gtest/gtest.h"
#include "graphs/find_smallest_edge_in_subgraph.h"

TEST(FindShortestEdgeInSubgraph, BFSallconnected1)
{
	std::vector<std::vector<int>> input{{1, 2, 3}, {2, 4, 5}, {1, 3, 7}, {3, 4, 5}, {1, 5, 1}};
	int expected_result{1};
	auto result = find_smallest_edge_in_sub_graph_bfs(input, 1, 5, 10, -1);
	EXPECT_EQ(expected_result, result);
}


TEST(FindShortestEdgeInSubgraph, BFSdisconnected1)
{
	std::vector<std::vector<int>>
		input{{1, 2, 3}, {2, 4, 5}, {1, 3, 7}, {3, 4, 5}, {1, 5, 1}, {6, 7, 2}, {6, 8, 2}, {7, 8, 2}};
	int expected_result{-1};
	auto result = find_smallest_edge_in_sub_graph_bfs(input, 1, 6, 10, -1);
	EXPECT_EQ(expected_result, result);
}

TEST(FindShortestEdgeInSubgraph, DFSallconnected1)
{
	std::vector<std::vector<int>> input{{1, 2, 3}, {2, 4, 5}, {1, 3, 7}, {3, 4, 5}, {1, 5, 1}};
	int expected_result{1};
	auto result = find_smallest_edge_in_sub_graph_dfs(input, 1, 5, 10, -1);
	EXPECT_EQ(expected_result, result);
}


TEST(FindShortestEdgeInSubgraph, DFSdisconnected1)
{
	std::vector<std::vector<int>>
		input{{1, 2, 3}, {2, 4, 5}, {1, 3, 7}, {3, 4, 5}, {1, 5, 1}, {6, 7, 2}, {6, 8, 2}, {7, 8, 2}};
	int expected_result{-1};
	auto result = find_smallest_edge_in_sub_graph_dfs(input, 1, 6, 10, -1);
	EXPECT_EQ(expected_result, result);
}
