//
// Created by andreas on 30.12.22.
//
#include "gtest/gtest.h"
#include "graphs/does_path_in_graph_exist.h"

class SetupDoesPathExist : public testing::Test {
public:
    SetupDoesPathExist() = default;

protected:
    int id1 = 1, data1 = 1;
    int id2 = 2, data2 = 2;
    int id3 = 3, data3 = 3;
    int id4 = 4, data4 = 4;
    int id5 = 5, data5 = 5;
};

TEST_F(SetupDoesPathExist, test_simple_case) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    graph.add_edge(vertex1, vertex2);
    graph.add_edge(vertex1, vertex3);
    graph.add_edge(vertex2, vertex3);
    EXPECT_TRUE(does_path_exist(graph, vertex1, vertex2));
    EXPECT_TRUE(does_path_exist(graph, vertex2, vertex1));
    EXPECT_TRUE(does_path_exist(graph, vertex1, vertex3));
    EXPECT_TRUE(does_path_exist(graph, vertex3, vertex2));
    EXPECT_TRUE(does_path_exist(graph, vertex2, vertex3));
    EXPECT_TRUE(does_path_exist(graph, vertex3, vertex2));
    EXPECT_FALSE(does_path_exist(graph, vertex1, vertex4));
    EXPECT_FALSE(does_path_exist(graph, vertex2, vertex4));
    EXPECT_FALSE(does_path_exist(graph, vertex3, vertex4));
    EXPECT_FALSE(does_path_exist(graph, vertex4, vertex1));
    EXPECT_FALSE(does_path_exist(graph, vertex4, vertex2));
    EXPECT_FALSE(does_path_exist(graph, vertex4, vertex3));
    graph.add_vertex(vertex4);
    EXPECT_FALSE(does_path_exist(graph, vertex1, vertex4));
    EXPECT_FALSE(does_path_exist(graph, vertex2, vertex4));
    EXPECT_FALSE(does_path_exist(graph, vertex3, vertex4));
    EXPECT_FALSE(does_path_exist(graph, vertex4, vertex1));
    EXPECT_FALSE(does_path_exist(graph, vertex4, vertex2));
    EXPECT_FALSE(does_path_exist(graph, vertex4, vertex3));
}

TEST_F(SetupDoesPathExist, test_case_with_erase) {
    auto graph = Graph<int, int>();
    const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
    const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
    const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
    const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
    const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
    graph.add_edge(vertex1, vertex2);
    graph.add_edge(vertex1, vertex3);
    graph.add_edge(vertex3, vertex4);
    graph.add_edge(vertex4, vertex5);
    EXPECT_TRUE(does_path_exist(graph, vertex1, vertex2));
    EXPECT_TRUE(does_path_exist(graph, vertex2, vertex1));
    EXPECT_TRUE(does_path_exist(graph, vertex1, vertex3));
    EXPECT_TRUE(does_path_exist(graph, vertex2, vertex3));
    EXPECT_TRUE(does_path_exist(graph, vertex1, vertex5));
    EXPECT_TRUE(does_path_exist(graph, vertex2, vertex5));
    EXPECT_TRUE(does_path_exist(graph, vertex3, vertex5));
    EXPECT_TRUE(does_path_exist(graph, vertex5, vertex1));
    EXPECT_TRUE(does_path_exist(graph, vertex5, vertex2));
    EXPECT_TRUE(does_path_exist(graph, vertex5, vertex3));
    EXPECT_TRUE(does_path_exist(graph, vertex5, vertex4));
    EXPECT_TRUE(does_path_exist(graph, vertex4, vertex5));

    graph.erase_vertex(id3);
    EXPECT_FALSE(does_path_exist(graph, vertex1, vertex5));
    EXPECT_FALSE(does_path_exist(graph, vertex2, vertex5));
    EXPECT_FALSE(does_path_exist(graph, vertex5, vertex1));
    EXPECT_FALSE(does_path_exist(graph, vertex5, vertex2));
    EXPECT_FALSE(does_path_exist(graph, vertex1, vertex4));
    EXPECT_FALSE(does_path_exist(graph, vertex2, vertex4));
    EXPECT_FALSE(does_path_exist(graph, vertex4, vertex1));
    EXPECT_FALSE(does_path_exist(graph, vertex4, vertex2));

    EXPECT_TRUE(does_path_exist(graph, vertex4, vertex5));
    EXPECT_TRUE(does_path_exist(graph, vertex5, vertex4));
    EXPECT_TRUE(does_path_exist(graph, vertex1, vertex2));
    EXPECT_TRUE(does_path_exist(graph, vertex2, vertex1));

}
