//
// Created by andreas on 15.04.24.
//

#ifndef DATA_STRUCTURES_COMPUTE_SUM_ROOT_TO_ALL_LEAFS_H
#define DATA_STRUCTURES_COMPUTE_SUM_ROOT_TO_ALL_LEAFS_H

#include "tree_node.h"

// You are given the root of a binary tree containing digits from 0 to 9 only.
// Each root-to-leaf path in the tree represents a number.
// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the
// answer will fit in a 32-bit integer.
// A leaf node is a node with no children.

template<typename T>
void dfs(TreeNode<T> *node, T current, T &sum) {
    if (!node)
        return;
    if (!node->left && !node->right) {
        sum += current * 10 + node->value;
    }
    current *= 10;
    current += node->value;
    dfs(node->left, current, sum);
    dfs(node->right, current, sum);
}

template<typename T>
T sum_of_root_to_leafs(TreeNode<T> *root) {
    T sum{};
    T current{};
    dfs(root, current, sum);
    return sum;
}

#endif //DATA_STRUCTURES_COMPUTE_SUM_ROOT_TO_ALL_LEAFS_H
