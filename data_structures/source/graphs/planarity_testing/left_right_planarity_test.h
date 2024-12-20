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
std::pair<NodeType, NodeType> make_edge(NodeType u, NodeType v)
{
    return std::make_pair(u, v);
}


template <typename NodeType>
    requires std::is_signed_v<NodeType>
class PlanarityTest
{
    using Edge = std::pair<NodeType, NodeType>; // Define an edge type for convenience
    constexpr auto lowpt_not_assigned = std::numeric_limits<int>::min();
    constexpr auto no_parent = std::numeric_limits<NodeType>::max();
    constexpr auto invalid_height = std::numeric_limits<int>::max();
public:
    explicit PlanarityTest(const UndirectedGraph<NodeType>& graph)
        : graph(graph)
    {
        auto nodes = graph.get_all_nodes();

        // Initialize `height` for all nodes
        for (const auto& node : nodes)
        {
            height[node] = invalid_height; // Initialize as unvisited (∞)
        }

        // Initialize `lowpt`, `lowpt2`, and `nesting_depth` for all edges
        for (const auto& node : nodes)
        {
            for (const auto& neighbor : graph.get_neighbors(node))
            {
                Edge edge = make_edge(node, neighbor);
                reachability_value[edge] = lowpt_not_assigned;
                reachability_value2[edge] = lowpt_not_assigned;
                parent_edge_map[edge] = no_parent;
                nesting_depth[edge] = 0; // Default to 0
            }
        }
    }


    void dfs(NodeType current_node)
    {
        // Retrieve the parent edge for the current vertex
        auto parent_edge = parent_edge_map[current_node];

        for (const auto& neighbor : graph.get_neighbors(current_node))
        {
            // We orient the edges in the undirected graph according the DFS-tree
            Edge dfs_edge = make_edge(current_node, neighbor); // Standardized edge representation

            if (visited_edges.find(dfs_edge) == visited_edges.end())
            {
                // Mark the edge as oriented
                visited_edges.insert(dfs_edge);

                // Initialize lowpoints
                reachability_value[dfs_edge] = height[current_node];
                reachability_value2[dfs_edge] = height[current_node];

                if (height[neighbor] == invalid_height)
                {
                    // Tree edge
                    parent_edge_map[neighbor] = dfs_edge;
                    height[neighbor] = height[current_node] + 1;
                    dfs(neighbor);
                }
                else
                {
                    // Back edge
                    reachability_value[dfs_edge] = height[neighbor];
                }

                // Determine nesting depth
                nesting_depth[dfs_edge] = 2 * reachability_value[dfs_edge];
                if (reachability_value2[dfs_edge] < height[current_node])
                {
                    nesting_depth[dfs_edge] += 1; // Chordal adjustment
                }

                // Update lowpoints of parent edge
                if (parent_edge != Edge{})
                {
                    // Parent edge is valid
                    if (reachability_value[dfs_edge] < reachability_value[parent_edge])
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value[parent_edge], reachability_value2[dfs_edge]);
                        reachability_value[parent_edge] = reachability_value[dfs_edge];
                    }
                    else if (reachability_value[dfs_edge] > reachability_value[parent_edge])
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value2[parent_edge], reachability_value[dfs_edge]);
                    }
                    else
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value2[parent_edge], reachability_value2[dfs_edge]);
                    }
                }
            }
        }
    }




private:
    const UndirectedGraph<NodeType>& graph;

    // Variables corresponding to the table
    std::unordered_map<NodeType, int> height; // Height of each node
    std::unordered_map<Edge, int, EdgeHash> reachability_value; // Lowpoint of each edge
    std::unordered_map<Edge, int, EdgeHash> reachability_value2; // Second-lowest point
    std::unordered_map<Edge, int, EdgeHash> nesting_depth; // Nesting depth
    std::unordered_map<NodeType, Edge> parent_edge_map; // Parent edge of each node
    std::unordered_set<Edge, EdgeHash> visited_edges;
};


#endif //LEFT_RIGHT_PLANARITY_TEST_H
