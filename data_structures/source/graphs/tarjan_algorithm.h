//
// Created by andreas on 03.11.24.
//

#ifndef TARJAN_ALGORITHM_H
#define TARJAN_ALGORITHM_H

// This is an implementation of the tarjan algorithm for undirected graphs. We assume the vertices are
// given as std::vector<std::vector<'integral_type'>> where each inner vector consists of two nodes [source, destination]
#include "used_concepts.h"
#include <vector>

template <typename T>
void dfs_tarjan(std::vector<std::vector<T>>& graph, T node, std::vector<bool>& visited, std::vector<T>& discovered,
                std::vector<T>& ancestor_reachability_value, std::vector<T>& parent, int time)
{
    visited[node] = true;
    discovered[node] = ancestor_reachability_value[node] = ++time;
    for (auto neighbor_node : graph[node])
    {
        if (!visited[neighbor_node])
        {
            //expand the dfs tree
            parent[neighbor_node] = node;
            dfs_tarjan(graph, neighbor_node, visited, discovered, ancestor_reachability_value, parent, time);
            ancestor_reachability_value[node] = std::min(ancestor_reachability_value[node],
                                                         ancestor_reachability_value[neighbor_node]);
        }
        else if (neighbor_node != parent[node])
        {
            // we found a back-edge because if neighbor_node is not a parent of node it must be an ancestor of node
            // that has been visited earlier
            ancestor_reachability_value[node] = std::min(ancestor_reachability_value[node], discovered[neighbor_node]);
        }
    }
}


template <typename T>
std::pair<std::vector<T>, std::vector<T>> tarjan_algorithm(std::vector<std::vector<T>>& edges, int number_of_nodes)
{
    std::vector<std::vector<T>> graph(number_of_nodes);
    for (const auto& edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    T invalid = -1;

    std::vector visited(number_of_nodes, false);
    std::vector<T> discovered(number_of_nodes, invalid);
    std::vector<T> ancestor_reachability_value(number_of_nodes, invalid);
    std::vector<T> parent(number_of_nodes, invalid);
    int time{};

    for (T node{}; node < number_of_nodes; ++node)
    {
        if (!visited[node])
            dfs_tarjan(graph, node, visited, discovered, ancestor_reachability_value, parent, time);
    }
    return std::make_pair(ancestor_reachability_value, discovered);
}


#endif //LR_PLANARITY_TEST_H
