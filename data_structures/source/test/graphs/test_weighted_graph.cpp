//
// Created by andreas on 30.12.22.
//
#include "gtest/gtest.h"
#include "./../../graphs/weighted_graph.h"

class SetupWeightedGraph : public testing::Test {
public:
    SetupWeightedGraph() = default;

protected:
    int id1 = 1, data1 = 1, weight1 = 1;
    int id2 = 2, data2 = 2, weight2 = 22;
    int id3 = 3, data3 = 3, weight3 = 33;
    int id4 = 4, data4 = 4, weight4 = 44;
    int id5 = 5, data5 = 5, weight5 = 55;
    int weight6 = 66, weight7 = 77, weight8 = 88;

    WeightedGraph<int, int, int> get_graph2(GraphNodePtr<int, int> &start_node) const {
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

    WeightedGraph<int, int, int> get_graph(GraphNodePtr<int, int> &start_node) const {
        WeightedGraph<int, int, int> graph;
        const std::shared_ptr<GraphNode<int, int>> vertex0(new GraphNode<int, int>(0, 0));
        const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(1, 1));
        const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(2, 2));
        const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(3, 3));
        const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(4, 4));
        const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(5, 5));
        const std::shared_ptr<GraphNode<int, int>> vertex6(new GraphNode<int, int>(6, 6));
        const std::shared_ptr<GraphNode<int, int>> vertex7(new GraphNode<int, int>(7, 7));
        const std::shared_ptr<GraphNode<int, int>> vertex8(new GraphNode<int, int>(8, 8));
        graph.add_edge(vertex0, vertex1, 4);
        graph.add_edge(vertex0, vertex7, 8);

        graph.add_edge(vertex1, vertex7, 11);
        graph.add_edge(vertex1, vertex2, 8);

        graph.add_edge(vertex2, vertex8, 2);
        graph.add_edge(vertex2, vertex3, 7);
        graph.add_edge(vertex2, vertex5, 4);

        graph.add_edge(vertex3, vertex4, 9);
        graph.add_edge(vertex3, vertex5, 14);

        graph.add_edge(vertex4, vertex5, 10);

        graph.add_edge(vertex5, vertex6, 2);

        graph.add_edge(vertex6, vertex7, 1);
        graph.add_edge(vertex6, vertex8, 6);

        graph.add_edge(vertex7, vertex8, 7);

        start_node = vertex0;
        return graph;
    }

};

TEST_F(SetupWeightedGraph, test_add_edge_vertexs) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2, weight1);
    graph.add_edge(vertex1, vertex3, weight1);
    graph.add_edge(vertex2, vertex3, weight1);
    EXPECT_EQ(graph.get_vertex_by_id(id1)->data, data1);
    EXPECT_EQ(graph.get_vertex_by_id(id2)->data, data2);
    EXPECT_EQ(graph.get_vertex_by_id(id3)->data, data3);
    EXPECT_EQ(graph.get_vertex_by_id(id4), nullptr);
}

TEST_F(SetupWeightedGraph, test_weight_for_added_edge_vertexs) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2, weight1);
    graph.add_edge(vertex1, vertex3, weight2);
    graph.add_edge(vertex2, vertex3, weight3);
    EXPECT_EQ(graph.get_edge_weight(vertex1->id, vertex2->id), weight1);
    EXPECT_EQ(graph.get_edge_weight(vertex1->id, vertex3->id), weight2);
    EXPECT_EQ(graph.get_edge_weight(vertex2->id, vertex3->id), weight3);
}

TEST_F(SetupWeightedGraph, test_weight_for_non_existent_edge_vertexs) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2, weight1);
    graph.add_edge(vertex1, vertex3, weight2);
    graph.add_edge(vertex2, vertex3, weight3);
    std::string message = "The vertex id " + std::to_string(vertex4->id) + " does not exist in the graph!";
    try {
        graph.get_edge_weight(vertex1->id, vertex4->id);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_TRUE(err.what() == message);
    }
}


