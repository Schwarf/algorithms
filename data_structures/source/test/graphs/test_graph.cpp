//
// Created by andreas on 30.12.22.
//
#include "gtest/gtest.h"
#include "graphs/graph.h"

class SetupGraph : public testing::Test {
public:
    SetupGraph() = default;

protected:
    int id1 = 1, data1 = 1;
    int id2 = 2, data2 = 2;
    int id3 = 3, data3 = 3;
    int id4 = 4, data4 = 4;
    int id5 = 5, data5 = 5;
    int invalid_id = 10;
};

TEST_F(SetupGraph, test_add_edge_vertexs) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2);
    graph.add_edge(vertex1, vertex3);
    graph.add_edge(vertex2, vertex3);
    EXPECT_EQ(graph.get_vertex_by_id(id1)->data, data1);
    EXPECT_EQ(graph.get_vertex_by_id(id2)->data, data2);
    EXPECT_EQ(graph.get_vertex_by_id(id3)->data, data3);
    EXPECT_EQ(graph.get_vertex_by_id(id4), nullptr);
}

TEST_F(SetupGraph, test_get_neighbours_by_vertex) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2);
    graph.add_edge(vertex1, vertex3);
    graph.add_edge(vertex2, vertex3);
    auto neighbors_vertex1 = std::set<int>{vertex2->id, vertex3->id};
    auto neighbors_vertex2 = std::set<int>{vertex3->id, vertex1->id};
    auto neighbors_vertex3 = std::set<int>{vertex2->id, vertex1->id};
    EXPECT_EQ(graph.get_neighbors(vertex1), neighbors_vertex1);
    EXPECT_EQ(graph.get_neighbors(vertex2), neighbors_vertex2);
    EXPECT_EQ(graph.get_neighbors(vertex3), neighbors_vertex3);
    EXPECT_TRUE(graph.get_neighbors(vertex4).empty());
}

TEST_F(SetupGraph, test_add_vertices_then_vertexs) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_vertex(vertex1);
    graph.add_vertex(vertex2);
    graph.add_vertex(vertex3);
    graph.add_edge(vertex1->id, vertex2->id);
    graph.add_edge(vertex1->id, vertex3->id);
    graph.add_edge(vertex2->id, vertex3->id);
    auto neighbors_vertex1 = std::set<int>{vertex2->id, vertex3->id};
    auto neighbors_vertex2 = std::set<int>{vertex3->id, vertex1->id};
    auto neighbors_vertex3 = std::set<int>{vertex2->id, vertex1->id};
    EXPECT_EQ(graph.get_neighbors(vertex1), neighbors_vertex1);
    EXPECT_EQ(graph.get_neighbors(vertex2), neighbors_vertex2);
    EXPECT_EQ(graph.get_neighbors(vertex3), neighbors_vertex3);
    EXPECT_TRUE(graph.get_neighbors(vertex4).empty());
}


TEST_F(SetupGraph, test_get_neighbours_by_id) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2);
    graph.add_edge(vertex1, vertex3);
    graph.add_edge(vertex2, vertex3);
    auto neighbors_vertex1 = std::set<int>{vertex2->id, vertex3->id};
    auto neighbors_vertex2 = std::set<int>{vertex3->id, vertex1->id};
    auto neighbors_vertex3 = std::set<int>{vertex2->id, vertex1->id};
    EXPECT_EQ(graph.get_neighbors(id1), neighbors_vertex1);
    EXPECT_EQ(graph.get_neighbors(id2), neighbors_vertex2);
    EXPECT_EQ(graph.get_neighbors(id3), neighbors_vertex3);
    EXPECT_TRUE(graph.get_neighbors(id4).empty());
}

