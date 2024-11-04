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
requires VertexRequirement<T>
void dfs_tarjan(std::vector<std::vector<T>> & graph, T node, std::vector<bool> & visited, std::vector<T> & discovered,
    std::vector<T> & low, std::vector<T> & parent, int time)
{
    visited[node] = true;
    discovered[node] = low[node] = ++time;
    for(auto neighbor_node: graph[node])
    {
        if(!visited[neighbor_node])
        {
            parent[neighbor_node] = node;
            dfs_tarjan(graph, neighbor_node, visited, discovered, low, parent, time);
            low[node] = std::min(low[node], low[neighbor_node]);
        }
        else if(neighbor_node != parent[node])
        {
            low[node] = std::min(low[node], discovered[neighbor_node]);
        }
    }

}



template <typename T>
requires VertexRequirement<T>
std::pair<std::vector<T>, std::vector<T>> tarjan_algorithm(std::vector<std::vector<T>> & edges)
{
    int number_of_nodes = edges.size();
    std::vector<std::vector<T>> graph(number_of_nodes);
    for(const auto & edge: edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    auto invalid = std::numeric_limits<T>::max();

    std::vector visited(number_of_nodes, false);
    std::vector<T> discovered(number_of_nodes, invalid);
    std::vector<T> low(number_of_nodes, invalid);
    std::vector<T> parent(number_of_nodes, invalid);
    int time{};

    for(T node{}; node< number_of_nodes; ++node)
    {
        if(!visited[node])
            dfs_tarjan(graph, node, visited, discovered, low, parent, time);
    }
    return std::make_pair(low, discovered);
}



#endif //LR_PLANARITY_TEST_H

