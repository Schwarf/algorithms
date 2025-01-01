//
// Created by andreas on 14.12.24.
//

#ifndef LEFT_RIGHT_PLANARITY_TEST_H
#define LEFT_RIGHT_PLANARITY_TEST_H
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <optional>
#include <stack>
#include <vector>
#include <utility>
#include "graphs/graph.h"


template <typename NodeType>
    requires std::is_signed_v<NodeType>
class PlanarityTest
{
    struct Interval
    {
        Edge<NodeType> low{NoneEdge<NodeType>}; // Represents the lower bound of the interval
        Edge<NodeType> high{NoneEdge<NodeType>}; // Represents the upper bound of the interval

        // Default constructor
        Interval() = default;

        // Constructor with specific low and high values
        Interval(const Edge<NodeType>& low, const Edge<NodeType>& high)
            : low(low), high(high)
        {
        }

        bool is_empty() const
        {
            return low == NoneEdge<NodeType>() && high == NoneEdge<NodeType>();
        }
    };


    struct ConflictPair
    {
        Interval left{}; // Left interval of edges
        Interval right{}; // Right interval of edges

        ConflictPair() = default;

        // Constructor with initial intervals
        ConflictPair(const Interval& left, const Interval& right)
            : left(left), right(right)
        {
        }

        void swap()
        {
            std::swap(left, right);
        }
    };


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
        if (graph.get_node_count() > 2 && graph.get_edges().size() > 3 * graph.get_node_count() - 6)
        {
            is_planar = false;
            return;
        }
    }

