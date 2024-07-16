//
// Created by andreas on 28.02.24.
//

#ifndef DIAMETER_OF_BINARY_TREE_H
#define DIAMETER_OF_BINARY_TREE_H

#include "tree_node.h"
#include <queue>
//Given the root of a binary tree, return the length of the diameter of the tree.
//The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
//The length of a path between two nodes is represented by the number of edges between them.

template<typename T>
int bfs_help(TreeNode<T> *node) {
    std::queue<TreeNode<T> *> q;
    q.push(node);
    int length{-1};
    while (!q.empty()) {
        int q_size = q.size();
        for (int i{}; i < q_size; ++i) {
            auto current = q.front();
            q.pop();
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        length++;
    }
    return length;
}

// using breadth first search
template<typename T>
int diameter_of_tree(TreeNode<T> *root) {
    int max{};
    if (root->left && root->right)
        max = std::max(max, 2 + bfs_help(root->right) + bfs_help(root->left));
    else
        max = std::max(max, bfs_help(root));
    if (root->right)
        max = std::max(max, diameter_of_tree(root->right));
    if (root->left)
        max = std::max(max, diameter_of_tree(root->left));
    return max;
}

template<typename T>
int diameter(TreeNode<T> *node, int &result) {
    // Base case: if the current node is null, return 0
    if (!node)
        return 0;

    // Recursively calculate the diameter of left and right subtrees
    int left = diameter(node->left, result);
    int right = diameter(node->right, result);

    // Update the maximum diameter encountered so far
    result = std::max(result, left + right);

    // Return the depth of the current node
    return std::max(left, right) + T{1};
}

template<typename T>
int diameter_of_tree_optimal(TreeNode<T> *root) {
    int result{};
    diameter(root, result);
    return result;
}


#endif //DIAMETER_OF_BINARY_TREE_H
