//
// Created by andreas on 14.12.24.
//

#ifndef LEFT_RIGHT_PLANARITY_TEST_H
#define LEFT_RIGHT_PLANARITY_TEST_H
#include <optional>
#include "graphs/graph.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <vector>
#include <utility> /

struct EdgeHash
{
    template <typename T>
    std::size_t operator()(const std::pair<T, T>& edge) const
    {
        return std::hash<T>()(edge.first) ^ std::hash<T>()(edge.second);
    }
};


template <typename NodeType>
requires std::is_signed_v<NodeType>
class PlanarityTest {
    using Edge = std::pair<NodeType, NodeType>; // Define an edge type for convenience

public:
    explicit PlanarityTest(const UndirectedGraph<NodeType>& graph)
           : graph(graph)
    {
        auto nodes = graph.get_all_nodes();

        // Initialize `height` for all nodes
        for (const auto& node : nodes) {
            height[node] = std::numeric_limits<int>::max(); // Initialize as unvisited (∞)
        }

        // Initialize `lowpt`, `lowpt2`, and `nesting_depth` for all edges
        for (const auto& node : nodes) {
            for (const auto& neighbor : graph.get_neighbors(node)) {
                Edge edge = make_edge(node, neighbor);
                lowpt[edge] = std::numeric_limits<int>::max();
                lowpt2[edge] = std::numeric_limits<int>::max();
                nesting_depth[edge] = 0; // Default to 0
            }
        }
    }





    // void update_lowpoints(NodeType u, NodeType v, int depth) {
    //     Edge edge = make_edge(u, v);
    //     if (lowpt[edge] > depth) {
    //         lowpt2[edge] = lowpt[edge];
    //         lowpt[edge] = depth;
    //     } else if (lowpt2[edge] > depth) {
    //         lowpt2[edge] = depth;
    //     }
    // }

private:
    const UndirectedGraph<NodeType>& graph;

    // Variables corresponding to the table
    std::unordered_map<NodeType, int> height;               // Height of each node
    std::unordered_map<Edge, int, EdgeHash> lowpt; // Lowpoint of each edge
    std::unordered_map<Edge, int, EdgeHash> lowpt2; // Second-lowest point
    std::unordered_map<Edge, int, EdgeHash> nesting_depth; // Nesting depth
};




#endif //LEFT_RIGHT_PLANARITY_TEST_H
