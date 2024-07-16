//
// Created by andreas on 16.07.24.
//

#ifndef DATA_STRUCTURES_LOWEST_COMMON_ANCESTOR_H
#define DATA_STRUCTURES_LOWEST_COMMON_ANCESTOR_H

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
// p and q as the lowest node in T that has both p and q as descendants
// (where we allow a node to be a descendant of itself)."

#include "tree_node.h"

template<typename T>
TreeNode<T> *least_common_ancestor(TreeNode<T> *root, T value1, T value2) {
    if (!root)
        return nullptr;
    if (root->value == value1 || root->value == value2)
        return root;

    auto left_lca = least_common_ancestor(root->left, value1, value2);
    auto right_lca = least_common_ancestor(root->right, value1, value2);

    if (!left_lca)
        return right_lca;
    else if (!right_lca)
        return left_lca;

    return root;
}

#endif //DATA_STRUCTURES_LOWEST_COMMON_ANCESTOR_H
