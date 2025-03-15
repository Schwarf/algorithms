//
// Created by andreas on 15.03.25.
//

#ifndef MIN_COST_TO_ADD_ROADS_H
#define MIN_COST_TO_ADD_ROADS_H
// There are N cities numbered from 1 to N.
// You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to
// connect city1 and city2together. (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)
// Return the minimum cost so that for every pair of cities, there exists a path of connections
// (possibly of length 1) that connects those two cities together. The cost is the sum of the connection costs used.
// If the task is impossible, return -1.

#include <vector>
#include <algorithm>
#include <queue>

struct UnionFind {
    std::vector<int> parent;
    std::vector<int> rank;

    // Initialize Union-Find structure for n elements
    UnionFind(int n) : parent(n + 1), rank(n + 1, 0) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank. Returns true if union was successful.
    bool unionize(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB)
            return false;

        if (rank[rootA] < rank[rootB])
            parent[rootA] = rootB;
        else if (rank[rootA] > rank[rootB])
            parent[rootB] = rootA;
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        return true;
    }
};

int min_cost_to_add_roads(int N, std::vector<std::vector<int>>& connections) {
    // Sort connections based on cost
    std::sort(connections.begin(), connections.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[2] < b[2];
    });

    UnionFind uf(N);
    int total_cost = 0;
    int edges_count = 0;

    // Process each connection in increasing order of cost
    for (const auto &connection : connections) {
        if (uf.unionize(connection[0], connection[1])) {
            total_cost += connection[2];
            edges_count++;
        }
    }

    // Check if all cities are connected
    return (edges_count == N - 1) ? total_cost : -1;
}
int min_cost_to_add_roads_prim(int N, std::vector<std::vector<int>>& connections) {
    // Sort connections based on cost
    std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
    for (const auto& connection : connections) {
        int u = connection[0], v = connection[1], cost = connection[2];
        graph[u].emplace_back(v, cost);
        graph[v].emplace_back(u, cost);
    }
    std::vector<bool> visited(N + 1, false);
    int total_cost = 0;
    int edges_used = 0;
    // Min-heap (priority queue) where each element is (cost, city)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

    // Start with city 1 (arbitrary start point) with cost 0
    minHeap.push({0, 1});

    // While there are edges to process and we haven't connected all cities
    while (!minHeap.empty() && edges_used < N) {
        auto [cost, city] = minHeap.top();
        minHeap.pop();

        // If this city is already visited, skip it
        if (visited[city])
            continue;

        // Mark the city as visited and add the cost
        visited[city] = true;
        total_cost += cost;
        edges_used++;

        // For every neighbor of the current city, if it's not visited, add the edge to the heap
        for (const auto& neighbor : graph[city]) {
            int nextCity = neighbor.first;
            int nextCost = neighbor.second;
            if (!visited[nextCity]) {
                minHeap.push({nextCost, nextCity});
            }
        }
    }

    // If we have connected all N cities, edgesUsed should equal N
    return (edges_used == N) ? total_cost : -1;
}
#endif //MIN_COST_TO_ADD_ROADS_H