TEST_F(SetupWeightedGraph, test_weight_for_non_existent_edge) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    graph.add_edge(vertex1, vertex2, weight1);
    graph.add_edge(vertex1, vertex3, weight2);
    std::string message = "The edge with source id " + std::to_string(vertex2->id) + " and destination id "
                          + std::to_string(vertex3->id) + " does not exist in the graph!";

    try {
        graph.get_edge_weight(vertex2->id, vertex3->id);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_TRUE(err.what() == message);
    }
}


TEST_F(SetupWeightedGraph, test_get_neighbours_by_vertex) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2, weight2);
    graph.add_edge(vertex1, vertex3, weight2);
    graph.add_edge(vertex2, vertex3, weight2);
    auto neighbors_vertex1 = std::set<int>{vertex2->id, vertex3->id};
    auto neighbors_vertex2 = std::set<int>{vertex3->id, vertex1->id};
    auto neighbors_vertex3 = std::set<int>{vertex2->id, vertex1->id};
    EXPECT_EQ(graph.get_neighbors(vertex1), neighbors_vertex1);
    EXPECT_EQ(graph.get_neighbors(vertex2), neighbors_vertex2);
    EXPECT_EQ(graph.get_neighbors(vertex3), neighbors_vertex3);
    EXPECT_TRUE(graph.get_neighbors(vertex4).empty());
}

TEST_F(SetupWeightedGraph, test_add_vertices_then_vertexs) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_vertex(vertex1);
    graph.add_vertex(vertex2);
    graph.add_vertex(vertex3);
    graph.add_edge(vertex1->id, vertex2->id, weight3);
    graph.add_edge(vertex1->id, vertex3->id, weight3);
    graph.add_edge(vertex2->id, vertex3->id, weight3);
    auto neighbors_vertex1 = std::set<int>{vertex2->id, vertex3->id};
    auto neighbors_vertex2 = std::set<int>{vertex3->id, vertex1->id};
    auto neighbors_vertex3 = std::set<int>{vertex2->id, vertex1->id};
    EXPECT_EQ(graph.get_neighbors(vertex1), neighbors_vertex1);
    EXPECT_EQ(graph.get_neighbors(vertex2), neighbors_vertex2);
    EXPECT_EQ(graph.get_neighbors(vertex3), neighbors_vertex3);
    EXPECT_TRUE(graph.get_neighbors(vertex4).empty());
}


TEST_F(SetupWeightedGraph, test_get_neighbours_by_id) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2, weight4);
    graph.add_edge(vertex1, vertex3, weight4);
    graph.add_edge(vertex2, vertex3, weight4);
    auto neighbors_vertex1 = std::set<int>{vertex2->id, vertex3->id};
    auto neighbors_vertex2 = std::set<int>{vertex3->id, vertex1->id};
    auto neighbors_vertex3 = std::set<int>{vertex2->id, vertex1->id};
    EXPECT_EQ(graph.get_neighbors(id1), neighbors_vertex1);
    EXPECT_EQ(graph.get_neighbors(id2), neighbors_vertex2);
    EXPECT_EQ(graph.get_neighbors(id3), neighbors_vertex3);
    EXPECT_TRUE(graph.get_neighbors(id4).empty());
}


TEST_F(SetupWeightedGraph, test_size) {
    auto graph = WeightedGraph<int, int, int>();
    EXPECT_EQ(graph.number_of_vertices(), 0);
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2, weight5);
    EXPECT_EQ(graph.number_of_vertices(), 2);
    graph.add_edge(vertex1, vertex3, weight5);
    EXPECT_EQ(graph.number_of_vertices(), 3);
    graph.add_edge(vertex1, vertex4, weight5);
    EXPECT_EQ(graph.number_of_vertices(), 4);
}

TEST_F(SetupWeightedGraph, test_add_vertex) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    EXPECT_EQ(graph.number_of_vertices(), 0);
    graph.add_edge(vertex1, vertex2, weight4);
    EXPECT_EQ(graph.number_of_vertices(), 2);
    graph.add_vertex(vertex3);
    EXPECT_EQ(graph.number_of_vertices(), 3);
    graph.add_vertex(vertex4);
    EXPECT_EQ(graph.number_of_vertices(), 4);
}

