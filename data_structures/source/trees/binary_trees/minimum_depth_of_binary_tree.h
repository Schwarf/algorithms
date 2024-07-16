//
// Created by andreas on 10.07.23.
//

#ifndef MINIMUM_DEPTH_OF_BINARY_TREE_H
#define MINIMUM_DEPTH_OF_BINARY_TREE_H

#include "tree_node.h"
#include <queue>

template<typename T>
int minimum_depth_binary_tree_dfs(TreeNode<T> *root) {
    if (!root)
        return 0;
    if (root->left && root->right)
        return 1 + std::min(minimum_depth_binary_tree_dfs(root->left), minimum_depth_binary_tree_dfs(root->right));
    if (root->left)
        return 1 + minimum_depth_binary_tree_dfs(root->left);
    if (root->right)
        return 1 + minimum_depth_binary_tree_dfs(root->right);
    return 1;
}

template<typename T>
int minimum_depth_binary_tree_bfs(TreeNode<T> *root) {
    if (!root)
        return 0;
    std::queue<TreeNode<T> *> q;
    q.push(root);
    int depth{};
    while (!q.empty()) {
        auto size = q.size();
        depth++;
        while (size--) {
            auto node = q.front();
            q.pop();
            if (!node->left && !node->right)
                return depth;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return depth;
}


#endif //MINIMUM_DEPTH_OF_BINARY_TREE_H
