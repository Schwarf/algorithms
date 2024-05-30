//
// Created by andreas on 24.09.22.
//

#ifndef PATH_SUM_BINARY_TREE_H
#define PATH_SUM_BINARY_TREE_H
/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node
values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
 */
#include <vector>
#include "./../data_structures/source/trees/binary_trees/tree_node.h"

template<typename T>
void sum(TreeNode<T> *node, T target_path_sum, std::vector<T> &path, std::vector<std::vector<T>> &result) {
    if (!node)
        return;
    path.push_back(node->value);
    target_path_sum -= node->value;
    if (node->left == nullptr && node->right == nullptr && target_path_sum == 0) {
        result.push_back(path);
    } else {
        sum(node->left, target_path_sum, path, result);
        sum(node->right, target_path_sum, path, result);
    }
    // pop back to evaluate all branches of given node
    path.pop_back();
}

template<typename T>
std::vector<std::vector<T>> path_sum(TreeNode<T> *root, T target_path_sum) {
    std::vector<std::vector<T>> result;
    std::vector<T> path;
    sum(root, target_path_sum, path, result);
    return result;
}

#endif //PATH_SUM_BINARY_TREE_H