TEST_F(SetupGraph, test_get_neighbours_by_id2) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
    graph.add_edge(vertex1, vertex2);
    graph.add_edge(vertex1, vertex3);
    graph.add_vertex(vertex4);
    graph.add_edge(vertex1, vertex5);
    auto neighbors_vertex1 = std::set<int>{vertex2->id, vertex3->id, vertex5->id};
    auto neighbors_vertex2 = std::set<int>{vertex1->id};
    auto neighbors_vertex5 = std::set<int>{vertex1->id};
    EXPECT_EQ(graph.get_neighbors(id1), neighbors_vertex1);
    EXPECT_EQ(graph.get_neighbors(id2), neighbors_vertex2);
    EXPECT_EQ(graph.get_neighbors(id3), neighbors_vertex5);
    EXPECT_TRUE(graph.get_neighbors(id4).empty());
}


TEST_F(SetupGraph, test_size) {
    auto graph = Graph<int, int>();
    EXPECT_EQ(graph.number_of_vertices(), 0);
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2);
    EXPECT_EQ(graph.number_of_vertices(), 2);
    graph.add_edge(vertex1, vertex3);
    EXPECT_EQ(graph.number_of_vertices(), 3);
    graph.add_edge(vertex1, vertex4);
    EXPECT_EQ(graph.number_of_vertices(), 4);
}

TEST_F(SetupGraph, test_add_vertex) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    EXPECT_EQ(graph.number_of_vertices(), 0);
    graph.add_edge(vertex1, vertex2);
    EXPECT_EQ(graph.number_of_vertices(), 2);
    graph.add_vertex(vertex3);
    EXPECT_EQ(graph.number_of_vertices(), 3);
    graph.add_vertex(vertex4);
    EXPECT_EQ(graph.number_of_vertices(), 4);
}

TEST_F(SetupGraph, test_erase_vertex) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
    graph.add_edge(vertex1, vertex2);
    graph.add_vertex(vertex3);
    graph.add_vertex(vertex4);
    graph.add_edge(vertex1, vertex5);
    EXPECT_EQ(graph.number_of_vertices(), 5);
    EXPECT_TRUE(graph.erase_vertex(id4));
    EXPECT_EQ(graph.number_of_vertices(), 4);
    EXPECT_TRUE(graph.erase_vertex(id1));
    EXPECT_EQ(graph.number_of_vertices(), 3);
    EXPECT_TRUE(graph.get_neighbors(id2).empty());
    EXPECT_TRUE(graph.get_neighbors(id5).empty());
    graph.add_edge(vertex3, vertex4);
    graph.add_edge(vertex3, vertex4);
}

TEST_F(SetupGraph, test_does_edge_exist) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
    graph.add_edge(vertex1, vertex2);
    graph.add_vertex(vertex3);
    graph.add_edge(vertex1, vertex5);
    EXPECT_TRUE(graph.does_edge_exist(id1, id2));
    EXPECT_FALSE(graph.does_edge_exist(id1, id3));
    EXPECT_FALSE(graph.does_edge_exist(id4, id5));
    EXPECT_FALSE(graph.does_edge_exist(id3, id5));
    EXPECT_FALSE(graph.does_edge_exist(id1, id3));
}

TEST_F(SetupGraph, test_erase_edge) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
    graph.add_edge(vertex1, vertex2);
    graph.add_vertex(vertex3);
    graph.add_edge(vertex1, vertex5);
    EXPECT_TRUE(graph.does_edge_exist(id1, id2));
    EXPECT_TRUE(graph.erase_edge(id1, id2));
    EXPECT_FALSE(graph.does_edge_exist(id1, id2));
}

TEST_F(SetupGraph, test_invalid_edge1) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    graph.add_vertex(vertex1);
    auto message = "The destination vertex id=" + std::to_string(invalid_id) + " does not exist in the graph!";
    try {
        graph.add_edge(id1, invalid_id);
        FAIL() << "Expected std::invalid_argument.";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_TRUE(err.what() == message);
    }

}

TEST_F(SetupGraph, test_invalid_edge2) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    graph.add_vertex(vertex1);
    auto message = "The source vertex id=" + std::to_string(invalid_id) + " does not exist in the graph!";
    try {
        graph.add_edge(invalid_id, id1);
        FAIL() << "Expected std::invalid_argument.";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_TRUE(err.what() == message);
    }

}
