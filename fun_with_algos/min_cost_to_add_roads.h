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

#endif //MIN_COST_TO_ADD_ROADS_H
