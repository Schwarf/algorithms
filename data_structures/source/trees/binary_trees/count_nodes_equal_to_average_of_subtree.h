//
// Created by andreas on 02.11.23.
//

#ifndef COUNT_NODES_EQUAL_TO_AVERAGE_OF_SUBTREE_H
#define COUNT_NODES_EQUAL_TO_AVERAGE_OF_SUBTREE_H
// Given a binary tree, return the number of nodes where the value of the node is equal to the
// average of the values in its subtree.
// Boundary conditions:
// - The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
// - A subtree of root is a tree consisting of root and all of its descendants.
#include <utility>
#include "tree_node.h"

template<typename T>
std::pair<T, int> dfs_average_of_subtree(TreeNode<T>* root, int& count) {
    if (!root)
        return {0, 0};
    auto left = dfs_average_of_subtree(root->left, count);
    auto right = dfs_average_of_subtree(root->right, count);
    T sum = left.first + right.first + root->value;
    int number = 1 + left.second + right.second;
    if (root->value == sum / number)
        count++;
    return {sum, number};
}

template<typename T>
int average_of_subtree(TreeNode<T> *root) {
    int count{};
    dfs_average_of_subtree(root, count);
    return count;
}

#endif //COUNT_NODES_EQUAL_TO_AVERAGE_OF_SUBTREE_H
