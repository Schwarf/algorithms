// This is an implementation of the tarjan algorithm for undirected graphs. We assume the vertices are
// given as std::vector<std::vector<'integral_type'>> where each inner vector consists of two nodes [source, destination]
//
// Created by andreas on 05.11.24.
//

#ifndef TARJAN_ALGORITHM_UNDIRECTED_GRAPH_H
#define TARJAN_ALGORITHM_UNDIRECTED_GRAPH_H

#include <stack>
#include "graph.h"

template <typename NodeType>
requires std::is_signed_v<NodeType>
void dfs_bcc_tarjan(NodeType current_node, NodeType parent, const UndirectedGraph<NodeType>& graph,
                    std::unordered_map<NodeType, int>& discovery_order,
                    std::unordered_map<NodeType, int>& ancestor_reachability_value,
                    std::stack<std::pair<NodeType, NodeType>>& edge_stack,
                    std::set<std::set<NodeType>>& biconnected_components,
                    int& discovery_index)
{
    // Initialize discovery order and ancestor reachability value
    discovery_order[current_node] = discovery_index++;
    ancestor_reachability_value[current_node] = discovery_order[current_node];
    int children = 0; // Count of children in DFS

    for (auto neighbor : graph.get_neighbors(current_node))
    {
        if (!discovery_order.contains(neighbor)) // If neighbor is not visited
        {
            children++;
            edge_stack.push({current_node, neighbor}); // Push the edge onto the stack
            dfs_bcc_tarjan(neighbor, current_node, graph, discovery_order, ancestor_reachability_value,
                           edge_stack, biconnected_components, discovery_index);

            // Check if subtree rooted at neighbor has a connection back to an ancestor of current_node
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node],
                                                                 ancestor_reachability_value[neighbor]);

            // If current_node is an articulation point, pop edges to form a biconnected component
            if ((parent == -1 && children > 1) || (parent != -1 && ancestor_reachability_value[neighbor] >= discovery_order[current_node]))
            {
                std::set<NodeType> biconnected_component;
                std::pair<NodeType, NodeType> edge;
                do
                {
                    edge = edge_stack.top();
                    edge_stack.pop();
                    biconnected_component.insert(edge.first);
                    biconnected_component.insert(edge.second);
                } while (edge != std::make_pair(current_node, neighbor));

                // Add this if we require that two vertices (one edge) do not form a bi connected component.
                // if (biconnected_component.size() > 2) {
                //     biconnected_components.insert(biconnected_component);
                // }
                biconnected_components.insert(biconnected_component);
            }
        }
        else if (neighbor != parent && discovery_order[neighbor] < discovery_order[current_node])
        {
            // Update ancestor reachability and push edge to stack for back edge
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node],
                                                                 discovery_order[neighbor]);
            edge_stack.push({current_node, neighbor});
        }
    }
}

template <typename NodeType>
requires std::is_signed_v<NodeType>
std::set<std::set<NodeType>> biconnected_components_tarjan(const UndirectedGraph<NodeType>& graph)
{
    std::unordered_map<NodeType, int> discovery_order;
    std::unordered_map<NodeType, int> ancestor_reachability_value;
    std::stack<std::pair<NodeType, NodeType>> edge_stack;
    std::set<std::set<NodeType>> biconnected_components;
    int discovery_index = 0;

    // Run DFS for each unvisited node to find all biconnected components
    for (auto node : graph.get_all_nodes())
    {
        if (!discovery_order.contains(node))
        {
            dfs_bcc_tarjan(node, -1, graph, discovery_order, ancestor_reachability_value, edge_stack,
                           biconnected_components, discovery_index);

            // Remaining edges in stack form a biconnected component
            if (!edge_stack.empty())
            {
                std::set<NodeType> biconnected_component;
                while (!edge_stack.empty())
                {
                    auto edge = edge_stack.top();
                    edge_stack.pop();
                    biconnected_component.insert(edge.first);
                    biconnected_component.insert(edge.second);
                }
                // Add this if we require that two vertices (one edge) do not form a bi connected component.
                // if (biconnected_component.size() > 2) {
                //     biconnected_components.insert(biconnected_component);
                // }

                biconnected_components.insert(biconnected_component);
            }
        }
    }

    return biconnected_components;
}

#endif // TARJAN_ALGORITHM_UNDIRECTED_GRAPH_H


