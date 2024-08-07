//
// Created by andreas on 30.04.22.
//

#ifndef INVERT_BINARY_TREE_H
#define INVERT_BINARY_TREE_H

#include "tree_node.h"

template<typename T>
TreeNode<T> *invert_binary_tree(TreeNode<T> *root) {
    if (!root)
        return nullptr;
    auto left = root->left;
    auto right = root->right;
    root->left = invert_binary_tree(right);
    root->right = invert_binary_tree(left);
    return root;
}

#endif //INVERT_BINARY_TREE_H
