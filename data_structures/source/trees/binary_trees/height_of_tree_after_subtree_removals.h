//
// Created by andreas on 29.10.24.
//

#ifndef DATA_STRUCTURES_HEIGHT_OF_TREE_AFTER_SUBTREE_REMOVALS_H
#define DATA_STRUCTURES_HEIGHT_OF_TREE_AFTER_SUBTREE_REMOVALS_H
// You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
// You have to perform m independent queries on the tree where in the ith query you do the following:
// Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
// Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.
// Note:
// The queries are independent, so the tree returns to its initial state after each query.
// The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
// Constraints:
//
// The number of nodes in the tree is n.
//  All the values in the tree are unique.
// 2 <= n <= 100000
// 1 <= Node.value <= n
//
// m == queries.length
// 1 <= m <= min(n, 10000)
// 1 <= queries[i] <= n
// No query does contain the root value

#include <vector>
#include <unordered_map>
#include "tree_node.h"

// Global static variables
int max_height_after_removal[100001];  // Array to store max height after removing each node
int current_max_height = 0;            // Variable to track current maximum height

// Left-to-right traversal function
template<typename T>
requires std::is_unsigned_v<T>
void traverse_left_to_right(TreeNode<T> *node, int current_height) {
    if (!node) return;

    // Store the maximum height if this node were removed
    max_height_after_removal[node->value] = current_max_height;

    // Update the current maximum height
    current_max_height = std::max(current_max_height, current_height);

    // Traverse left subtree first, then right
    traverse_left_to_right(node->left, current_height + 1);
    traverse_left_to_right(node->right, current_height + 1);
}

// Right-to-left traversal function
template<typename T>
requires std::is_unsigned_v<T>
void traverse_right_to_left(TreeNode<T> *node, int current_height) {
    if (!node) return;

    // Update the maximum height if this node were removed
    max_height_after_removal[node->value] = std::max(max_height_after_removal[node->value], current_max_height);

    // Update the current maximum height
    current_max_height = std::max(current_height, current_max_height);

    // Traverse right subtree first, then left
    traverse_right_to_left(node->right, current_height + 1);
    traverse_right_to_left(node->left, current_height + 1);
}

// Main function to handle queries and return results
template<typename T>
requires std::is_unsigned_v<T>
std::vector<int> height_of_trees(TreeNode<T> *root, const std::vector<T> &queries) {
    // Reset global variables
    current_max_height = 0;

    // Perform left-to-right traversal
    traverse_left_to_right(root, 0);

    // Reset current_max_height and perform right-to-left traversal
    current_max_height = 0;
    traverse_right_to_left(root, 0);

    // Process queries using precomputed heights
    std::vector<int> query_results;
    for (T query: queries) {
        query_results.push_back(max_height_after_removal[query]);
    }

    return query_results;
}

template<typename T>
requires std::is_unsigned_v<T>
int compute_height(TreeNode<T> *node, std::unordered_map<TreeNode<T> *, int> &height_cache) {
    if (!node)
        return -1;
    if (height_cache.find(node) != height_cache.end())
        return height_cache[node];

    height_cache[node] =
            1 + std::max(compute_height(node->left, height_cache), compute_height(node->right, height_cache));
    return height_cache[node];
}

template<typename T>
requires std::is_unsigned_v<T>
void dfs(TreeNode<T> *node, int depth, int max_height_so_far, std::unordered_map<T, int> &result_map,
         std::unordered_map<TreeNode<T> *, int> &height_cache) {
    if (!node)
        return;

    result_map[node->value] = max_height_so_far;
    dfs(node->left, depth + 1, std::max(max_height_so_far, depth + 1 + compute_height(node->right, height_cache)),
        result_map,
        height_cache);
    dfs(node->right, depth + 1, std::max(max_height_so_far, depth + 1 + compute_height(node->left, height_cache)),
        result_map,
        height_cache);


}


template<typename T>
requires std::is_unsigned_v<T>
std::vector<int> height_of_trees_one_traversal(TreeNode<T> *root, const std::vector<T> &queries) {

    std::unordered_map<T, int> result_map;
    std::unordered_map<TreeNode<T> *, int> height_cache;

    dfs(root, 0, 0, result_map, height_cache);
    std::vector<int> result(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        result[i] = result_map[queries[i]];
    }
    return result;
}


#endif //DATA_STRUCTURES_HEIGHT_OF_TREE_AFTER_SUBTREE_REMOVALS_H

