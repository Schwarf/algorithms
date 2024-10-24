//
// Created by andreas on 24.10.24.
//

#ifndef DATA_STRUCTURES_ARE_BINARY_TREES_FLIP_EQUIVALENT_H
#define DATA_STRUCTURES_ARE_BINARY_TREES_FLIP_EQUIVALENT_H
// For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
// A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
// Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

#include "tree_node.h"

template <typename T>
bool are_flip_equivalent_recursive(TreeNode<T> *root1, TreeNode<T> *root2) {
    // Both trees are empty
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    // Just one of the trees is empty
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    // Corresponding values differ
    if (root1->value != root2->value) {
        return false;
    }

    // Check if corresponding subtrees are flip equivalent
    bool no_swap = are_flip_equivalent_recursive(root1->left, root2->left) &&
            are_flip_equivalent_recursive(root1->right, root2->right);
    // Check if opposite subtrees are flip equivalent
    bool swap = are_flip_equivalent_recursive(root1->left, root2->right) &&
            are_flip_equivalent_recursive(root1->right, root2->left);

    return swap || no_swap;
}

#endif //DATA_STRUCTURES_ARE_BINARY_TREES_FLIP_EQUIVALENT_H
