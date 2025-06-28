//
// Created by andreas on 28.06.25.
//
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//
// A valid BST is defined as follows:
//    The left of a node contains only nodes with keys less than the node's key.
//    The right subtree of a node contains only nodes with keys greater than the node's key.
//    Both the left and right subtrees must also be binary search trees.

#include "tree_node.h"
#include <limits>

template <typename T>
bool is_valid_BST(TreeNode<T>* root, long long min = std::numeric_limits<long long>::min(), long long max =
std::numeric_limits<long long>::max()) {
    if(!root)
        return true;

    if(root->value <= min || root->value >= max)
        return false;

    return is_valid_BST(root->left, min, root->value) && is_valid_BST(root->right, root->value, max);

}