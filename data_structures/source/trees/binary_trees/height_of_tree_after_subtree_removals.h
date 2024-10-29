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
#include "tree_node.h"

template<typename T>
requires std::is_unsigned_v<T>
std::vector<T>
left_right_traversal(TreeNode<T> *node, std::vector<T> &node_heights, int current_height, int current_max_height) {
    if (!node)
        return;
    node_heights[node->value] = current_max_height;
    current_max_height = std::max(current_max_height, current_height);
    left_right_traversal(node->left, current_height + 1, current_max_height);
    left_right_traversal(node->right, current_height + 1, current_max_height);
}

template<typename T>
requires std::is_unsigned_v<T>
std::vector<T>
right_left_traversal(TreeNode<T> *node, std::vector<T> &node_heights, int current_height, int current_max_height) {
    if (!node)
        return;
    node_heights[node->value] = current_max_height;
    current_max_height = std::max(current_max_height, current_height);
    left_right_traversal(node->right, current_height + 1, current_max_height);
    left_right_traversal(node->left, current_height + 1, current_max_height);

}

template<typename T>
requires std::is_unsigned_v<T>
std::vector<T> height_of_trees(TreeNode<T> *root, std::vector<T> queries) {
    int current_max_height{};
    // we deal with a maximum of 100000 nodes
    std::vector<T> node_heights(100001);
    left_right_traversal(root, 0, current_max_height);
    current_max_height = 0;
    right_left_traversal(root, 0, current_max_height);
    std::vector<int> heights;
    for (int i{}; i < queries.size(); ++i) {
        heights[i] = node_heights[queries[i]];
    }
    return heights;
}


#endif //DATA_STRUCTURES_HEIGHT_OF_TREE_AFTER_SUBTREE_REMOVALS_H

