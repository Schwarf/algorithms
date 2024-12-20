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

using EdgeHashType = size_t;

template <typename NodeType>
EdgeHashType compute_edge_hash(const std::pair<NodeType, NodeType>& edge)
{
    return std::hash<NodeType>()(edge.first) ^ (std::hash<NodeType>()(edge.second) << 1);
}

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
    constexpr auto reachability_not_assigned = std::numeric_limits<int>::max();
    constexpr auto no_parent = std::numeric_limits<EdgeHashType>::max();
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
                reachability_value[edge] = reachability_not_assigned;
                reachability_value2[edge] = reachability_not_assigned;
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
            // We orient the edges in the undirected graph according the DFS-tree current_node --> neighbor
            const auto dfs_edge_hash = compute_edge_hash(make_edge(current_node, neighbor));
            if (visited_edges.find(dfs_edge_hash) == visited_edges.end())
            {
                // Mark the edge as oriented
                visited_edges.insert(dfs_edge_hash);

                // Initialize lowpoints
                reachability_value[dfs_edge_hash] = height[current_node];
                reachability_value2[dfs_edge_hash] = height[current_node];

                if (height[neighbor] == invalid_height)
                {
                    // Tree edge
                    parent_edge_map[neighbor] = dfs_edge_hash;
                    height[neighbor] = height[current_node] + 1;
                    dfs(neighbor);
                }
                else
                {
                    // Back edge
                    reachability_value[dfs_edge_hash] = height[neighbor];
                }

                // Determine nesting depth
                nesting_depth[dfs_edge_hash] = 2 * reachability_value[dfs_edge_hash];
                if (reachability_value2[dfs_edge_hash] < height[current_node])
                {
                    nesting_depth[dfs_edge_hash] += 1; // Chordal adjustment
                }

                // Update lowpoints of parent edge
                if (parent_edge != no_parent)
                {
                    // Parent edge is valid
                    if (reachability_value[dfs_edge_hash] < reachability_value[parent_edge])
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value[parent_edge],
                                                                    reachability_value2[dfs_edge_hash]);
                        reachability_value[parent_edge] = reachability_value[dfs_edge_hash];
                    }
                    else if (reachability_value[dfs_edge_hash] > reachability_value[parent_edge])
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value2[parent_edge],
                                                                    reachability_value[dfs_edge_hash]);
                    }
                    else
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value2[parent_edge],
                                                                    reachability_value2[dfs_edge_hash]);
                    }
                }
            }
        }
    }

private:
    const UndirectedGraph<NodeType>& graph;

    // Variables corresponding to the table
    std::unordered_map<NodeType, int> height; // Height of each node
    std::unordered_map<EdgeHashType, int> reachability_value; // Lowpoint of each edge
    std::unordered_map<EdgeHashType, int> reachability_value2; // Second-lowest point
    std::unordered_map<EdgeHashType, int> nesting_depth; // Nesting depth
    std::unordered_map<NodeType, EdgeHashType> parent_edge_map; // Parent edge of each node
    std::unordered_set<EdgeHashType> visited_edges;
};


#endif //LEFT_RIGHT_PLANARITY_TEST_H
