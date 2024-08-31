//
// Created by andreas on 31.08.24.
//
#include "gtest/gtest.h"
#include "graphs/path_with_maximum_probability.h"

TEST(TestPathWithMaximumProbabilityBellmanFord, simple1) {
    constexpr int n{3};
    std::vector<std::vector<int>> edges{{0, 1},
                                        {1, 2},
                                        {0, 2}};
    std::vector<double> probabilities{0.5, 0.5, 0.2};
    constexpr int start_node{0};
    constexpr int end_node{2};
    constexpr double expected_result{0.25};
    EXPECT_DOUBLE_EQ(expected_result, max_probability_path_bellman_ford(n, edges, probabilities, start_node, end_node));
}

TEST(TestPathWithMaximumProbabilityBellmanFord, simple2) {
    constexpr int n{3};
    std::vector<std::vector<int>> edges{{0, 1},
                                        {1, 2},
                                        {0, 2}};
    std::vector<double> probabilities{0.5, 0.5, 0.3};
    constexpr int start_node{0};
    constexpr int end_node{2};
    constexpr double expected_result{0.3};
    EXPECT_DOUBLE_EQ(expected_result, max_probability_path_bellman_ford(n, edges, probabilities, start_node, end_node));
}

TEST(TestPathWithMaximumProbabilityBellmanFord, simple3) {
    constexpr int n{3};
    std::vector<std::vector<int>> edges{{0, 1}};
    std::vector<double> probabilities{0.5};
    constexpr int start_node{0};
    constexpr int end_node{2};
    constexpr double expected_result{};
    EXPECT_DOUBLE_EQ(expected_result, max_probability_path_bellman_ford(n, edges, probabilities, start_node, end_node));
}

TEST(TestPathWithMaximumProbabilityBellmanFord, medium1) {
    constexpr int n{10};
    std::vector<std::vector<int>> edges{{3, 5},
                                        {3, 4},
                                        {6, 8},
                                        {1, 5},
                                        {2, 8},
                                        {6, 9},
                                        {0, 2},
                                        {7, 8},
                                        {0, 4},
                                        {3, 7},
                                        {8, 9},
                                        {5, 8},
                                        {3, 6},
                                        {0, 6},
                                        {1, 6},
                                        {0, 1},
                                        {0, 3},
                                        {5, 6},
                                        {1, 9}};
    std::vector<double> probabilities{0.72, 0.81, 0.18, 0.62, 0.96, 0.45, 0.19, 0.77, 0.1, 0.99, 0.49, 0.25, 0.45, 0.68,
                                      0.95, 0.61, 0.11, 0.72, 0.2};
    constexpr int start_node{1};
    constexpr int end_node{6};
    constexpr double expected_result{0.95};
    EXPECT_DOUBLE_EQ(expected_result, max_probability_path_bellman_ford(n, edges, probabilities, start_node, end_node));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestPathWithMaximumProbabilityDijkstra, simple1) {
    constexpr int n{3};
    std::vector<std::vector<int>> edges{{0, 1},
                                        {1, 2},
                                        {0, 2}};
    std::vector<double> probabilities{0.5, 0.5, 0.2};
    constexpr int start_node{0};
    constexpr int end_node{2};
    constexpr double expected_result{0.25};
    EXPECT_DOUBLE_EQ(expected_result, max_probability_path_dijkstra(n, edges, probabilities, start_node, end_node));
}

TEST(TestPathWithMaximumProbabilityDijkstra, simple2) {
    constexpr int n{3};
    std::vector<std::vector<int>> edges{{0, 1},
                                        {1, 2},
                                        {0, 2}};
    std::vector<double> probabilities{0.5, 0.5, 0.3};
    constexpr int start_node{0};
    constexpr int end_node{2};
    constexpr double expected_result{0.3};
    EXPECT_DOUBLE_EQ(expected_result, max_probability_path_dijkstra(n, edges, probabilities, start_node, end_node));
}

TEST(TestPathWithMaximumProbabilityDijkstra, simple3) {
    constexpr int n{3};
    std::vector<std::vector<int>> edges{{0, 1}};
    std::vector<double> probabilities{0.5};
    constexpr int start_node{0};
    constexpr int end_node{2};
    constexpr double expected_result{};
    EXPECT_DOUBLE_EQ(expected_result, max_probability_path_dijkstra(n, edges, probabilities, start_node, end_node));
}

TEST(TestPathWithMaximumProbabilityDijkstra, medium1) {
    constexpr int n{10};
    std::vector<std::vector<int>> edges{{3, 5},
                                        {3, 4},
                                        {6, 8},
                                        {1, 5},
                                        {2, 8},
                                        {6, 9},
                                        {0, 2},
                                        {7, 8},
                                        {0, 4},
                                        {3, 7},
                                        {8, 9},
                                        {5, 8},
                                        {3, 6},
                                        {0, 6},
                                        {1, 6},
                                        {0, 1},
                                        {0, 3},
                                        {5, 6},
                                        {1, 9}};
    std::vector<double> probabilities{0.72, 0.81, 0.18, 0.62, 0.96, 0.45, 0.19, 0.77, 0.1, 0.99, 0.49, 0.25, 0.45, 0.68,
                                      0.95, 0.61, 0.11, 0.72, 0.2};
    constexpr int start_node{1};
    constexpr int end_node{6};
    constexpr double expected_result{0.95};
    EXPECT_DOUBLE_EQ(expected_result, max_probability_path_dijkstra(n, edges, probabilities, start_node, end_node));
}
