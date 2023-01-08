//
// Created by andreas on 30.12.22.
//
#include "gtest/gtest.h"
#include "./../../graphs/weighted_graph.h"

class SetupWeightedGraph: public testing::Test
{
public:
	SetupWeightedGraph() = default;
protected:
	int id1 = 1, data1 = 1, weight1 = 1;
	int id2 = 2, data2 = 2, weight2 = 22;
	int id3 = 3, data3 = 3, weight3 = 33;
	int id4 = 4, data4 = 4, weight4 = 44;
	int id5 = 5, data5 = 5, weight5 = 55;
};

TEST_F(SetupWeightedGraph, test_add_edge_nodes)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2, weight1);
	graph.add_edge(node1, node3, weight1);
	graph.add_edge(node2, node3, weight1);
	EXPECT_EQ(graph.get_node_by_id(id1)->data, data1);
	EXPECT_EQ(graph.get_node_by_id(id2)->data, data2);
	EXPECT_EQ(graph.get_node_by_id(id3)->data, data3);
	EXPECT_EQ(graph.get_node_by_id(id4), nullptr);
}

TEST_F(SetupWeightedGraph, test_weight_for_added_edge_nodes)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2, weight1);
	graph.add_edge(node1, node3, weight2);
	graph.add_edge(node2, node3, weight3);
	EXPECT_EQ(graph.get_edge_weight(node1->id, node2->id), weight1);
	EXPECT_EQ(graph.get_edge_weight(node1->id, node3->id), weight2);
	EXPECT_EQ(graph.get_edge_weight(node2->id, node3->id), weight3);
}

TEST_F(SetupWeightedGraph, test_weight_for_non_existent_edge_nodes)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2, weight1);
	graph.add_edge(node1, node3, weight2);
	graph.add_edge(node2, node3, weight3);
	std::string message = "The node id " + std::to_string(node4->id) + " does not exist in the graph!";
	try {
		graph.get_edge_weight(node1->id, node4->id);
		FAIL() << "Expected std::invalid_argument";
	}
	catch (std::invalid_argument const &err) {
		EXPECT_TRUE(err.what() == message);
	}
}


TEST_F(SetupWeightedGraph, test_weight_for_non_existent_edge)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	graph.add_edge(node1, node2, weight1);
	graph.add_edge(node1, node3, weight2);
	std::string message = "The edge with source id " + std::to_string(node2->id) + " and destination id "
		+ std::to_string(node3->id) + " does not exist in the graph!";

	try {
		graph.get_edge_weight(node2->id, node3->id);
		FAIL() << "Expected std::invalid_argument";
	}
	catch (std::invalid_argument const &err) {
		EXPECT_TRUE(err.what() == message);
	}
}


TEST_F(SetupWeightedGraph, test_get_neighbours_by_node)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2, weight2);
	graph.add_edge(node1, node3, weight2);
	graph.add_edge(node2, node3, weight2);
	auto neighbors_node1 = std::set<int>{node2->id, node3->id};
	auto neighbors_node2 = std::set<int>{node3->id, node1->id};
	auto neighbors_node3 = std::set<int>{node2->id, node1->id};
	EXPECT_EQ(graph.get_neighbors(node1), neighbors_node1);
	EXPECT_EQ(graph.get_neighbors(node2), neighbors_node2);
	EXPECT_EQ(graph.get_neighbors(node3), neighbors_node3);
	EXPECT_TRUE(graph.get_neighbors(node4).empty());
}

TEST_F(SetupWeightedGraph, test_add_vertices_then_nodes)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_vertex(node1);
	graph.add_vertex(node2);
	graph.add_vertex(node3);
	graph.add_edge(node1->id, node2->id, weight3);
	graph.add_edge(node1->id, node3->id, weight3);
	graph.add_edge(node2->id, node3->id, weight3);
	auto neighbors_node1 = std::set<int>{node2->id, node3->id};
	auto neighbors_node2 = std::set<int>{node3->id, node1->id};
	auto neighbors_node3 = std::set<int>{node2->id, node1->id};
	EXPECT_EQ(graph.get_neighbors(node1), neighbors_node1);
	EXPECT_EQ(graph.get_neighbors(node2), neighbors_node2);
	EXPECT_EQ(graph.get_neighbors(node3), neighbors_node3);
	EXPECT_TRUE(graph.get_neighbors(node4).empty());
}


TEST_F(SetupWeightedGraph, test_get_neighbours_by_id)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2, weight4);
	graph.add_edge(node1, node3, weight4);
	graph.add_edge(node2, node3, weight4);
	auto neighbors_node1 = std::set<int>{node2->id, node3->id};
	auto neighbors_node2 = std::set<int>{node3->id, node1->id};
	auto neighbors_node3 = std::set<int>{node2->id, node1->id};
	EXPECT_EQ(graph.get_neighbors(id1), neighbors_node1);
	EXPECT_EQ(graph.get_neighbors(id2), neighbors_node2);
	EXPECT_EQ(graph.get_neighbors(id3), neighbors_node3);
	EXPECT_TRUE(graph.get_neighbors(id4).empty());
}


TEST_F(SetupWeightedGraph, test_size)
{
	auto graph = WeightedGraph<int, int, int>();
	EXPECT_EQ(graph.number_of_vertices(), 0);
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node2, weight5);
	EXPECT_EQ(graph.number_of_vertices(), 2);
	graph.add_edge(node1, node3, weight5);
	EXPECT_EQ(graph.number_of_vertices(), 3);
	graph.add_edge(node1, node4, weight5);
	EXPECT_EQ(graph.number_of_vertices(), 4);
}

TEST_F(SetupWeightedGraph, test_add_node)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	EXPECT_EQ(graph.number_of_vertices(), 0);
	graph.add_edge(node1, node2, weight4);
	EXPECT_EQ(graph.number_of_vertices(), 2);
	graph.add_vertex(node3);
	EXPECT_EQ(graph.number_of_vertices(), 3);
	graph.add_vertex(node4);
	EXPECT_EQ(graph.number_of_vertices(), 4);
}

TEST_F(SetupWeightedGraph, test_erase_node)
{
	auto graph = WeightedGraph<int, int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	const std::shared_ptr<GraphNode<int, int>> node5(new GraphNode<int, int>(id5, data5));
	graph.add_edge(node1, node2, weight1);
	graph.add_vertex(node3);
	graph.add_vertex(node4);
	graph.add_edge(node1, node5, weight2);
	EXPECT_EQ(graph.get_edge_weight(node1->id, node5->id), weight2);
	EXPECT_EQ(graph.number_of_vertices(), 5);
	EXPECT_TRUE(graph.erase_node(id4));
	EXPECT_EQ(graph.number_of_vertices(), 4);
	EXPECT_TRUE(graph.erase_node(id1));
	std::string message = "The node id " + std::to_string(node1->id) + " does not exist in the graph!";
	try {
		graph.get_edge_weight(node5->id, node1->id);
		FAIL() << "Expected std::invalid_argument";
	}
	catch (std::invalid_argument const &err) {
		EXPECT_TRUE(err.what() == message);
	}
	EXPECT_EQ(graph.number_of_vertices(), 3);
	EXPECT_TRUE(graph.get_neighbors(id2).empty());
	EXPECT_TRUE(graph.get_neighbors(id5).empty());
	graph.add_edge(node3, node4, weight4);
	graph.add_edge(node3, node4, weight3);
}
