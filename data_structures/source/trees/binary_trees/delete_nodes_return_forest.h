//
// Created by andreas on 01.06.24.
//

#ifndef DATA_STRUCTURES_DELETE_NODES_RETURN_FOREST_H
#define DATA_STRUCTURES_DELETE_NODES_RETURN_FOREST_H
// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest.  You may return the result in any order.

#include "tree_node.h"
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>

template<typename T>
TreeNode<T> *
dfs(TreeNode<T> *&node, const std::unordered_set<T> &&to_delete_values, bool is_root_node,
    std::vector<TreeNode<T> *> &result) {
    if (!node) {
        return node;
    }

    const auto will_node_be_deleted = to_delete_values.contains(node->value);
    // if the current node is a root node an will not be deleted we store it.
    if (is_root_node && !will_node_be_deleted)
        result.push_back(node);

    // Check the children
    node->left = dfs(node->left, std::move(to_delete_values), will_node_be_deleted, result);
    node->right = dfs(node->right, std::move(to_delete_values), will_node_be_deleted, result);

    // Delete the current node
    if (will_node_be_deleted) {
        delete node;
        return nullptr;
    }
    return node;
}

template<typename T>
std::vector<TreeNode<T> *> delete_nodes_return_forest(TreeNode<T> *root, const std::vector<T> &values_to_delete) {
    std::vector<TreeNode<T> *> result;
    dfs(root, {values_to_delete.begin(), values_to_delete.end()}, true, result);
    return result;
}


template<typename T>
std::vector<TreeNode<T> *>
delete_nodes_return_forest_bfs(TreeNode<T> *root, const std::vector<T> &values_to_delete) {
    if (!root) return {};

    std::unordered_set<T> to_delete(values_to_delete.begin(), values_to_delete.end());
    std::queue<TreeNode<T> *> q;
    std::vector<TreeNode<T> *> roots;

    // Push the root node with a pointer to a nullptr parent
    q.push(root);

    // Handle the root node separately to correctly add it to root_nodes if it should not be deleted
    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        if (current->left) {
            q.push(current->left);
            if (to_delete.find(current->left->value) != to_delete.end())
                current->left = nullptr;
        }
        if (current->right) {
            q.push(current->right);
            if (to_delete.find(current->right->value) != to_delete.end())
                current->right = nullptr;
        }

        if (to_delete.find(current->value) != to_delete.end()) {
            if (current->left)
                roots.push_back(current->left);
            if (current->right)
                roots.push_back(current->right);
        }
    }
    if (to_delete.find(root->value) == to_delete.end())
        roots.push_back(root);
    return roots;
}

template<typename T>
std::vector<TreeNode<T> *>
delete_nodes_return_forest_bfs_with_correct_deletion(TreeNode<T> *root, const std::vector<T> &values_to_delete) {
    if (!root) return {};

    std::unordered_set<T> to_delete(values_to_delete.begin(), values_to_delete.end());
    std::queue<TreeNode<T> *> q;
    std::vector<TreeNode<T> *> roots;

    // Check if the root node is marked for deletion
    if (to_delete.find(root->value) == to_delete.end()) {
        roots.push_back(root); // root is not to be deleted, add as a root of a new tree
    }
    q.push(root);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        // Process the left child
        if (current->left) {
            if (to_delete.find(current->left->value) != to_delete.end()) {
                // If left child is to be deleted
                if (current->left->left) {
                    q.push(current->left->left);
                    if (to_delete.find(current->left->left->value) == to_delete.end()) {
                        roots.push_back(current->left->left); // Add as new root if not marked for deletion
                    }
                }
                if (current->left->right) {
                    q.push(current->left->right);
                    if (to_delete.find(current->left->right->value) == to_delete.end()) {
                        roots.push_back(current->left->right); // Add as new root if not marked for deletion
                    }
                }
                delete current->left; // Delete the node
                current->left = nullptr;
            } else {
                q.push(current->left);
                if (to_delete.find(current->value) != to_delete.end()) {
                    roots.push_back(current->left); // Current is deleted, so child becomes a new root
                }
            }
        }

        // Process the right child
        if (current->right) {
            if (to_delete.find(current->right->value) != to_delete.end()) {
                // If right child is to be deleted
                if (current->right->left) {
                    q.push(current->right->left);
                    if (to_delete.find(current->right->left->value) == to_delete.end()) {
                        roots.push_back(current->right->left); // Add as new root if not marked for deletion
                    }
                }
                if (current->right->right) {
                    q.push(current->right->right);
                    if (to_delete.find(current->right->right->value) == to_delete.end()) {
                        roots.push_back(current->right->right); // Add as new root if not marked for deletion
                    }
                }
                delete current->right; // Delete the node
                current->right = nullptr;
            } else {
                q.push(current->right);
                if (to_delete.find(current->value) != to_delete.end()) {
                    roots.push_back(current->right); // Current is deleted, so child becomes a new root
                }
            }
        }

        // Check and delete the current node if necessary (except root which is handled initially)
        if (to_delete.find(current->value) != to_delete.end() && current != root) {
            delete current;
        }
    }
    return roots;
}


#endif //DATA_STRUCTURES_DELETE_NODES_RETURN_FOREST_H
