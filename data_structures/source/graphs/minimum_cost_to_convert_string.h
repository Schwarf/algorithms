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

std::vector<long long> dijkstra(int start, std::vector<std::vector<std::pair<int, int>>> graph) {
    constexpr long long max_ll = std::numeric_limits<long long>::max();
    std::vector<long long> costs(26, max_ll);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    q.emplace(start, 0);
    while (!q.empty()) {
        auto [current_char, current_cost] = q.top();
        q.pop();
        if (costs[current_char] < current_cost)
            continue;

        for (auto &[neighbor_char, neighbor_cost]: graph[current_char]) {
            auto new_cost = neighbor_cost + current_cost;
            if (new_cost < costs[neighbor_cost]) {
                costs[neighbor_cost] = new_cost;
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
    for (int i{}; i < n; ++i) {
        dijkstra(i, graph);
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

#endif //DATA_STRUCTURES_MINIMUM_COST_TO_CONVERT_STRING_H
