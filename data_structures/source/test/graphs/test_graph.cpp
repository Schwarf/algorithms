//
// Created by andreas on 30.12.22.
//
#include "gtest/gtest.h"
#include "./../../graphs/graph.h"

class SetupBidirectionalGraph: public testing::Test
{
public:
	SetupBidirectionalGraph() = default;
protected:
	int id1 = 1, data1 = 1;
	int id2 = 2, data2 = 2;
	int id3 = 3, data3 = 3;
	int id4 = 4, data4 = 4;

};

TEST_F(SetupBidirectionalGraph, test_add_edge)
{
	auto graph = BidirectionalGraph<int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2);
	graph.add_edge(node1, node3);
	graph.add_edge(node2, node3);
	EXPECT_EQ(graph.get_node_by_id(id1)->data, data1);
	EXPECT_EQ(graph.get_node_by_id(id2)->data, data2);
	EXPECT_EQ(graph.get_node_by_id(id3)->data, data3);
	EXPECT_EQ(graph.get_node_by_id(id4), nullptr);
}

TEST_F(SetupBidirectionalGraph, test_get_neighbours)
{
	auto graph = BidirectionalGraph<int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2);
	graph.add_edge(node1, node3);
	graph.add_edge(node2, node3);
	auto neighbors_node1 = std::vector<std::shared_ptr<GraphNode<int, int> >>{node2, node3};
	auto neighbors_node2 = std::vector<std::shared_ptr<GraphNode<int, int> >>{node3, node1};
	EXPECT_EQ(graph.get_neighbors(node1), neighbors_node1);
	EXPECT_EQ(graph.get_neighbors(node2), neighbors_node2);
}