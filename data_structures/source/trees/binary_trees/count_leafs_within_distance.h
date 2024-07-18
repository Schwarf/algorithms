//
// Created by andreas on 18.07.24.
//

#ifndef DATA_STRUCTURES_COUNT_LEAFS_WITHIN_DISTANCE_H
#define DATA_STRUCTURES_COUNT_LEAFS_WITHIN_DISTANCE_H

#include "tree_node.h"
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

template<typename T>
void dfs(TreeNode<T> *node, std::unordered_map<TreeNode<T> *, std::vector<TreeNode<T> *>> &graph,
         std::unordered_set<TreeNode<T> *> &leafs) {
    if (!node->left && !node->right) {
        leafs.insert(node);
        return;
    }

    if (node->left) {
        graph[node].push_back(node->left);
        graph[node->left].push_back(node);
        dfs(node->left, graph, leafs);
    }
    if (node->right) {
        graph[node].push_back(node->right);
        graph[node->right].push_back(node);
        dfs(node->right, graph, leafs);
    }
}

template<typename T>
int count_leafs_within_distance(TreeNode<T> *root, int distance) {
    std::unordered_map<TreeNode<T> *, std::vector<TreeNode<T> *>> graph;
    std::unordered_set<TreeNode<T> *> leafs;
    dfs(root, graph, leafs);

    int count{};
    for (const auto &leaf: leafs) {
        std::queue<TreeNode<T> *> q{{leaf}};
        std::unordered_set<TreeNode<T> *> visited;
        visited.insert(leaf);
        for (int i{}; i <= distance; ++i) {
            int size = q.size();
            for (int j{}; j < size; ++j) {
                auto current = q.front();
                q.pop();
                if (current != leaf && leafs.find(current) != leafs.end()) {
                    count++;
                }
                for (const auto &node: graph[current]) {
                    if (visited.find(node) == visited.end()) {
                        q.push(node);
                        visited.insert(node);
                    }
                }
            }

        }
    }
    return count / 2;
}

#endif //DATA_STRUCTURES_COUNT_LEAFS_WITHIN_DISTANCE_H
