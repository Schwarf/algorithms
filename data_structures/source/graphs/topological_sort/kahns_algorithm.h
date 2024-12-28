//
// Created by andreas on 28.12.24.
//

#ifndef KAHNS_ALGORITHM_H
#define KAHNS_ALGORITHM_H

#include <vector>
#include <queue>
#include "graphs/graph.h"

template <typename NodeType>
std::vector<NodeType> kahns_algorithm(const DirectedGraph<NodeType>& graph)
{
    std::unordered_map<NodeType, int> in_degree;
    std::vector<NodeType> topological_order;
    for(const auto node: graph.get_all_nodes())
    {
        for(const auto neighbor: graph.get_neighbors(node))
        {
            in_degree[neighbor] += 1;
        }
    }

    // Find all start nodes
    std::queue<NodeType> queue;
    for(const auto node: graph.get_all_nodes())
    {
        if(in_degree[node] == 0)
            queue.push(node);
    }

    while(!queue.empty())
    {
        auto current = queue.front();
        queue.pop();
        topological_order.push_back(current);
        for(const auto neighbor: graph.get_neighbors(current))
        {
            in_degree[neighbor] -= 1;
            if(in_degree[neighbor] == 0)
                queue.push(neighbor);
        }
    }
    if(topological_order.size() != graph.get_all_nodes().size())
        return {};

    return topological_order;
}

#endif //KAHNS_ALGORITHM_H
