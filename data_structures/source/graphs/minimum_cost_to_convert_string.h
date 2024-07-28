//
// Created by andreas on 28.07.24.
//

#ifndef DATA_STRUCTURES_MINIMUM_COST_TO_CONVERT_STRING_H
#define DATA_STRUCTURES_MINIMUM_COST_TO_CONVERT_STRING_H
// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters.
// You are also given two 0-indexed character arrays original and changed, and an integer array cost,
// where cost[i] represents the cost of changing the character original[i] to the character changed[i].
// You start with the string source. In one operation, you can pick a character x from the string and change
// it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x,
// and changed[j] == y.
// Return the minimum cost to convert the string source to the string target using any number of operations.
// If it is impossible to convert source to target, return -1.
//
// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

std::vector<long long> dijkstra(int start, const std::vector<std::vector<std::pair<int, int>>> &graph) {
    constexpr long long max_ll = std::numeric_limits<long long>::max();
    std::vector<long long> costs(26, max_ll);
    std::priority_queue<std::pair<int, long long>, std::vector<std::pair<int, long long>>, std::greater<>> q;
    q.emplace(start, 0);
    while (!q.empty()) {
        auto [current_char, current_cost] = q.top();
        q.pop();
        if (costs[current_char] < current_cost)
            continue;

        for (auto &[neighbor_char, neighbor_cost]: graph[current_char]) {
            auto new_cost = neighbor_cost + current_cost;
            if (new_cost < costs[neighbor_char]) {
                costs[neighbor_char] = new_cost;
                q.emplace(neighbor_char, new_cost);
            }
        }
    }
    return costs;
}


long long minimum_cost_to_convert_string(std::string &source, std::string &target, std::vector<char> &original,
                                         std::vector<char> &changed, std::vector<int> &costs) {

    std::vector<std::vector<std::pair<int, int>>> graph(26);
    int n = original.size();
    for (int i{}; i < n; ++i) {
        graph[original[i] - 'a'].push_back({changed[i] - 'a', costs[i]});
    }
    std::vector<std::vector<long long>> conversion_costs(26, std::vector<long long>(26));
    for (int i{}; i < 26; ++i) {
        conversion_costs[i] = dijkstra(i, graph);
    }
    long long total_costs{};
    for (int i{}; i < source.length(); ++i) {
        if (source[i] != target[i]) {
            if (conversion_costs[source[i] - 'a'][target[i] - 'a'] == std::numeric_limits<long long>::max())
                return -1;
            total_costs += conversion_costs[source[i] - 'a'][target[i] - 'a'];

        }
    }
    return total_costs;
}

void floyd_warshall(const std::vector<std::vector<long long>> &graph,
                    std::vector<std::vector<long long>> &conversion_costs) {
    for (int transition_char{}; transition_char < 26; ++transition_char) {
        for (int start_char{}; start_char < 26; ++start_char) {
            for (int end_char{}; end_char < 26; ++end_char) {
                if (graph[start_char][transition_char] != std::numeric_limits<long long>::max() &&
                    graph[transition_char][end_char] != std::numeric_limits<long long>::max()) {
                    conversion_costs[start_char][end_char] = std::min(conversion_costs[start_char][end_char],
                                                                      graph[start_char][transition_char] +
                                                                      graph[transition_char][end_char]);
                }
            }
        }
    }
}


long long
minimum_cost_to_convert_string_floyd_warshall(std::string &source, std::string &target, std::vector<char> &original,
                                              std::vector<char> &changed, std::vector<int> &costs) {
    std::vector<std::vector<long long>> graph(26, std::vector<long long>(26, std::numeric_limits<long long>::max()));
    int n = original.size();
    for (int i{}; i < n; ++i) {
        graph[original[i] - 'a'][changed[i] - 'a'] = costs[i];
    }
    std::vector<std::vector<long long>> conversion_costs(26, std::vector<long long>(26,
                                                                                    std::numeric_limits<long long>::max()));

    floyd_warshall(graph, conversion_costs);
    long long total_costs{};
    for (int i{}; i < source.length(); ++i) {
        if (source[i] != target[i]) {
            if (conversion_costs[source[i] - 'a'][target[i] - 'a'] == std::numeric_limits<long long>::max())
                return -1;
            total_costs += conversion_costs[source[i] - 'a'][target[i] - 'a'];

        }
    }
    return total_costs;
}

#endif //DATA_STRUCTURES_MINIMUM_COST_TO_CONVERT_STRING_H
