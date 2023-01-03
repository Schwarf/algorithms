//
// Created by andreas on 30.12.22.
//
#include "gtest/gtest.h"
#include "./../../graphs/does_path_in_graph_exist.h"

class SetupDoesPathExist: public testing::Test
{
public:
	SetupDoesPathExist() = default;
protected:
	int id1 = 1, data1 = 1;
	int id2 = 2, data2 = 2;
	int id3 = 3, data3 = 3;
	int id4 = 4, data4 = 4;
	int id5 = 5, data5 = 5;
};

TEST_F(SetupDoesPathExist, test_simple_case)
{
	auto graph = BidirectionalGraph<int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2);
	graph.add_edge(node1, node3);
	graph.add_edge(node2, node3);
	EXPECT_TRUE(does_path_exist(graph, node1, node2));
	EXPECT_TRUE(does_path_exist(graph, node2, node1));
	EXPECT_TRUE(does_path_exist(graph, node1, node3));
	EXPECT_TRUE(does_path_exist(graph, node3, node2));
	EXPECT_TRUE(does_path_exist(graph, node2, node3));
	EXPECT_TRUE(does_path_exist(graph, node3, node2));
	EXPECT_FALSE(does_path_exist(graph, node1, node4));
	EXPECT_FALSE(does_path_exist(graph, node2, node4));
	EXPECT_FALSE(does_path_exist(graph, node3, node4));
	EXPECT_FALSE(does_path_exist(graph, node4, node1));
	EXPECT_FALSE(does_path_exist(graph, node4, node2));
	EXPECT_FALSE(does_path_exist(graph, node4, node3));
	graph.add_vertex(node4);
	EXPECT_FALSE(does_path_exist(graph, node1, node4));
	EXPECT_FALSE(does_path_exist(graph, node2, node4));
	EXPECT_FALSE(does_path_exist(graph, node3, node4));
	EXPECT_FALSE(does_path_exist(graph, node4, node1));
	EXPECT_FALSE(does_path_exist(graph, node4, node2));
	EXPECT_FALSE(does_path_exist(graph, node4, node3));
}

TEST_F(SetupDoesPathExist, test_case_with_erase)
{
	auto graph = BidirectionalGraph<int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	const std::shared_ptr<GraphNode<int, int>> node5(new GraphNode<int, int>(id5, data5));
	graph.add_edge(node1, node2);
	graph.add_edge(node1, node3);
	graph.add_edge(node3, node4);
	graph.add_edge(node4, node5);
	EXPECT_TRUE(does_path_exist(graph, node1, node2));
	EXPECT_TRUE(does_path_exist(graph, node2, node1));
	EXPECT_TRUE(does_path_exist(graph, node1, node3));
	EXPECT_TRUE(does_path_exist(graph, node2, node3));
	EXPECT_TRUE(does_path_exist(graph, node1, node5));
	EXPECT_TRUE(does_path_exist(graph, node2, node5));
	EXPECT_TRUE(does_path_exist(graph, node3, node5));
	EXPECT_TRUE(does_path_exist(graph, node5, node1));
	EXPECT_TRUE(does_path_exist(graph, node5, node2));
	EXPECT_TRUE(does_path_exist(graph, node5, node3));
	EXPECT_TRUE(does_path_exist(graph, node5, node4));
	EXPECT_TRUE(does_path_exist(graph, node4, node5));

	graph.erase_node(id3);
	EXPECT_FALSE(does_path_exist(graph, node1, node5));
	EXPECT_FALSE(does_path_exist(graph, node2, node5));
	EXPECT_FALSE(does_path_exist(graph, node5, node1));
	EXPECT_FALSE(does_path_exist(graph, node5, node2));
	EXPECT_FALSE(does_path_exist(graph, node1, node4));
	EXPECT_FALSE(does_path_exist(graph, node2, node4));
	EXPECT_FALSE(does_path_exist(graph, node4, node1));
	EXPECT_FALSE(does_path_exist(graph, node4, node2));

	EXPECT_TRUE(does_path_exist(graph, node4, node5));
	EXPECT_TRUE(does_path_exist(graph, node5, node4));
	EXPECT_TRUE(does_path_exist(graph, node1, node2));
	EXPECT_TRUE(does_path_exist(graph, node2, node1));

}
