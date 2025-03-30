//
// Created by andreas on 04.01.23.
//
#include "gtest/gtest.h"
#include "graphs/graph.h"
#include "graphs/breadth_first_search.h"

class SetupBFSGraph : public testing::Test
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

    Graph<int, int> get_graph(int start_vertex_id, GraphNodePtr<int, int>& start_vertex) const
    {
        const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(id1, data1));
        const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(id2, data2));
        const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(id3, data3));
        const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(id4, data4));
        const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(id5, data5));
        const std::shared_ptr<GraphNode<int, int>> vertex6(new GraphNode<int, int>(id6, data6));
        const std::shared_ptr<GraphNode<int, int>> vertex7(new GraphNode<int, int>(id7, data7));
        auto graph = Graph<int, int>();
        graph.add_edge(vertex1, vertex2);
        graph.add_edge(vertex1, vertex3);
        graph.add_edge(vertex2, vertex3);
        graph.add_edge(vertex3, vertex4);
        graph.add_edge(vertex3, vertex5);
        graph.add_edge(vertex5, vertex6);
        graph.add_edge(vertex5, vertex7);
        graph.add_edge(vertex2, vertex6);
        start_vertex = graph.get_vertex_by_id(start_vertex_id);
        return graph;
    }
};


TEST_F(SetupBFSGraph, test_breadth_first_search_start_vertex1)
{
    GraphNodePtr<int, int> start_vertex = nullptr;
    int start_vertex_id = 1;
    auto graph = get_graph(start_vertex_id, start_vertex);
    std::map<int, int> expected_bfs_tree{
        {2, 1},
        {3, 1},
        {4, 3},
        {5, 3},
        {6, 2},
        {7, 5}
    };
    auto bfs_tree = get_breadth_first_search_tree<int, int>(graph, start_vertex);
    EXPECT_EQ(bfs_tree.size(), expected_bfs_tree.size());
    for (const auto& [child, parent] : expected_bfs_tree)
        EXPECT_EQ(parent, bfs_tree[child]);
}

TEST_F(SetupBFSGraph, test_breadth_first_search_start_vertex2)
{
    GraphNodePtr<int, int> start_vertex = nullptr;
    int start_vertex_id = 2;
    auto graph = get_graph(start_vertex_id, start_vertex);
    std::map<int, int> expected_bfs_tree{
        {1, 2},
        {3, 2},
        {6, 2},
        {4, 3},
        {5, 3},
        {7, 5}
    };
    auto bfs_tree = get_breadth_first_search_tree<int, int>(graph, start_vertex);
    EXPECT_EQ(bfs_tree.size(), expected_bfs_tree.size());
    for (const auto& [child, parent] : expected_bfs_tree)
        EXPECT_EQ(parent, bfs_tree[child]);
}

TEST_F(SetupBFSGraph, test_breadth_first_search_start_vertex7)
{
    GraphNodePtr<int, int> start_vertex = nullptr;
    int start_vertex_id = 7;
    auto graph = get_graph(start_vertex_id, start_vertex);
    std::map<int, int> expected_bfs_tree{
        {5, 7},
        {3, 5},
        {6, 5},
        {4, 3},
        {2, 3},
        {1, 3}
    };
    auto bfs_tree = get_breadth_first_search_tree<int, int>(graph, start_vertex);
    EXPECT_EQ(bfs_tree.size(), expected_bfs_tree.size());
    for (const auto& [child, parent] : expected_bfs_tree)
        EXPECT_EQ(parent, bfs_tree[child]);
}
