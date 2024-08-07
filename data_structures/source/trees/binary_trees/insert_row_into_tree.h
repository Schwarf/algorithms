//
// Created by andreas on 16.04.24.
//

#ifndef DATA_STRUCTURES_INSERT_ROW_INTO_TREE_H
#define DATA_STRUCTURES_INSERT_ROW_INTO_TREE_H

#include "tree_node.h"
#include <queue>
// Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the
// given depth depth. Note that the root node is at depth 1.
// The adding rule is:
// Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value
// val as cur's left subtree root and right subtree root.
// cur's original left subtree should be the left subtree of the new left subtree root.
// cur's original right subtree should be the right subtree of the new right subtree root.
// If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new
// root of the whole original tree, and the original tree is the new root's left subtree.

template<typename T>
TreeNode<T> *insert_row_into_tree(TreeNode<T> *root, T value, int depth) {
    if (depth == 1) {
        auto new_root = new TreeNode<T>(value);
        new_root->left = root;
        return new_root;
    }

    std::queue<TreeNode<T> *> q;
    q.push(root);
    int current_depth{};
    while (!q.empty()) {
        current_depth++;

        for (int i = q.size(); i > 0; --i) {
            auto node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            if (current_depth == depth - 1) {
                auto left_sub_tree = node->left;
                auto right_sub_tree = node->right;
                node->left = new TreeNode<T>(value);
                node->left->left = left_sub_tree;
                node->right = new TreeNode<T>(value);
                node->right->right = right_sub_tree;
            }
        }
        if (current_depth == depth - 1)
            break;
    }
    return root;
}


#endif //DATA_STRUCTURES_INSERT_ROW_INTO_TREE_H
