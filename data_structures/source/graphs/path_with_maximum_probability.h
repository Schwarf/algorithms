//
// Created by andreas on 31.08.24.
//

#ifndef DATA_STRUCTURES_PATH_WITH_MAXIMUM_PROBABILITY_H
#define DATA_STRUCTURES_PATH_WITH_MAXIMUM_PROBABILITY_H
// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where
// edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of
// success of traversing that edge probability[i].
// Given two nodes start and end, find the path with the maximum probability of success to go from start to end
// and return its success probability.
// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the
// correct answer by at most 1e-5.
#include <vector>
#include <queue>

double
max_probability_path_bellman_ford(int n, std::vector<std::vector<int>>& edges, std::vector<double>& probabilities,
                                  int start_node, int end_node)
{
    std::vector<double> maximum_probability(n);
    maximum_probability[start_node] = 1.0;
    // iterating n-1 one times in a graph with n nodes yields the longest path without cycles
    for (int i{}; i < n - 1; ++i)
    {
        auto has_update = false;
        // We update for each
        for (int edge_count{}; edge_count < edges.size(); ++edge_count)
        {
            const auto node1 = edges[edge_count][0];
            const auto node2 = edges[edge_count][1];
            if (maximum_probability[node1] * probabilities[edge_count] > maximum_probability[node2])
            {
                maximum_probability[node2] = maximum_probability[node1] * probabilities[edge_count];
                has_update = true;
            }
            if (maximum_probability[node2] * probabilities[edge_count] > maximum_probability[node1])
            {
                maximum_probability[node1] = maximum_probability[node2] * probabilities[edge_count];
                has_update = true;
            }
        }
        if (!has_update)
            break;
    }
    return maximum_probability[end_node];
}

double
max_probability_path_dijkstra(int n, std::vector<std::vector<int>>& edges, std::vector<double>& probabilities,
                              int start_node, int end_node)
{
    std::vector<std::vector<std::pair<int, double>>> graph(n);
    std::priority_queue<std::pair<double, int>> q;
    q.emplace(1.0, start_node);
    std::vector<bool> visited(n);
    // build an adjacency list to represent graph
    for (int edge_count{}; edge_count < edges.size(); ++edge_count)
    {
        const auto node1 = edges[edge_count][0];
        const auto node2 = edges[edge_count][1];
        graph[node1].emplace_back(node2, probabilities[edge_count]);
        graph[node2].emplace_back(node1, probabilities[edge_count]);
    }
    while (!q.empty())
    {
        const auto [probability, node] = q.top();
        q.pop();
        if (node == end_node)
            return probability;
        if (visited[node])
            continue;
        visited[node] = true;
        for (const auto& [next_node, next_probability] : graph[node])
        {
            if (visited[next_node])
                continue;
            q.emplace(next_probability * probability, next_node);
        }
    }
    return 0;
}


double
max_probability_path_shortest_path_faster_algorithm(int n, std::vector<std::vector<int>>& edges,
                                                    std::vector<double>& probabilities,
                                                    int start_node, int end_node)
{
    std::vector<std::vector<std::pair<int, double>>> graph(n);
    std::vector<bool> visited(n);
    // build an adjacency list to represent graph
    for (int edge_count{}; edge_count < edges.size(); ++edge_count)
    {
        const auto node1 = edges[edge_count][0];
        const auto node2 = edges[edge_count][1];
        graph[node1].emplace_back(node2, probabilities[edge_count]);
        graph[node2].emplace_back(node1, probabilities[edge_count]);
    }
    std::vector<double> maximum_probability(n);
    maximum_probability[start_node] = 1.0;

    std::queue<int> q;
    q.emplace(start_node);
    while (!q.empty())
    {
        auto current_node = q.front();
        q.pop();
        for (const auto& [next_node, next_probability] : graph[current_node])
        {
            if (maximum_probability[current_node] * next_probability > maximum_probability[next_node])
            {
                maximum_probability[next_node] = maximum_probability[current_node] * next_probability;
                q.emplace(next_node);
            }
        }
    }
    return maximum_probability[end_node];
}

#endif //DATA_STRUCTURES_PATH_WITH_MAXIMUM_PROBABILITY_H
