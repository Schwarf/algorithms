//
// Created by andreas on 04.01.23.
//
#include "gtest/gtest.h"
#include "./../../graphs/graph.h"
#include "./../../graphs/breadth_first_search.h"
class SetupGraph: public testing::Test
{
public:
	SetupGraph() = default;
protected:
	int id1 = 1, data1 = 1;
	int id2 = 2, data2 = 2;
	int id3 = 3, data3 = 3;
	int id4 = 4, data4 = 4;
	int id5 = 5, data5 = 5;
	int id6 = 6, data6 = 6;
	int id7 = 7, data7 = 7;
};


TEST_F(SetupGraph, test_breadth_first_search)
{
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	const std::shared_ptr<GraphNode<int, int>> node5(new GraphNode<int, int>(id5, data5));
	const std::shared_ptr<GraphNode<int, int>> node6(new GraphNode<int, int>(id6, data6));
	const std::shared_ptr<GraphNode<int, int>> node7(new GraphNode<int, int>(id7, data7));
	auto graph = BidirectionalGraph<int, int>();
	graph.add_edge(node1, node2);
	graph.add_edge(node1, node3);
	graph.add_edge(node2, node3);
	graph.add_edge(node3, node4);
	graph.add_edge(node3, node5);
	graph.add_edge(node5, node6);
	graph.add_edge(node5, node7);
	graph.add_edge(node2, node6);
	std::map<int, int> expected_parents {{2,1}, {3, 1}, {4, 3}, {5, 3}, {6, 2}, {7, 5}};
	auto parents = breadth_first_search<int, int>(graph, node1);
	for(const auto & [child, parent] : expected_parents)
		EXPECT_EQ(parent, parents[child]);
}