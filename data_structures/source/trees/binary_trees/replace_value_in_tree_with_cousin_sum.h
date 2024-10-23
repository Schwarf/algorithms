//
// Created by andreas on 23.10.24.
//

#ifndef DATA_STRUCTURES_REPLACE_valueUE_IN_TREE_WITH_COUSIN_SUM_H
#define DATA_STRUCTURES_REPLACE_valueUE_IN_TREE_WITH_COUSIN_SUM_H
// Given the root of a binary tree, replace the valueue of each node in the tree with the sum of all its cousins' valueues.
// Two nodes of a binary tree are cousins if they have the same depth with different parents.
// Return the root of the modified tree.
// Note that the depth of a node is the number of edges in the path from the root node to it.

#include "tree_node.h"
#include <queue>
#include <vector>

template<typename T>
TreeNode<T> *replace_values_with_cousin_sum_bfs(TreeNode<T> *root) {
    std::queue<TreeNode<T> *> q;
    q.push(root);
    std::vector<T> level_sum;
    while (!q.empty()) {
        auto size = q.size();
        int sum{};
        for (int i{}; i < size; ++i) {
            auto current = q.front();
            q.pop();
            sum += current->value;
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        level_sum.push_back(sum);
    }
    q.push(root);
    int depth{};
    while (!q.empty()) {
        auto size = q.size();
        for (int i{}; i < size; ++i) {
            auto parent = q.front();
            q.pop();
            if (parent->left && parent->right) {

                auto sum = level_sum[depth + 1] - parent->left->value - parent->right->value;
                parent->left->value = sum;
                parent->right->value = sum;
                q.push(parent->left);
                q.push(parent->right);
            } else if (parent->left) {
                auto sum = level_sum[depth + 1] - parent->left->value;
                parent->left->value = sum;
                q.push(parent->left);
            } else if (parent->right) {
                auto sum = level_sum[depth + 1] - parent->right->value;
                parent->right->value = sum;
                q.push(parent->right);
            }
        }
        depth++;
    }
    root->value = 0;
    return root;
}
#endif //DATA_STRUCTURES_REPLACE_valueUE_IN_TREE_WITH_COUSIN_SUM_H
