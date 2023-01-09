//
// Created by andreas on 08.01.23.
//

#ifndef TEST_PRIM_ALGORITHM_CPP
#define TEST_PRIM_ALGORITHM_CPP
#include "gtest/gtest.h"
#include "./../../graphs/weighted_graph.h"
#include "./../../graphs/simple_prim_algorithm.h"

class SetupPrimAlgorithmTest: public testing::Test
{
public:
	SetupPrimAlgorithmTest() = default;
protected:
	int id1 = 1, data1 = 1, weight1 = 1;
	int id2 = 2, data2 = 2, weight2 = 22;
	int id3 = 3, data3 = 3, weight3 = 33;
	int id4 = 4, data4 = 4, weight4 = 44;
	int id5 = 5, data5 = 5, weight5 = 55;
	int weight6 = 66, weight7 = 77, weight8 = 88;
	WeightedGraph<int, int, int> get_graph1(GraphNodePtr<int, int> &start_node) const
	{
		WeightedGraph<int, int, int> graph;
		const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
		const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
		const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
		const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
		const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
		graph.add_edge(vertex1, vertex2, weight1);
		graph.add_edge(vertex1, vertex3, weight2);
		graph.add_edge(vertex2, vertex3, weight3);
		graph.add_edge(vertex2, vertex4, weight4);
		graph.add_edge(vertex3, vertex5, weight5);
		graph.add_edge(vertex5, vertex1, weight6);
		start_node = vertex1;
		return graph;
	}
	WeightedGraph<int, int, int> get_graph2(GraphNodePtr<int, int> &start_node) const
	{
		WeightedGraph<int, int, int> graph;
		const std::shared_ptr<GraphNode<int, int>> vertex0(new GraphNode<int, int>(0, 0));
		const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(1, 1));
		const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(2, 2));
		const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(3, 3));
		const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(4, 4));
		graph.add_edge(vertex0, vertex1, 2);
		graph.add_edge(vertex1, vertex2, 3);
		graph.add_edge(vertex0, vertex3, 6);
		graph.add_edge(vertex1, vertex4, 5);
		graph.add_edge(vertex1, vertex3, 8);
		graph.add_edge(vertex2, vertex4, 7);
		graph.add_edge(vertex3, vertex4, 9);
		start_node = vertex0;
		return graph;
	}

};

TEST_F(SetupPrimAlgorithmTest, simple_prim_graph2)
{
	GraphNodePtr<int, int> start_node = nullptr;
	auto graph = get_graph2(start_node);
	auto minimum_spanning_tree = simple_prim_algorithm(graph, start_node, 10000);
	EXPECT_EQ(1, 2);
}
#endif //TEST_PRIM_ALGORITHM_CPP
