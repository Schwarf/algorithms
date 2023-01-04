//
// Created by andreas on 04.01.23.
//
#include "gtest/gtest.h"
#include "./../../graphs/graph.h"
#include "./../../graphs/breadth_first_search.h"
class SetupBFSGraph: public testing::Test
{
public:
	SetupBFSGraph() = default;
protected:
	int id1 = 1, data1 = 1;
	int id2 = 2, data2 = 2;
	int id3 = 3, data3 = 3;
	int id4 = 4, data4 = 4;
	int id5 = 5, data5 = 5;
	int id6 = 6, data6 = 6;
	int id7 = 7, data7 = 7;
	Graph<int, int> get_graph(int start_node_id, GraphNodePtr<int, int> &start_node) const
	{
		const std::shared_ptr<GraphNode<int, int>> node1(new GraphNode<int, int>(id1, data1));
		const std::shared_ptr<GraphNode<int, int>> node2(new GraphNode<int, int>(id2, data2));
		const std::shared_ptr<GraphNode<int, int>> node3(new GraphNode<int, int>(id3, data3));
		const std::shared_ptr<GraphNode<int, int>> node4(new GraphNode<int, int>(id4, data4));
		const std::shared_ptr<GraphNode<int, int>> node5(new GraphNode<int, int>(id5, data5));
		const std::shared_ptr<GraphNode<int, int>> node6(new GraphNode<int, int>(id6, data6));
		const std::shared_ptr<GraphNode<int, int>> node7(new GraphNode<int, int>(id7, data7));
		auto graph = Graph<int, int>();
		graph.add_edge(node1, node2);
		graph.add_edge(node1, node3);
		graph.add_edge(node2, node3);
		graph.add_edge(node3, node4);
		graph.add_edge(node3, node5);
		graph.add_edge(node5, node6);
		graph.add_edge(node5, node7);
		graph.add_edge(node2, node6);
		start_node = graph.get_node_by_id(start_node_id);
		return graph;
	}
};


TEST_F(SetupBFSGraph, test_breadth_first_search_start_node1)
{
	GraphNodePtr<int, int> start_node = nullptr;
	int start_node_id = 1;
	auto graph = get_graph(start_node_id, start_node);
	std::map<int, int> expected_parents{{2, 1}, {3, 1}, {4, 3}, {5, 3}, {6, 2}, {7, 5}};
	auto parents = breadth_first_search<int, int>(graph, start_node);
	for (const auto &[child, parent]: expected_parents)
		EXPECT_EQ(parent, parents[child]);
}

TEST_F(SetupBFSGraph, test_breadth_first_search_start_node2)
{
	GraphNodePtr<int, int> start_node = nullptr;
	int start_node_id = 2;
	auto graph = get_graph(start_node_id, start_node);
	std::map<int, int> expected_parents{{1, 2}, {3, 2}, {6, 2}, {4, 3}, {5, 3}, {7, 5}};
	auto parents = breadth_first_search<int, int>(graph, start_node);
	for (const auto &[child, parent]: expected_parents)
		EXPECT_EQ(parent, parents[child]);
}

TEST_F(SetupBFSGraph, test_breadth_first_search_start_node7)
{
	GraphNodePtr<int, int> start_node = nullptr;
	int start_node_id = 7;
	auto graph = get_graph(start_node_id, start_node);
	std::map<int, int> expected_parents{{5, 7}, {3, 5}, {6, 5}, {4, 3}, {2, 3}, {1, 3}};
	auto parents = breadth_first_search<int, int>(graph, start_node);
	for (const auto &[child, parent]: expected_parents)
		EXPECT_EQ(parent, parents[child]);
}