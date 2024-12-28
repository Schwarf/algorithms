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
    std::vector<NodeType> in_degree(graph.get_all_nodes());
    std::vector<NodeType> topological_order;
    for(const auto node: graph.get_all_nodes())
    {
        for(const auto neighbor: graph.get_all_neighbours(node))
        {
            ++in_degree[neighbor];
        }
    }

    // Find all start nodes
    std::queue<NodeType> queue;
    for(int i{}; i < in_degree.size(); ++i)
    {
        if(in_degree[i] == 0)
            queue.push(i);
    }

    while(!queue.empty())
    {
        auto current = queue.front();
        queue.pop();
        topological_order.push_back(current);
        for(const auto neighbor: graph.get_all_neighbours(current))
        {
            --in_degree[neighbor];
            if(in_degree[neighbor] == 0)
                queue.push(neighbor);
        }
    }
    if(topological_order.size() != graph.get_all_nodes().size())
        return {};

    return topological_order;
}

#endif //KAHNS_ALGORITHM_H