TEST_F(SetupWeightedGraph, test_erase_vertex) {
    auto graph = WeightedGraph<int, int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
    graph.add_edge(vertex1, vertex2, weight1);
    graph.add_vertex(vertex3);
    graph.add_vertex(vertex4);
    graph.add_edge(vertex1, vertex5, weight2);
    EXPECT_EQ(graph.get_edge_weight(vertex1->id, vertex5->id), weight2);
    EXPECT_EQ(graph.number_of_vertices(), 5);
    EXPECT_TRUE(graph.erase_vertex(id4));
    EXPECT_EQ(graph.number_of_vertices(), 4);
    EXPECT_TRUE(graph.erase_vertex(id1));
    std::string message = "The vertex id " + std::to_string(vertex1->id) + " does not exist in the graph!";
    try {
        graph.get_edge_weight(vertex5->id, vertex1->id);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_TRUE(err.what() == message);
    }
    EXPECT_EQ(graph.number_of_vertices(), 3);
    EXPECT_TRUE(graph.get_neighbors(id2).empty());
    EXPECT_TRUE(graph.get_neighbors(id5).empty());
    graph.add_edge(vertex3, vertex4, weight4);
    graph.add_edge(vertex3, vertex4, weight3);
}


TEST_F(SetupWeightedGraph, simple_prim_graph2) {
    GraphNodePtr<int, int> start_node = nullptr;
    auto graph = get_graph2(start_node);
    auto minimum_spanning_tree = graph.compute_minimum_spanning_tree_simple_prim(start_node);
    std::map<int, std::pair<int, int>> expected_minimum_spanning_tree{std::make_pair(1, std::make_pair(0, 2)),
                                                                      std::make_pair(2, std::make_pair(1, 3)),
                                                                      std::make_pair(3, std::make_pair(0, 6)),
                                                                      std::make_pair(4, std::make_pair(1, 5))};
    for (const auto &element: expected_minimum_spanning_tree) {
        EXPECT_EQ(minimum_spanning_tree[element.first], element.second);
    }
}

TEST_F(SetupWeightedGraph, simple_prim_graph) {
    GraphNodePtr<int, int> start_node = nullptr;
    auto graph = get_graph(start_node);
    auto minimum_spanning_tree = graph.compute_minimum_spanning_tree_simple_prim(start_node);
    int expected_total_distance = 37;
    int total_distance{};
    for (const auto &[first, second]: minimum_spanning_tree) {
        total_distance += second.second;
    }
    EXPECT_EQ(total_distance, expected_total_distance);
}

TEST_F(SetupWeightedGraph, test_djikstra) {
    GraphNodePtr<int, int> start_node = nullptr;
    auto graph = get_graph(start_node);
    auto shortest_path = graph.primitive_dijkstra(start_node);
    std::unordered_map<int, int> expected_shortest_paths;
	expected_shortest_paths[2] = 12;
	expected_shortest_paths[3] = 19;
	expected_shortest_paths[4] = 21;
	expected_shortest_paths[5] = 11;
	expected_shortest_paths[6] = 9;
	expected_shortest_paths[7] = 8;
	expected_shortest_paths[8] = 14;

    for (const auto &[key, value]: expected_shortest_paths) {
        EXPECT_EQ(shortest_path[key], value);
    }
}

TEST_F(SetupWeightedGraph, test_djikstra2) {
    GraphNodePtr<int, int> start_node = nullptr;
    auto graph = get_graph2(start_node);
    auto shortest_path = graph.primitive_dijkstra(start_node);
	std::unordered_map<int, int> expected_shortest_paths;
	expected_shortest_paths[2] = 5;
	expected_shortest_paths[3] = 6;
	expected_shortest_paths[4] = 7;
	for (const auto &[key, value]: expected_shortest_paths) {
		EXPECT_EQ(shortest_path[key], value);
	}

}
