//
// Created by andreas on 29.02.24.
//

#ifndef IS_TREE_EVEN_ODD_TREE_H
#define IS_TREE_EVEN_ODD_TREE_H
// Condider this definition of an even-odd binary tree
// The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
// For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
// For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
// Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.
#include "tree_node.h"
#include <queue>

template<typename T>
bool is_even_odd_tree(TreeNode<T> *root) {
    std::queue<TreeNode<T> *> q;

    q.push(root);
    int level{-1};
    while (!q.empty()) {
        level++;
        int q_size = q.size();
        int last = (level & 1) ? 20000000 : 0;
        for (int i{}; i < q_size; ++i) {
            auto node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            if (!(level & 1)) {
                if (last >= node->value)
                    return false;
                if (!(node->value & 1))
                    return false;

            }
            if ((level & 1)) {
                if (last <= node->value)
                    return false;
                if ((node->value & 1))
                    return false;
            }

            last = node->value;
        }
    }
    return true;
}

#endif //IS_TREE_EVEN_ODD_TREE_H

