//
// Created by andreas on 14.12.24.
//

#ifndef LEFT_RIGHT_PLANARITY_TEST_H
#define LEFT_RIGHT_PLANARITY_TEST_H
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <stack>
#include <vector>
#include <utility>
#include "graphs/graph.h"


template <typename NodeType>
struct ConflictPair {
    std::vector<Edge<NodeType>> L; // Left interval of edges
    std::vector<Edge<NodeType>> R; // Right interval of edges

    ConflictPair() = default;

    // Constructor with initial intervals
    ConflictPair(const std::vector<Edge<NodeType>>& left, const std::vector<Edge<NodeType>>& right)
        : L(left), R(right) {}
};




template <typename NodeType>
    requires std::is_signed_v<NodeType>
class PlanarityTest
{
    using Edge = std::pair<NodeType, NodeType>; // Define an edge type for convenience
    static constexpr int lowpt_not_assigned = std::numeric_limits<int>::min();
    static constexpr NodeType no_parent = std::numeric_limits<NodeType>::max();
    static constexpr int none = std::numeric_limits<int>::max();
    static constexpr std::pair<NodeType, NodeType> invalid_edge = std::make_pair(none, none);
    bool is_planar{};
public:
    explicit PlanarityTest(const UndirectedGraph<NodeType>& graph)
        : graph(graph), dfs_graph()
    {
        auto nodes = graph.get_all_nodes();

        // Initialize `height` for all nodes
        for (const auto& node : nodes)
        {
            height[node] = none;
            parent_edges[node] = invalid_edge;
        }

        // Initialize `lowpt`, `lowpt2`, and `nesting_depth` for all edges
        dfs_graph = DirectedGraph<NodeType>{{graph.get_edges()}, {}};

    }
    void run()
    {
        if(graph.get_node_count()  > 2 && graph.get_edges().size() > 3* graph.get_node_count() - 6)
        {
            is_planar = false;
            return;
        }


    }

private:
    void sort_adjacency_list_by_nesting_depth() {
        for (auto& [node, neighbors] : graph) {
            std::sort(neighbors.begin(), neighbors.end(), [&](NodeType a, NodeType b) {
                return nesting_depth[make_edge(node, a)] < nesting_depth[make_edge(node, b)];
            });
        }
    }

    void dfs_testing(NodeType current_node)
    {
        auto parent_edge = parent_edge[current_node];
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
                low_pt[current_edge] = current_edge;
                ConflictPair<NodeType> conflict_pair;
                conflict_pair.L = {};
                conflict_pair.R = {current_edge};
                stack.push(conflict_pair);
            }
        }
    }
    void check_planarity()
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
            if (height[current_node] == none)
            {
                // Node is unvisited, mark it as root.
                height[current_node] = 0;
                roots.push_back(current_node);
                dfs_orientation(current_node);
            }
        }
    }

    void dfs_orientation(NodeType start_node)
    {
        // Retrieve the parent edge for the current vertex
        std::stack<NodeType> dfs_stack;
        dfs_stack.push(start_node);
        std::unordered_map<NodeType, size_t> next_edge_index;
        std::unordered_map<Edge, bool, EdgeHash> skip_edge_initialization;
        while (!dfs_stack.empty())
        {
            auto current_node = dfs_stack.top();
            dfs_stack.pop();
            auto & neighbors = graph.get_neighbors(current_node);
            auto neighbor_iterator = neighbors.begin();
            auto & index = next_edge_index[current_node];
            for (; neighbor_iterator != neighbors.end(); ++neighbor_iterator, ++index)
            {
                auto neighbor = *neighbor_iterator;
                auto current_edge = make_edge(current_node, neighbor);
                if(!skip_edge_initialization[current_edge])
                {
                    auto reverse_edge = make_edge(neighbor, current_edge);
                    if(dfs_graph.get_all_edges().contains(reverse_edge) || dfs_graph.get_all_edges().contains(current_edge))
                    {
                        ++index;
                        continue;
                    }

                }


            }
        }
    }

private:
    const UndirectedGraph<NodeType>& graph;
    DirectedGraph<NodeType>& dfs_graph;
    std::vector<NodeType> roots; // Stores the roots of all connected components
    // Variables corresponding to the table
    std::unordered_map<NodeType, int> height; // Height of each node
    std::unordered_map<Edge, int, EdgeHash> low_pt{}; // Lowpoint of each edge
    std::unordered_map<Edge, int, EdgeHash> low_pt2{}; // Second-lowest point
    std::unordered_map<Edge, int, EdgeHash> nesting_depth{}; // Nesting depth
    std::unordered_map<Edge, int, EdgeHash> stack_bottom{};
    std::unordered_map<NodeType, std::vector<NodeType>> adjacency_list{};
    std::unordered_map<NodeType, std::vector<NodeType>> ordered_adjacency_list{};
    std::unordered_map<Edge, int, EdgeHash> ref{};
    std::unordered_map<Edge, int, EdgeHash> side{};
    std::unordered_map<Edge, Edge, EdgeHash> lowpt_edge{};
    std::unordered_map<NodeType, Edge, EdgeHash> left_ref{};
    std::unordered_map<NodeType, Edge, EdgeHash> right_ref{};

    std::unordered_map<NodeType, Edge> parent_edges; // Parent edge of each node
    std::unordered_set<Edge, EdgeHash> visited_edges;
    std::stack<ConflictPair<NodeType>> stack{};
};


#endif //LEFT_RIGHT_PLANARITY_TEST_H
