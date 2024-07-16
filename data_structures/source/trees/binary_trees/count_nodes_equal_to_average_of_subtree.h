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

// Question: Is this postorder traversal?
template<typename T>
std::pair<int, T> dfs(TreeNode<T> root, int &count) {
    if (!root)
        return {0, 0};
    std::pair<T, int> left = dfs(root->left, count);
    std::pair<T, int> right = dfs(root->right, count);
    int sum = left.first + right.first + root->val;
    int number = 1 + left.second + right.second;
    if (root->val == sum / number)
        count++;
    return {sum, number};
}

template<typename T>
int averageOfSubtree(TreeNode<T> *root) {
    int count{};
    dfs(root, count);
    return count;
}

#endif //COUNT_NODES_EQUAL_TO_AVERAGE_OF_SUBTREE_H
