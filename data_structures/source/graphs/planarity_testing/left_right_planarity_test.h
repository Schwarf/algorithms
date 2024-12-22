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
#include <stack>
#include <vector>
#include <utility> /

template <typename NodeType>
using Edge = std::pair<NodeType, NodeType>;

template <typename NodeType>
struct ConflictPair {
    std::vector<Edge<NodeType>> L; // Left interval of edges
    std::vector<Edge<NodeType>> R; // Right interval of edges

    ConflictPair() = default;

    // Constructor with initial intervals
    ConflictPair(const std::vector<Edge<NodeType>>& left, const std::vector<Edge<NodeType>>& right)
        : L(left), R(right) {}
};


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

    void sort_adjacency_list_by_nesting_depth() {
        for (auto& [node, neighbors] : graph) {
            std::sort(neighbors.begin(), neighbors.end(), [&](NodeType a, NodeType b) {
                return nesting_depth[make_edge(node, a)] < nesting_depth[make_edge(node, b)];
            });
        }
    }

    void dfs_testing(NodeType current_node)
    {
        auto parent_edge = parent_edge_map[current_node];
        for (const auto& neighbor : graph.get_neighbors(current_node))
        {
            Edge current_edge = make_edge(current_node, neighbor); // Create the edge

            // Track the stack's state for the current edge
            stack_bottom[neighbor] = stack.empty() ? -1 : stack.top(); // Use -1 to indicate an empty stack
            if (current_edge == parent_edge[neighbor])
            {
                dfs_testing(neighbor);
            }
            else
            {
                reachability_value[current_edge] = current_edge;
                ConflictPair<NodeType> conflict_pair;
                conflict_pair.L = {};
                conflict_pair.R = {current_edge};
                stack.push(conflict_pair);
            }
        }
    }
    void testing_planarity()
    {
        sort_adjacency_list_by_nesting_depth();
        for(const auto root_node : roots)
        {
            dfs_testing(root_node);
        }
    }

    void orientation()
    {
        for (const auto& current_node : graph.get_all_nodes())
        {
            if (height[current_node] == invalid_height)
            {
                // Node is unvisited, mark it as root.
                height[current_node] = 0;
                roots.push_back(current_node);
                dfs_orientation(current_node);
            }
        }
    }

    void dfs_orientation(NodeType current_node)
    {
        // Retrieve the parent edge for the current vertex
        auto parent_edge = parent_edge_map[current_node];

        for (const auto& neighbor : graph.get_neighbors(current_node))
        {
            // We orient the edges in the undirected graph according the DFS-tree current_node --> neighbor
            Edge current_edge = make_edge(current_node, neighbor);

            if (visited_edges.find(current_edge) == visited_edges.end())
            {
                // Mark the edge as oriented and visited
                visited_edges.insert(current_edge);
                // Set the
                reachability_value[current_edge] = height[current_node];
                reachability_value2[current_edge] = height[current_node];

                if (height[neighbor] == invalid_height)
                {
                    // Found a DFS-tree edge
                    parent_edge_map[neighbor] = current_edge;
                    height[neighbor] = height[current_node] + 1;
                    dfs_orientation(neighbor);
                }
                else
                {
                    // Found a back edge
                    reachability_value[current_edge] = height[neighbor];
                }

                // Determine nesting depth
                nesting_depth[current_edge] = 2 * reachability_value[current_edge];
                if (reachability_value2[current_edge] < height[current_node])
                {
                    nesting_depth[current_edge] += 1; // Chordal adjustment
                }

                // Update reachability_values of parent edge
                if (parent_edge != Edge{})
                {
                    // Parent edge is valid
                    if (reachability_value[current_edge] < reachability_value[parent_edge])
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value[parent_edge],
                                                                    reachability_value2[current_edge]);
                        reachability_value[parent_edge] = reachability_value[current_edge];
                    }
                    else if (reachability_value[current_edge] > reachability_value[parent_edge])
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value2[parent_edge],
                                                                    reachability_value[current_edge]);
                    }
                    else
                    {
                        reachability_value2[parent_edge] = std::min(reachability_value2[parent_edge],
                                                                    reachability_value2[current_edge]);
                    }
                }
            }
        }
    }

private:
    const UndirectedGraph<NodeType>& graph;
    std::vector<NodeType> roots; // Stores the roots of all connected components
    // Variables corresponding to the table
    std::unordered_map<NodeType, int> height; // Height of each node
    std::unordered_map<Edge, int, EdgeHash> reachability_value; // Lowpoint of each edge
    std::unordered_map<Edge, int, EdgeHash> reachability_value2; // Second-lowest point
    std::unordered_map<Edge, int, EdgeHash> nesting_depth; // Nesting depth
    std::unordered_map<Edge, int, EdgeHash> stack_bottom;
    std::unordered_map<Edge, Edge, EdgeHash> reachability_edge;

    std::unordered_map<NodeType, Edge> parent_edge_map; // Parent edge of each node
    std::unordered_set<Edge, EdgeHash> visited_edges;
    std::stack<ConflictPair<NodeType>> stack;
};


#endif //LEFT_RIGHT_PLANARITY_TEST_H
