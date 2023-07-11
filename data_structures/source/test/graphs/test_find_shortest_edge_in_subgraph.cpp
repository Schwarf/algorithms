//
// Created by andreas on 22.03.23.
//
#include "gtest/gtest.h"
#include "graphs/find_smallest_edge_in_subgraph.h"

TEST(FindShortestEdgeInSubgraph, BFSallconnected1) {
    std::vector<std::vector<unsigned int>> input{{1, 2, 3},
                                                 {2, 4, 5},
                                                 {1, 3, 7},
                                                 {3, 4, 5},
                                                 {1, 5, 1}};
    unsigned int start_vertex{1};
    unsigned int end_vertex{5};
    unsigned int max_edge_value{10};
    unsigned int not_connected_value{10000};
    unsigned int expected_result{1};
    auto result =
            find_smallest_edge_in_sub_graph_bfs(input, start_vertex, end_vertex, max_edge_value, not_connected_value);
    EXPECT_EQ(expected_result, result);
}


TEST(FindShortestEdgeInSubgraph, BFSdisconnected1) {
    std::vector<std::vector<unsigned int>>
            input{{1, 2, 3},
                  {2, 4, 5},
                  {1, 3, 7},
                  {3, 4, 5},
                  {1, 5, 1},
                  {6, 7, 2},
                  {6, 8, 2},
                  {7, 8, 2}};
    unsigned int start_vertex{1};
    unsigned int end_vertex{6};
    unsigned int max_edge_value{10};
    unsigned int not_connected_value{10000};

    unsigned int expected_result{10000};
    auto result =
            find_smallest_edge_in_sub_graph_bfs(input, start_vertex, end_vertex, max_edge_value, not_connected_value);
    EXPECT_EQ(expected_result, result);
}

TEST(FindShortestEdgeInSubgraph, DFSallconnected1) {
    std::vector<std::vector<unsigned int>> input{{1, 2, 3},
                                                 {2, 4, 5},
                                                 {1, 3, 7},
                                                 {3, 4, 5},
                                                 {1, 5, 1}};

    unsigned int start_vertex{1};
    unsigned int end_vertex{5};
    unsigned int max_edge_value{10};
    unsigned int not_connected_value{10000};
    unsigned int expected_result{1};
    auto result =
            find_smallest_edge_in_sub_graph_dfs(input, start_vertex, end_vertex, max_edge_value, not_connected_value);
    EXPECT_EQ(expected_result, result);
}


TEST(FindShortestEdgeInSubgraph, DFSdisconnected1) {
    std::vector<std::vector<unsigned int>>
            input{{1, 2, 3},
                  {2, 4, 5},
                  {1, 3, 7},
                  {3, 4, 5},
                  {1, 5, 1},
                  {6, 7, 2},
                  {6, 8, 2},
                  {7, 8, 2}};
    unsigned int start_vertex{1};
    unsigned int end_vertex{6};
    unsigned int max_edge_value{10};
    unsigned int not_connected_value{10000};

    unsigned int expected_result{10000};
    auto result =
            find_smallest_edge_in_sub_graph_dfs(input, start_vertex, end_vertex, max_edge_value, not_connected_value);
    EXPECT_EQ(expected_result, result);
}

TEST(FindShortestEdgeInSubgraph, DFSrecursiveallconnected1) {
    std::vector<std::vector<unsigned int>> input{{1, 2, 3},
                                                 {2, 4, 5},
                                                 {1, 3, 7},
                                                 {3, 4, 5},
                                                 {1, 5, 1}};

    unsigned int start_vertex{1};
    unsigned int end_vertex{5};
    unsigned int max_edge_value{10};
    unsigned int not_connected_value{10000};
    unsigned int expected_result{1};
    auto result = find_smallest_edge_in_sub_graph_dfs_recursive(input,
                                                                start_vertex,
                                                                end_vertex,
                                                                max_edge_value,
                                                                not_connected_value);
    EXPECT_EQ(expected_result, result);
}


TEST(FindShortestEdgeInSubgraph, DFSrecursivedisconnected1) {
    std::vector<std::vector<unsigned int>>
            input{{1, 2, 3},
                  {2, 4, 5},
                  {1, 3, 7},
                  {3, 4, 5},
                  {1, 5, 1},
                  {6, 7, 2},
                  {6, 8, 2},
                  {7, 8, 2}};

    unsigned int start_vertex{1};
    unsigned int end_vertex{6};
    unsigned int max_edge_value{10};
    unsigned int not_connected_value{10000};
    unsigned int expected_result{10000};
    auto result = find_smallest_edge_in_sub_graph_dfs_recursive(input,
                                                                start_vertex,
                                                                end_vertex,
                                                                max_edge_value,
                                                                not_connected_value);
    EXPECT_EQ(expected_result, result);
}