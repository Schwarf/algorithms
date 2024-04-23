//
// Created by andreas on 23.04.24.
//

#ifndef DATA_STRUCTURES_MINIMUM_HEIGHT_TREES_H
#define DATA_STRUCTURES_MINIMUM_HEIGHT_TREES_H
// A tree is an undirected graph in which any two vertices are connected by exactly one path.
// In other words, any connected graph without simple cycles is a tree.
// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [s_i, t_i]
// indicates that there is an undirected edge between the two nodes ai and bi in the tree,
// you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h.
// Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
// Return a list of all MHTs' root labels. You can return the answer in any order.
// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

template<typename T>
requires std::is_unsigned_v<T>
std::vector<T> find_minimum_height_trees(std::vector<std::vector<T>> &edges, int n) {
    if (n == 1 || edges.empty())
        return {T{}};

    std::vector<T> leaves;
    std::unordered_map<int, std::unordered_set<int>> graph;

    for (const auto &edge: edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }

    // Determine leaf nodes by checking for only one adjacent/child node
    for (const auto &[label, children]: graph)
        if (children.size() == 1)
            leaves.push_back(label);

    while (n > 2) {
        // Reduce number of nodes by size of current levaes.
        n -= leaves.size();
        std::vector<T> new_leaves;
        for (const auto &leaf: leaves) {
            auto u = *graph[leaf].begin(); // Get the only neighbor of a leaf node
            graph[u].erase(leaf); // Remove the leaf itself from this neighbor
            if (graph[u].size() == 1) //If neighbor has only one adjacent/child add it to new_leaves
                new_leaves.push_back(u);
        }
        leaves = new_leaves;
    }

    return leaves;
}

template<typename T>
requires std::is_unsigned_v<T>
std::vector<T> find_minimum_height_trees_alternative(std::vector<std::vector<T>> &edges, int n) {

    if (n == 1)
        return {T{}}; // A special case where the single node is the root.

    // Step 1: Build the graph as an adjacency list.
    std::vector<std::vector<T>> graph(n);
    std::vector<T> degree(n, T{});
    for (const auto &edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    // Step 2: Initialize leaves
    std::queue<T> leaves;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) { // It's a leaf
            leaves.push(i);
        }
    }

    // Step 3: Trim leaves iteratively until 1 or 2 nodes remain
    int remaining_nodes = n;
    while (remaining_nodes > 2) {
        auto leaves_size = leaves.size();
        remaining_nodes -= leaves_size;
        for (int i{}; i < leaves_size; ++i) {
            auto leaf = leaves.front();
            leaves.pop();
            for (int neighbor: graph[leaf]) {
                if (--degree[neighbor] == T{1}) {
                    leaves.push(neighbor);
                }
            }
        }
    }

    // Collect all remaining nodes, these are the roots of MHTs
    std::vector<T> result;
    while (!leaves.empty()) {
        result.push_back(leaves.front());
        leaves.pop();
    }

    return result;
}


#endif //DATA_STRUCTURES_MINIMUM_HEIGHT_TREES_H
