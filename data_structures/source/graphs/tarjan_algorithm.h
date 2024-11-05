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
void dfs_tarjan(std::vector<std::vector<T>>& graph, T node, std::vector<bool>& visited,
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
std::pair<std::vector<T>, std::vector<T>> tarjan_algorithm(std::vector<std::vector<T>>& edges,
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




#endif //LR_PLANARITY_TEST_H
