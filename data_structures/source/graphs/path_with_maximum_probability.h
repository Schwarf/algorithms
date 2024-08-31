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

double
max_probability_path_bellman_ford(int n, std::vector<std::vector<int>> &edges, std::vector<double> &probabilities,
                                  int start_node, int end_node) {
    std::vector<double> maximum_probability(n);
    maximum_probability[start_node] = 1.0;
    // iterating n-1 one times in a graph with n nodes yields the longest path without cycles
    for (int i{}; i < n - 1; ++i) {
        auto has_update = false;
        // We update for each
        for (int edge_count{}; edge_count < edges.size(); ++edge_count) {
            auto node1 = edges[edge_count][0];
            auto node2 = edges[edge_count][1];
            auto probability = probabilities[edge_count];
            if (maximum_probability[node1] * probability > maximum_probability[node2]) {
                maximum_probability[node2] = maximum_probability[node1] * probability;
                has_update = true;
            }
            if (maximum_probability[node2] * probability > maximum_probability[node1]) {
                maximum_probability[node1] = maximum_probability[node2] * probability;
                has_update = true;
            }
        }
        if (!has_update)
            break;
    }
    return maximum_probability[end_node];

}

#endif //DATA_STRUCTURES_PATH_WITH_MAXIMUM_PROBABILITY_H
