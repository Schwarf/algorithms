//
// Created by andreas on 20.01.26.
//

#ifndef ALGORITHMS_MERGE_BINARY_TREES_H
#define ALGORITHMS_MERGE_BINARY_TREES_H
// Given two binary trees as input write a function that merges them and returns the merged tree.
// If two nodes overlap the merged node shall represent the sum of the overlapping nodes` values.

#include "tree_node.h"

template<typename T>
TreeNode<T>* merge_binary_tees(TreeNode<T>* root1, TreeNode<T>* root2) {
    if (!root1 && !root2)
        return nullptr;

    int value = (root1 ? root1->value : 0) + (root2 ? root2->value : 0);
    auto* result = new TreeNode<T>(value);

    result->left  = merge_binary_trees(root1 ? root1->left  : nullptr, root2 ? root2->left  : nullptr);
    result->right = merge_binary_trees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
    return result;
}
#endif //ALGORITHMS_MERGE_BINARY_TREES_H