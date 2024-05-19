//
// Created by andreas on 19.05.24.
//

#ifndef DATA_STRUCTURES_REMOVE_LEAFE_NODES_WITH_TARGET_VALUE_H
#define DATA_STRUCTURES_REMOVE_LEAFE_NODES_WITH_TARGET_VALUE_H
// Given a binary tree root and an integer target, delete all the leaf nodes with value target.
// Note that once you delete a leaf node with value target,
// if its parent node becomes a leaf node and has the value target, it should also be deleted
// (you need to continue doing that until you cannot).
#include "tree_node.h"

template<typename T>
TreeNode<T> *remove_leaf_nodes(TreeNode<T> *root, T target) {
    if (!root)
        return nullptr;
    root->left = remove_leaf_nodes(root->left, target);
    root->right = remove_leaf_nodes(root->right, target);
    if (root->left == nullptr && root->right == nullptr && root->value == target) {
        delete root;
        return nullptr;
    }
    return root;
}


#endif //DATA_STRUCTURES_REMOVE_LEAFE_NODES_WITH_TARGET_VALUE_H
