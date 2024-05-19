//
// Created by andreas on 19.05.24.
//

#ifndef DATA_STRUCTURES_REMOVE_LEAF_NODES_WITH_TARGET_VALUE_H
#define DATA_STRUCTURES_REMOVE_LEAF_NODES_WITH_TARGET_VALUE_H
// Given a binary tree root and an integer target, delete all the leaf nodes with value target.
// Note that once you delete a leaf node with value target,
// if its parent node becomes a leaf node and has the value target, it should also be deleted
// (you need to continue doing that until you cannot).
#include "tree_node.h"
#include <stack>

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

template<typename T>
TreeNode<T> *remove_leaf_nodes_iterative(TreeNode<T> *root, T target) {
    std::stack<TreeNode<T> *> s;
    auto current = root;
    TreeNode<T> *last_right_node = nullptr;
    while (!s.empty() || current) {
        // get down on the left of the tree
        while (current) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        // Check if current node has unexplored right subtree
        // If so go down right unless it's a subtree we just visited
        if (current->right != last_right_node && current->right) {
            current = current->right;
            continue;
        }

        s.pop();
        if (!current->right && !current->left && current->value == target) {
            // root node contains target
            if (s.empty()) {
                delete root;
                return nullptr;
            }
            // get parent of current node
            auto parent = s.top();
            if (parent->left == current)
                parent->left = nullptr;
            else
                parent->right = nullptr;

        } else {
            // mark current node as visited by setting last_right_node to current for next iteration
            last_right_node = current;
        }
        // reset current node to process next node from the stack
        current = nullptr;
    }
    return root;
}


#endif //DATA_STRUCTURES_REMOVE_LEAF_NODES_WITH_TARGET_VALUE_H
