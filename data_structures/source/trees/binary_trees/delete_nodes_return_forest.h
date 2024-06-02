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
#include <unordered_set>

template<typename T>
TreeNode<T> *
dfs(TreeNode<T> *&node, const std::unordered_set<T> &&to_delete_values, bool is_root_node,
    std::vector<TreeNode<T> *> &result) {
    if (!node) {
        return node;
    }

    const auto will_root_be_deleted = to_delete_values.contains(node->value);
    // if the current node is a root node an will not be deleted we store it.
    if (is_root_node && !will_root_be_deleted)
        result.push_back(node);

    // Check the children
    node->left = dfs(node->left, std::move(to_delete_values), will_root_be_deleted, result);
    node->right = dfs(node->right, std::move(to_delete_values), will_root_be_deleted, result);
    return will_root_be_deleted ? nullptr : node;

}

template<typename T>
std::vector<TreeNode<T> *> delete_nodes_return_forest(TreeNode<T> *root, std::vector<T> &values_to_delete) {
    std::vector<TreeNode<T> *> result;
    dfs(root, {values_to_delete.begin(), values_to_delete.end()}, true, result);
    return result;
}


#endif //DATA_STRUCTURES_DELETE_NODES_RETURN_FOREST_H
