//
// Created by andreas on 12.11.23.
//
#include "gtest/gtest.h"
#include "graphs/design_graph_with_shortest_path_calculator.h"

// These tests are bad because they test 3 methods per test ... .
TEST(TestDesignGraphWithShortestPathCalculator, simpleDijkstra1)
{
	constexpr int number_of_nodes{4};
	std::vector<std::vector<short>> edges{{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
	constexpr short expected_shortest_path_3_to_2{6};
	constexpr short expected_shortest_path_0_to_3{-1};

	Graph graph(number_of_nodes, edges);
	EXPECT_EQ(expected_shortest_path_3_to_2, graph.shortest_path(3, 2));
	EXPECT_EQ(expected_shortest_path_0_to_3, graph.shortest_path(0, 3));
	graph.add_edge({1, 3, 4});
	constexpr short new_expected_shortest_path_0_to_3 = expected_shortest_path_3_to_2;
	EXPECT_EQ(new_expected_shortest_path_0_to_3, graph.shortest_path(0, 3));
	EXPECT_EQ(0, graph.shortest_path(3, 3));
}

TEST(TestDesignGraphWithShortestPathCalculator, complexDijkstra1)
{
	constexpr int number_of_nodes{13};
	std::vector<std::vector<int>> edges
		{{7, 2, 131570}, {9, 4, 622890}, {9, 1, 812365}, {1, 3, 399349}, {10, 2, 407736}, {6, 7, 880509},
		 {1, 4, 289656}, {8, 0, 802664}, {6, 4, 826732}, {10, 3, 567982}, {5, 6, 434340}, {4, 7, 833968},
		 {12, 1, 578047}, {8, 5, 739814}, {10, 9, 648073}, {1, 6, 679167}, {3, 6, 933017}, {0, 10, 399226},
		 {1, 11, 915959}, {0, 12, 393037}, {11, 5, 811057}, {6, 2, 100832}, {5, 1, 731872}, {3, 8, 741455},
		 {2, 9, 835397}, {7, 0, 516610}, {11, 8, 680504}, {3, 11, 455056}, {1, 0, 252721}};
	Graph graph(number_of_nodes, edges);
	constexpr int expected_shortest_path_9_to_3{1211714};
	EXPECT_EQ(expected_shortest_path_9_to_3, graph.shortest_path(9, 3));
	graph.add_edge({11, 1, 873094});
	constexpr int expected_shortest_path_3_to_10{1943345};
	EXPECT_EQ(expected_shortest_path_3_to_10, graph.shortest_path(3, 10));
	EXPECT_EQ(407736, graph.shortest_path(10, 2));
}

TEST(TestDesignGraphWithShortestPathCalculator, simpleFloydWarshall1)
{
	constexpr int number_of_nodes{4};
	std::vector<std::vector<short>> edges{{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
	constexpr short expected_shortest_path_3_to_2{6};
	constexpr short expected_shortest_path_0_to_3{-1};

	GraphFW graph(number_of_nodes, edges);
	EXPECT_EQ(expected_shortest_path_3_to_2, graph.shortest_path(3, 2));
	EXPECT_EQ(expected_shortest_path_0_to_3, graph.shortest_path(0, 3));
	graph.add_edge({1, 3, 4});
	constexpr short new_expected_shortest_path_0_to_3 = expected_shortest_path_3_to_2;
	EXPECT_EQ(new_expected_shortest_path_0_to_3, graph.shortest_path(0, 3));
	EXPECT_EQ(0, graph.shortest_path(3, 3));
}

TEST(TestDesignGraphWithShortestPathCalculator, complexFloydWarshall1)
{
	constexpr int number_of_nodes{13};
	std::vector<std::vector<int>> edges
		{{7, 2, 131570}, {9, 4, 622890}, {9, 1, 812365}, {1, 3, 399349}, {10, 2, 407736}, {6, 7, 880509},
		 {1, 4, 289656}, {8, 0, 802664}, {6, 4, 826732}, {10, 3, 567982}, {5, 6, 434340}, {4, 7, 833968},
		 {12, 1, 578047}, {8, 5, 739814}, {10, 9, 648073}, {1, 6, 679167}, {3, 6, 933017}, {0, 10, 399226},
		 {1, 11, 915959}, {0, 12, 393037}, {11, 5, 811057}, {6, 2, 100832}, {5, 1, 731872}, {3, 8, 741455},
		 {2, 9, 835397}, {7, 0, 516610}, {11, 8, 680504}, {3, 11, 455056}, {1, 0, 252721}};
	GraphFW graph(number_of_nodes, edges);
	constexpr int expected_shortest_path_9_to_3{1211714};
	EXPECT_EQ(expected_shortest_path_9_to_3, graph.shortest_path(9, 3));
	graph.add_edge({11, 1, 873094});
	constexpr int expected_shortest_path_3_to_10{1943345};
	EXPECT_EQ(expected_shortest_path_3_to_10, graph.shortest_path(3, 10));
	EXPECT_EQ(407736, graph.shortest_path(10, 2));
}