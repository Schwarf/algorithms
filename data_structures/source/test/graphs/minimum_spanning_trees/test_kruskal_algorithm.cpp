//
// Created by andreas on 02.08.26.
//

#include "../../../graphs/minimum_spanning_tree/kruskal_algorithm.h"
#include "gtest/gtest.h"

#include <set>
#include <tuple>

namespace
{
using Graph = std::vector<std::vector<std::vector<int>>>;
using UndirectedEdge = std::tuple<int, int, int>;

void add_undirected_edge(Graph& graph, int from, int to, int weight)
{
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

std::set<UndirectedEdge> to_edge_set(const Graph& graph)
{
    std::set<UndirectedEdge> edges;
    for (int from{}; from < static_cast<int>(graph.size()); ++from)
    {
        for (const auto& edge : graph[from])
        {
            const int to = edge[0];
            const int weight = edge[1];
            edges.insert({std::min(from, to), std::max(from, to), weight});
        }
    }
    return edges;
}

int total_weight(const Graph& graph)
{
    int weight{};
    for (const auto& edges : graph)
    {
        for (const auto& edge : edges)
            weight += edge[1];
    }
    return weight / 2;
}

std::size_t number_of_undirected_edges(const Graph& graph)
{
    return to_edge_set(graph).size();
}
}

TEST(KruskalAlgorithm, ComputesMinimumSpanningTreeForConnectedGraph)
{
    Graph graph(5);
    add_undirected_edge(graph, 0, 1, 2);
    add_undirected_edge(graph, 0, 3, 6);
    add_undirected_edge(graph, 1, 2, 3);
    add_undirected_edge(graph, 1, 3, 8);
    add_undirected_edge(graph, 1, 4, 5);
    add_undirected_edge(graph, 2, 4, 7);
    add_undirected_edge(graph, 3, 4, 9);

    const auto mst = kruskal_algorithm(graph);

    EXPECT_EQ(mst.size(), graph.size());
    EXPECT_EQ(number_of_undirected_edges(mst), 4);
    EXPECT_EQ(total_weight(mst), 16);
    EXPECT_EQ(to_edge_set(mst), (std::set<UndirectedEdge>{{0, 1, 2}, {1, 2, 3}, {1, 4, 5}, {0, 3, 6}}));
}

TEST(KruskalAlgorithm, SkipsCycleEdgesAndKeepsCheapestParallelEdge)
{
    Graph graph(4);
    add_undirected_edge(graph, 0, 1, 10);
    add_undirected_edge(graph, 0, 1, 1);
    add_undirected_edge(graph, 1, 2, 2);
    add_undirected_edge(graph, 0, 2, 3);
    add_undirected_edge(graph, 2, 3, 4);
    add_undirected_edge(graph, 0, 3, 100);

    const auto mst = kruskal_algorithm(graph);

    EXPECT_EQ(number_of_undirected_edges(mst), 3);
    EXPECT_EQ(total_weight(mst), 7);
    EXPECT_EQ(to_edge_set(mst), (std::set<UndirectedEdge>{{0, 1, 1}, {1, 2, 2}, {2, 3, 4}}));
}

TEST(KruskalAlgorithm, HandlesNegativeAndZeroWeights)
{
    Graph graph(4);
    add_undirected_edge(graph, 0, 1, -4);
    add_undirected_edge(graph, 1, 2, 0);
    add_undirected_edge(graph, 2, 3, 2);
    add_undirected_edge(graph, 0, 3, 10);
    add_undirected_edge(graph, 0, 2, 3);

    const auto mst = kruskal_algorithm(graph);

    EXPECT_EQ(number_of_undirected_edges(mst), 3);
    EXPECT_EQ(total_weight(mst), -2);
    EXPECT_EQ(to_edge_set(mst), (std::set<UndirectedEdge>{{0, 1, -4}, {1, 2, 0}, {2, 3, 2}}));
}

TEST(KruskalAlgorithm, HandlesDisconnectedGraphAsMinimumSpanningForest)
{
    Graph graph(6);
    add_undirected_edge(graph, 0, 1, 4);
    add_undirected_edge(graph, 1, 2, 1);
    add_undirected_edge(graph, 0, 2, 7);
    add_undirected_edge(graph, 3, 4, 2);

    const auto mst = kruskal_algorithm(graph);

    EXPECT_EQ(mst.size(), graph.size());
    EXPECT_EQ(number_of_undirected_edges(mst), 3);
    EXPECT_EQ(total_weight(mst), 7);
    EXPECT_TRUE(mst[5].empty());
    EXPECT_EQ(to_edge_set(mst), (std::set<UndirectedEdge>{{1, 2, 1}, {3, 4, 2}, {0, 1, 4}}));
}

TEST(KruskalAlgorithm, HandlesEmptyGraph)
{
    Graph graph;

    const auto mst = kruskal_algorithm(graph);

    EXPECT_TRUE(mst.empty());
}

TEST(KruskalAlgorithm, HandlesSingleVertexGraph)
{
    Graph graph(1);

    const auto mst = kruskal_algorithm(graph);

    EXPECT_EQ(mst.size(), 1);
    EXPECT_TRUE(mst[0].empty());
}

TEST(KruskalAlgorithm, IgnoresSelfLoops)
{
    Graph graph(3);
    graph[0].push_back({0, -100});
    graph[1].push_back({1, -50});
    add_undirected_edge(graph, 0, 1, 5);
    add_undirected_edge(graph, 1, 2, 6);
    add_undirected_edge(graph, 0, 2, 20);

    const auto mst = kruskal_algorithm(graph);

    EXPECT_EQ(number_of_undirected_edges(mst), 2);
    EXPECT_EQ(total_weight(mst), 11);
    EXPECT_EQ(to_edge_set(mst), (std::set<UndirectedEdge>{{0, 1, 5}, {1, 2, 6}}));
}
