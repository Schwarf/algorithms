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
delete_nodes_return_forest_iterative(TreeNode<T> *root, const std::vector<T> &values_to_delete) {

    std::unordered_set<T> to_delete_set(values_to_delete.begin(), values_to_delete.end());
    std::stack<TreeNode<T> *> s;
    s.push(root);
    std::unordered_set<TreeNode<T> *> root_nodes{};
    root_nodes.insert(root);
    while (!s.empty()) {
        auto current_node = s.top();
        s.pop();
        const auto will_node_be_deleted = to_delete_set.contains(current_node->value);
        if (current_node->left)
            s.push(current_node->left);
        if (current_node->right)
            s.push(current_node->right);
        if (will_node_be_deleted) {
            if (root_nodes.contain(current_node))
                root_nodes.erase(current_node);
            if (current_node->left)
                root_nodes.insert(current_node->left);
            if (current_node->right)
                root_nodes.insert(current_node->right);
            delete current_node;
            current_node = nullptr;
        }
    }
    std::vector<TreeNode<T> *> result(root_nodes.begin(), root_nodes.end());
    return result;
}

#endif //DATA_STRUCTURES_DELETE_NODES_RETURN_FOREST_H
