//
// Created by andreas on 19.01.26.
//

#ifndef ALGORITHMS_HEIGHT_BALANCED_BINARY_TREE_H
#define ALGORITHMS_HEIGHT_BALANCED_BINARY_TREE_H
// You're given the root node of a Binary Tree.Write a function that returns `true` if this Binary Tree is
// height balanced and `false` if it isn't.
// A Binary Tree is height balanced if for each node in the tree, the difference between the height of its.
// left subtree and the height of its right subtree is at most 1.

#include "tree_node.h"

template <typename T>
int balanced_height(TreeNode<T>* node)
{
    if(!node)
        return 0;
    const int left_height = balanced_height(node->left);
    if(left_height == -1)
        return -1;
    const int right_height = balanced_height(node->right);

    if (std::abs(left_height - right_height) > 1)
        return -1;
    return 1 + std::max(left_height, right_height);
}


template <typename T>
bool height_balanced_binary_tree(TreeNode<T>* root)
{
    return balanced_height(root) != -1;
}

#endif //ALGORITHMS_HEIGHT_BALANCED_BINARY_TREE_H