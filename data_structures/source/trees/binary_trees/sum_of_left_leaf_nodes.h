//
// Created by andreas on 14.04.24.
//

#ifndef DATA_STRUCTURES_SUM_OF_LEFT_LEAF_NODES_H
#define DATA_STRUCTURES_SUM_OF_LEFT_LEAF_NODES_H

#include "tree_node.h"

template<typename T>
void dfs(TreeNode<T> *node, T &sum) {
    if (!node)
        return;
    if (node->left && !node->left->left && !node->left->right)
        sum += node->left->value;

    dfs(node->left, sum);
    dfs(node->right, sum);
}

template<typename T>
T sum_of_left_leafs(TreeNode<T> *root) {
    T sum{};
    dfs(root, sum);
    return sum;
}

#endif //DATA_STRUCTURES_SUM_OF_LEFT_LEAF_NODES_H

