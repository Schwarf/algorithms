//
// Created by andreas on 03.11.24.
//

#ifndef TARJAN_ALGORITHM_H
#define TARJAN_ALGORITHM_H

// This is an implementation of the tarjan algorithm for undirected graphs. We assume the vertices are
// given as std::vector<std::vector<'integral_type'>> where each inner vector consists of two nodes [source, destination]
#include "used_concepts.h"
#include <vector>
#include <iostream>  // For debugging output
#include <stack>

#include "graph.h"

template <typename T>
void dfs_tarjan_undirected(std::vector<std::vector<T>>& graph, T node, std::vector<bool>& visited,
                           std::vector<T>& discovery_time,
                           std::vector<T>& ancestor_reachability_value, std::vector<T>& parent, int& time)
{
    visited[node] = true;
    discovery_time[node] = ancestor_reachability_value[node] = ++time;

    std::cout << "Visiting node " << node << " | discovery_time: " << discovery_time[node]
        << " | ancestor_reachability_value: " << ancestor_reachability_value[node] << std::endl;

    for (auto neighbor_node : graph[node])
    {
        if (!visited[neighbor_node])
        {
            // Expand the DFS tree
            parent[neighbor_node] = node;
            dfs_tarjan(graph, neighbor_node, visited, discovery_time, ancestor_reachability_value, parent, time);

            // Update ancestor reachability based on DFS child
            ancestor_reachability_value[node] = std::min(ancestor_reachability_value[node],
                                                         ancestor_reachability_value[neighbor_node]);

            std::cout << "Backtracking to node " << node << " from child " << neighbor_node
                << " | Updated ancestor_reachability_value: " << ancestor_reachability_value[node] << std::endl;
        }
        else if (neighbor_node != parent[node])
        {
            // Update low value for back edges
            ancestor_reachability_value[node] = std::min(ancestor_reachability_value[node],
                                                         discovery_time[neighbor_node]);

            std::cout << "Found back edge from node " << node << " to ancestor " << neighbor_node
                << " | Updated ancestor_reachability_value: " << ancestor_reachability_value[node] << std::endl;
        }
    }
}


template <typename T>
std::pair<std::vector<T>, std::vector<T>> tarjan_algorithm_undirected(std::vector<std::vector<T>>& edges,
                                                                      int number_of_nodes)
{
    std::vector<std::vector<T>> graph(number_of_nodes);
    for (const auto& edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    T invalid = -1;

    std::vector visited(number_of_nodes, false);
    std::vector<T> discovery_time(number_of_nodes, invalid);
    std::vector<T> ancestor_reachability_value(number_of_nodes, invalid);
    std::vector<T> parent(number_of_nodes, invalid);
    int time{};

    for (T node{}; node < number_of_nodes; ++node)
    {
        if (!visited[node])
        {
            std::cout << "\nStarting DFS at node " << node << std::endl;
            dfs_tarjan(graph, node, visited, discovery_time, ancestor_reachability_value, parent, time);
        }
    }
    return std::make_pair(ancestor_reachability_value, discovery_time);
}


template <typename NodeType>
    requires std::is_signed_v<NodeType>
void dfs_ssc_trajan(NodeType current_node, const DirectedGraph<NodeType>& graph, std::unordered_map<NodeType, int>& discovery_order,
         std::unordered_map<NodeType, int>& ancestor_reachability_value, std::stack<NodeType>& stack,
         std::unordered_set<NodeType>& on_stack, std::set<std::set<NodeType>>& SCCs, int& discovery_index) {

    discovery_order[current_node] = ancestor_reachability_value[current_node] = discovery_index++;
    stack.push(current_node);
    on_stack.insert(current_node);

    for (auto neighbor : graph.getAdjacencyList(current_node)) {
        if (!discovery_order.contains(neighbor)) {  // Node w has not been visited
            dfs_ssc_trajan(neighbor, graph, discovery_order, ancestor_reachability_value, stack, on_stack, SCCs, discovery_index);
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node], ancestor_reachability_value[neighbor]);
        } else if (on_stack.contains(neighbor)) {  // Node w is in the current SCC
            ancestor_reachability_value[current_node] = std::min(ancestor_reachability_value[current_node], discovery_order[neighbor]);
        }
    }

    // Root node of an SCC
    if (ancestor_reachability_value[current_node] == discovery_order[current_node]) {
        std::set<NodeType> scc;
        NodeType node;
        do {
            node = stack.top();
            stack.pop();
            on_stack.erase(node);
            scc.insert(node);
        } while (node != current_node);
        SCCs.insert(scc);
    }
}


template <typename NodeType>
    requires std::is_signed_v<NodeType>
std::set<std::set<NodeType>> strongly_connected_components_tarjan(const DirectedGraph<NodeType>& graph)
{
    std::unordered_map<NodeType, int> discovery_order;
    std::set<std::set<NodeType>> strongly_connected_components;
    std::stack<NodeType> stack{};
    std::unordered_set<NodeType> on_stack{};
    std::unordered_map<NodeType, int> ancestor_reachability_value;
    int current_index{};

    // Run DFS for each unvisited node
    for (auto node : graph.getNodes())
    {
        if (!discovery_order.contains(node))
        {

            // Node v has not been visited
            dfs_ssc_trajan(node, graph, discovery_order, ancestor_reachability_value, stack, on_stack,
                strongly_connected_components, current_index);
        }
    }

    return strongly_connected_components;
}


#endif //LR_PLANARITY_TEST_H
