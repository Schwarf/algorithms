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
            return low == NoneEdge<NodeType> && high == NoneEdge<NodeType>;
        }
    };

    friend bool operator==(const Interval& lhs, const Interval& rhs)
    {
        return lhs.low == rhs.low && lhs.high == rhs.high;
    }


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

    const ConflictPair NoneConflictPair{Interval{}, Interval{}};

    friend bool operator==(const ConflictPair& lhs, const ConflictPair& rhs)
    {
        return lhs.left == rhs.left && lhs.right == rhs.right;
    }

    static constexpr int NoneHeight = std::numeric_limits<int>::max();
    bool is_planar{};

public:
    explicit PlanarityTest(UndirectedGraph<NodeType>& graph)
        : graph_(graph)
    {
        // Initialize `height` and parent edges
        for (const auto& node : graph_.get_all_nodes())
        {
            height[node] = NoneHeight;
            parent_edges[node] = NoneEdge<NodeType>;
        }
        // initialize all nodes for dfs-walk (orientation)
        dfs_graph = DirectedGraph<NodeType>{graph_.get_all_nodes(), {}};
    }

    void run()
    {
        if (graph_.get_node_count() > 2 && graph_.get_edge_count() > 3 * graph_.get_node_count() - 6)
        {
            is_planar = false;
            return;
        }
        orientation();
        check_planarity();
    }

    bool is_graph_planar() const
    {
        return is_planar;
    }