private:
    void sort_adjacency_list_by_nesting_depth()
    {
        for (auto& [node, neighbors] : dfs_graph)
        {
            std::sort(neighbors.begin(), neighbors.end(), [&](NodeType a, NodeType b)
            {
                return nesting_depth[make_edge(node, a)] < nesting_depth[make_edge(node, b)];
            });
        }
    }


    bool dfs_testing(NodeType current_node)
    {
        auto parent_edge = parent_edges[current_node];
        for (const auto neighbor : dfs_graph.get_neighbors(current_node))
        {
            auto current_edge = make_edge(current_node, neighbor); // Create the edge

            // Track the stack's state for the current edge
            stack_bottom[neighbor] = stack.empty() ? -1 : stack.top(); // Use -1 to indicate an empty stack
            if (current_edge == parent_edges[neighbor]) // tree edge ? add explanation
            {
                if (!dfs_testing(neighbor))
                    return false;
            }
            else // back edge ? add explanation
            {
                low_pt[current_edge] = current_edge;
                stack.push(ConflictPair(Interval{},Interval(current_edge, current_edge)));
            }

            if (low_pt[current_edge] < height[current_node])
            {
                if (neighbor == current_edge)
                    break;

            }
        }

        return true;
    }

    bool apply_constraints(const Edge<NodeType>& edge, const Edge<NodeType>& parent_edge)
    {
        auto help_conflict_pair = ConflictPair{};
        while (stack.top() != stack_bottom[edge])
        {
            auto current_conflict_pair = stack.top();
            stack.pop();
            if (!current_conflict_pair.left.is_empty())
            {
                current_conflict_pair.swap();
            }
            if (!current_conflict_pair.left.is_empty())
            {
                return false;
            }
            if (low_pt[current_conflict_pair.left] > low_pt[parent_edge])
            {
                if (help_conflict_pair.right.is_empty())
                {
                    help_conflict_pair.right = current_conflict_pair.right;
                }
                else
                {
                    ref[help_conflict_pair.right.low] = current_conflict_pair.right.high;
                }

                help_conflict_pair.right.low = current_conflict_pair.right.low;
            }
            else
            {
                ref[current_conflict_pair.right.low] = low_pt[parent_edge];
            }
        }

        while (conflicting(stack.top().left, edge) || conflicting(stack.top().right, edge))
        {
            auto current_conflict_pair = stack.top();
            stack.pop();
            if (conflicting(current_conflict_pair.right, edge))
            {
                current_conflict_pair.swap();
            }
            if (conflicting(current_conflict_pair.right, edge))
            {
                return false;
            }
            ref[help_conflict_pair.right.low] = current_conflict_pair.right.high;
            if(current_conflict_pair.right.low != NoneEdge<NodeType>)
            {
                help_conflict_pair.right = current_conflict_pair.right;
            }
            if(help_conflict_pair.left.is_empty())
            {
                help_conflict_pair.left = current_conflict_pair.left;
            }
            else
            {
                ref[help_conflict_pair.left.low] = current_conflict_pair.left.high;
            }
            help_conflict_pair.left.low = current_conflict_pair.left.low;
        }

        if (!help_conflict_pair.left.is_empty() && help_conflict_pair.right.is_empty())
            stack.push(help_conflict_pair);
        return true;
    }

    void check_planarity()
    {
        sort_adjacency_list_by_nesting_depth();
        for (const auto root_node : roots)
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


    bool conflicting(const Interval& interval, const Edge<NodeType>& edge)
    {
        return !interval.is_empty() && low_pt[interval.high] > low_pt[edge];
    }

    void dfs_orientation(NodeType current_node)
    {
        // Retrieve the parent edge for the curradjacency_listent vertex
        auto parent_edge = parent_edge[current_node];

        for (const auto& neighbor : graph.get_neighbors(current_node))
        {
            // We orient the edges in the undirected graph according the DFS-tree current_node --> neighbor
            auto current_edge = make_edge(current_node, neighbor);
            auto current_reversed_edge = make_edge(current_node, neighbor);

            if (visited_edges.contains(current_edge) || visited_edges.contains(current_reversed_edge))
                continue;
            // Mark the edge as oriented and visited
            visited_edges.insert(current_edge);
            dfs_graph.add_edge(current_node, neighbor);
            // Set the
            low_pt[current_edge] = height[current_node];
            low_pt2[current_edge] = height[current_node];

            if (height[neighbor] == none)
            {
                // Found a DFS-tree edge
                parent_edges[neighbor] = current_edge;
                height[neighbor] = height[current_node] + 1;
                dfs_orientation(neighbor);
            }
            else
            {
                // Found a back edge
                low_pt[current_edge] = height[neighbor];
            }

            // Determine nesting depth
            nesting_depth[current_edge] = 2 * low_pt[current_edge];
            if (low_pt2[current_edge] < height[current_node])
            {
                nesting_depth[current_edge] += 1; // Chordal adjustment
            }

            // Update reachability_values (aka low_points) of parent edge
            if (parent_edge != no_parent)
            {
                if (low_pt[current_edge] < low_pt[parent_edge])
                {
                    low_pt2[parent_edge] = std::min(low_pt[parent_edge], low_pt2[current_edge]);
                    low_pt[parent_edge] = low_pt[current_edge];
                }
                else if (low_pt[current_edge] > low_pt[parent_edge])
                {
                    low_pt2[parent_edge] = std::min(low_pt2[parent_edge], low_pt[current_edge]);
                }
                else
                {
                    low_pt2[parent_edge] = std::min(low_pt2[parent_edge], low_pt2[current_edge]);
                }
            }
        }
    }

    // We follow the naming here: https://citeseerx.ist.psu.edu/document?repid=rep1&type=pdf&doi=7963e9feffe1c9362eb1a69010a5139d1da3661e
    const UndirectedGraph<NodeType>& graph;
    DirectedGraph<NodeType>& dfs_graph;
    std::vector<NodeType> roots; // Stores the roots of all connected components
    // Variables corresponding to the table
    std::unordered_map<NodeType, int> height; // Height of each node
    std::unordered_map<Edge<NodeType>, int, EdgeHash> low_pt{}; // Lowpoint of each edge
    std::unordered_map<Edge<NodeType>, int, EdgeHash> low_pt2{}; // Second-lowest point
    std::unordered_map<Edge<NodeType>, int, EdgeHash> nesting_depth{}; // Nesting depth
    std::unordered_map<Edge<NodeType>, int, EdgeHash> stack_bottom{};
    std::unordered_map<NodeType, std::unordered_set<NodeType>> ordered_adjacency_list;
    std::unordered_map<Edge<NodeType>, int, EdgeHash> ref{};
    std::unordered_map<Edge<NodeType>, int, EdgeHash> side{};
    std::unordered_map<Edge<NodeType>, Edge<NodeType>, EdgeHash> lowpt_edge{};
    std::unordered_map<NodeType, Edge<NodeType>, EdgeHash> left_ref{};
    std::unordered_map<NodeType, Edge<NodeType>, EdgeHash> right_ref{};

    std::unordered_map<NodeType, Edge<NodeType>> parent_edges; // Parent edge of each node
    std::unordered_set<Edge<NodeType>, EdgeHash> visited_edges;
    std::stack<ConflictPair> stack{};
};


#endif //LEFT_RIGHT_PLANARITY_TEST_H
