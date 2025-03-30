//
// Created by andreas on 04.01.24.
//

#ifndef MINIMUM_SPANNING_TREE_ALGORITHMS_H
#define MINIMUM_SPANNING_TREE_ALGORITHMS_H
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>


template <typename VertexType, typename DistanceType>
    requires std::is_unsigned_v<VertexType> && std::is_arithmetic_v<DistanceType>
std::tuple<std::vector<VertexType>, std::vector<DistanceType>> minimum_spanning_tree_prim(VertexType start_vertex,
    const std::vector<std::vector<
        std::pair<VertexType,
                  DistanceType>>>& graph)
{
    if (start_vertex > graph.size())
        throw std::out_of_range("The start_vertex id is larger than the graph size.");

    auto number_of_vertices = graph.size();
    std::vector<DistanceType> weights(number_of_vertices, std::numeric_limits<DistanceType>::max());
    std::vector<VertexType> spanning_tree_parents(number_of_vertices, std::numeric_limits<VertexType>::max());
    std::vector<bool> visited_vertices(number_of_vertices, false);
    std::priority_queue<std::pair<DistanceType, VertexType>,
                        std::vector<std::pair<DistanceType, VertexType>>,
                        std::greater<>> pq;
    pq.push({static_cast<DistanceType>(0), start_vertex});

    weights[start_vertex] = static_cast<DistanceType>(0);
    while (!pq.empty())
    {
        VertexType current_vertex = pq.top().second;
        pq.pop();
        if (visited_vertices[current_vertex])
            continue;
        visited_vertices[current_vertex] = true;
        for (const auto& edge : graph[current_vertex])
        {
            auto next_vertex = edge.first;
            auto weight = edge.second;
            if (!visited_vertices[next_vertex] && weights[next_vertex] > weight)
            {
                weights[next_vertex] = weight;
                pq.push({weight, next_vertex});
                spanning_tree_parents[next_vertex] = current_vertex;
            }
        }
    }
    return std::make_tuple(spanning_tree_parents, weights);
}

template <typename VertexType, typename DistanceType>
    requires std::is_unsigned_v<VertexType> && std::is_arithmetic_v<DistanceType>
std::tuple<std::vector<VertexType>,
           std::vector<DistanceType>> minimum_spanning_tree_prim_matrix(VertexType start_vertex,
                                                                        const std::vector<std::vector<DistanceType>>&
                                                                        graph)
{
    if (start_vertex > graph.size())
        throw std::out_of_range("The start_vertex id is larger than the graph size.");

    auto number_of_vertices = graph.size();
    std::vector<DistanceType> weights(number_of_vertices, std::numeric_limits<DistanceType>::max());
    std::vector<VertexType> spanning_tree_parents(number_of_vertices, std::numeric_limits<VertexType>::max());
    std::vector<bool> visited_vertices(number_of_vertices, false);
    std::priority_queue<std::pair<DistanceType, VertexType>,
                        std::vector<std::pair<DistanceType, VertexType>>,
                        std::greater<>> pq;
    pq.push({static_cast<DistanceType>(0), start_vertex});

    weights[start_vertex] = static_cast<DistanceType>(0);
    while (!pq.empty())
    {
        VertexType current_vertex = pq.top().second;
        pq.pop();
        if (visited_vertices[current_vertex])
            continue;
        visited_vertices[current_vertex] = true;
        for (VertexType next_vertex{}; next_vertex < graph.size(); ++next_vertex)
        {
            auto weight = graph[current_vertex][next_vertex];
            if (!visited_vertices[next_vertex] && weights[next_vertex] > weight)
            {
                weights[next_vertex] = weight;
                pq.push({weight, next_vertex});
                spanning_tree_parents[next_vertex] = current_vertex;
            }
        }
    }
    return std::make_tuple(spanning_tree_parents, weights);
}

#endif //MINIMUM_SPANNING_TREE_ALGORITHMS_H
