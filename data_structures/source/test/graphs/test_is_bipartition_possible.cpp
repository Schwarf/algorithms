//
// Created by andreas on 30.12.22.
//

#include "gtest/gtest.h"
#include "./../../graphs/is_bipartition_possible.h"

class SetupBiPartitionPossible: public testing::Test
{
public:
	SetupBiPartitionPossible() = default;
protected:
	int id1 = 1, data1 = 1;
	int id2 = 2, data2 = 2;
	int id3 = 3, data3 = 3;
	int id4 = 4, data4 = 4;
	int id5 = 5, data5 = 5;
};


TEST_F(SetupBiPartitionPossible, test_positive_case)
{
	auto graph = Graph<int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node3);
	graph.add_edge(node1, node4);
	graph.add_edge(node2, node3);
	graph.add_edge(node2, node4);
	EXPECT_TRUE(is_bi_partition_possible(graph));
}


TEST_F(SetupBiPartitionPossible, test_negative_case)
{
	auto graph = Graph<int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	graph.add_edge(node1, node3);
	graph.add_edge(node1, node4);
	graph.add_edge(node2, node3);
	graph.add_edge(node2, node4);
	graph.add_edge(node1, node2);
	EXPECT_FALSE(is_bi_partition_possible(graph));
}

TEST_F(SetupBiPartitionPossible, test_negative_erase_positive)
{
	auto graph = Graph<int, int>();
	const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
	const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
	const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
	const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
	const std::shared_ptr<GraphNode<int, int>> node5(new GraphNode<int, int>(id5, data5));
	graph.add_edge(node1, node3);
	graph.add_edge(node1, node4);
	graph.add_edge(node2, node3);
	graph.add_edge(node2, node4);
	graph.add_edge(node5, node2);
	graph.add_edge(node5, node3);
	EXPECT_FALSE(is_bi_partition_possible(graph));
	graph.erase_node(id5);
	EXPECT_TRUE(is_bi_partition_possible(graph));
}