private:
    int get_lowest_lowpt(const ConflictPair& conflict_pair)
    {
        if (conflict_pair.left.is_empty())
            return low_pt[conflict_pair.right.low];
        if (conflict_pair.right.is_empty())
            return low_pt[conflict_pair.left.low];
        return std::min(low_pt[conflict_pair.right.low], low_pt[conflict_pair.left.low]);
    }

    void sort_adjacency_list_by_nesting_depth()
    {
        ordered_adjacency_list = dfs_graph.get_adjacency_list();

        for (auto& [node, neighbors] : ordered_adjacency_list)
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
        for (const auto neighbor : ordered_adjacency_list[current_node])
        {
            auto current_edge = make_edge(current_node, neighbor);
            stack_bottom[current_edge] = stack.empty() ? NoneConflictPair : stack.top();

            if (current_edge == parent_edges[neighbor]) // tree edge ? add explanation
            {
                if (!dfs_testing(neighbor))
                    return false;
            }
            else // back edge ? add explanation
            {
                lowpt_edge[current_edge] = current_edge;
                stack.push(ConflictPair(Interval{}, Interval(current_edge, current_edge)));
            }

            if (low_pt[current_edge] < height[current_node])
            {
                if (neighbor == ordered_adjacency_list[current_node][0])
                {
                    lowpt_edge[parent_edge] = lowpt_edge[current_edge];
                }
                else
                {
                    if (!apply_constraints(current_edge, parent_edge))
                        return false;
                }
            }
        }
        if (parent_edge != NoneEdge<NodeType>)
            remove_back_edges(parent_edge);

        return true;
    }

    void remove_back_edges(const Edge<NodeType>& edge)
    {
        auto parent_node = edge.first;
        while (!stack.empty() && get_lowest_lowpt(stack.top()) == height[parent_node])
        {
            // auto conflict_pair = stack.top();
            stack.pop();
            // if (conflict_pair.left.low != NoneEdge<NodeType>)
            //     side[conflict_pair.left.low] = -1;
        }

        if (!stack.empty())
        {
            auto conflict_pair = stack.top();
            stack.pop();
            while (conflict_pair.left.high != NoneEdge<NodeType> && conflict_pair.left.high.second == parent_node)
            {
                conflict_pair.left.high = ref[conflict_pair.left.high];
            }
            if (conflict_pair.left.high == NoneEdge<NodeType> && conflict_pair.left.low != NoneEdge<NodeType>)
            {
                ref[conflict_pair.left.low] = conflict_pair.right.low;
                // side[conflict_pair.left.low] = -1;
                conflict_pair.left.low = NoneEdge<NodeType>;
            }
            while (conflict_pair.right.high != NoneEdge<NodeType> && conflict_pair.right.high.second == parent_node)
            {
                conflict_pair.right.high = ref[conflict_pair.right.high];
            }

            if (conflict_pair.right.high == NoneEdge<NodeType> && conflict_pair.right.low != NoneEdge<NodeType>)
            {
                ref[conflict_pair.right.low] = conflict_pair.left.low;
                // side[conflict_pair.right.low] = -1;
                conflict_pair.right.low = NoneEdge<NodeType>;
            }
            stack.push(conflict_pair);
        }


        if (!stack.empty() && low_pt[edge] < height[parent_node])
        {
            auto highest_return_edge_left = stack.top().left.high;
            auto highest_return_edge_right = stack.top().right.high;
            if (highest_return_edge_left != NoneEdge<NodeType> && (highest_return_edge_right != NoneEdge<NodeType> ||
                low_pt[highest_return_edge_left] > low_pt[highest_return_edge_right]))
            {
                ref[edge] = highest_return_edge_left;
            }
            else
            {
                ref[edge] = highest_return_edge_right;
            }
        }
    }


    bool apply_constraints(const Edge<NodeType>& edge, const Edge<NodeType>& parent_edge)
    {
        auto help_conflict_pair = ConflictPair{};
        while (!stack.empty() && stack.top() != stack_bottom[edge])
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
            if (low_pt[current_conflict_pair.right.low] > low_pt[parent_edge])
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
                ref[current_conflict_pair.right.low] = lowpt_edge[parent_edge];
            }
        }

        while (!stack.empty() && (conflicting(stack.top().left, edge) || conflicting(stack.top().right, edge)))
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
            if (current_conflict_pair.right.low != NoneEdge<NodeType>)
            {
                help_conflict_pair.right = current_conflict_pair.right;
            }
            if (help_conflict_pair.left.is_empty())
            {
                help_conflict_pair.left = current_conflict_pair.left;
            }
            else
            {
                ref[help_conflict_pair.left.low] = current_conflict_pair.left.high;
            }
            help_conflict_pair.left.low = current_conflict_pair.left.low;
        }

        if (!help_conflict_pair.left.is_empty() || !help_conflict_pair.right.is_empty())
            stack.push(help_conflict_pair);
        return true;
    }

    void check_planarity()
    {
        sort_adjacency_list_by_nesting_depth();
        for (const auto root_node : roots)
        {
            is_planar = dfs_testing(root_node);
        }
    }

    void orientation()
    {
        for (const auto& current_node : graph_.get_all_nodes())
        {
            if (height[current_node] == NoneHeight)
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
        auto parent_edge = parent_edges[current_node];

        for (const auto& neighbor : graph_.get_neighbors(current_node))
        {
            // We orient the edges in the undirected graph according the DFS-tree current_node --> neighbor
            auto current_edge = make_edge(current_node, neighbor);
            auto current_reversed_edge = make_edge(neighbor, current_node);

            if (visited_edges.contains(current_edge) || visited_edges.contains(current_reversed_edge))
                continue;
            // Mark the edge as oriented and visited
            visited_edges.insert(current_edge);
            dfs_graph.add_edge(current_node, neighbor);
            // Set the
            low_pt[current_edge] = height[current_node];
            low_pt2[current_edge] = height[current_node];

            if (height[neighbor] == NoneHeight)
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
            if (parent_edge != NoneEdge<NodeType>)
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
    const UndirectedGraph<NodeType>& graph_;
    DirectedGraph<NodeType> dfs_graph;
    std::vector<NodeType> roots; // Stores the roots of all connected components
    // Variables corresponding to the table
    std::unordered_map<NodeType, int> height; // Height of each node
    std::unordered_map<Edge<NodeType>, int, EdgeHash> low_pt{}; // Lowpoint of each edge
    std::unordered_map<Edge<NodeType>, int, EdgeHash> low_pt2{}; // Second-lowest point
    std::unordered_map<Edge<NodeType>, int, EdgeHash> nesting_depth{}; // Nesting depth
    std::unordered_map<Edge<NodeType>, ConflictPair, EdgeHash> stack_bottom{};
    std::unordered_map<NodeType, std::vector<NodeType>> ordered_adjacency_list;
    std::unordered_map<Edge<NodeType>, Edge<NodeType>, EdgeHash> ref{};
    // std::unordered_map<Edge<NodeType>, int, EdgeHash> side{};
    std::unordered_map<Edge<NodeType>, Edge<NodeType>, EdgeHash> lowpt_edge{};
    // std::unordered_map<NodeType, Edge<NodeType>, EdgeHash> left_ref{};
    // std::unordered_map<NodeType, Edge<NodeType>, EdgeHash> right_ref{};

    std::unordered_map<NodeType, Edge<NodeType>> parent_edges; // Parent edge of each node
    std::unordered_set<Edge<NodeType>, EdgeHash> visited_edges;
    std::stack<ConflictPair> stack{};
};


#endif //LEFT_RIGHT_PLANARITY_TEST_H
