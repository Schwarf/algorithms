//
// Created by andreas on 16.07.24.
//

#ifndef DATA_STRUCTURES_LOWEST_COMMON_ANCESTOR_H
#define DATA_STRUCTURES_LOWEST_COMMON_ANCESTOR_H

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
// p and q as the lowest node in T that has both p and q as descendants
// (where we allow a node to be a descendant of itself)."

#include "tree_node.h"
#include <unordered_set>
#include <stack>


template<typename T>
TreeNode<T> *lowest_common_ancestor(TreeNode<T> *root, T value1, T value2, bool &found1, bool &found2) {
    if (!root)
        return nullptr;
    if (root->value == value1) {
        found1 = true;
        return root;
    }
    if (root->value == value2) {
        found2 = true;
        return root;
    }

    auto left_lca = lowest_common_ancestor(root->left, value1, value2, found1, found2);
    auto right_lca = lowest_common_ancestor(root->right, value1, value2, found1, found2);

    if (!left_lca)
        return right_lca;
    if (!right_lca)
        return left_lca;

    return root;
}

template<typename T>
TreeNode<T> *find_node(TreeNode<T> *root, T value) {
    if (!root) return nullptr;
    if (root->value == value) return root;

    TreeNode<T> *leftResult = find_node(root->left, value);
    if (leftResult) return leftResult;

    return find_node(root->right, value);
}

// Wrapper function to handle the case where only one value is found.
// Then we return nullptr;
template<typename T>
TreeNode<T> *find_lowest_common_ancestor(TreeNode<T> *root, T value1, T value2) {
    bool found1{};
    bool found2{};
    auto node = lowest_common_ancestor(root, value1, value2, found1, found2);
    if (found1 && found2)
        return node;

    // Ensure if only one value is found, it returns the correct node
    if (found1 && find_node(node, value2))
        return node;

    if (found2 && find_node(node, value1))
        return node;

    return nullptr;
}

template<typename T>
TreeNode<T> *find_lowest_common_ancestor_iterative(TreeNode<T> *root, T value1, T value2) {

    if (!root) return nullptr;

    TreeNode<T> *node1 = find_node(root, value1);
    TreeNode<T> *node2 = find_node(root, value2);
    // If either value is not found we return nullptr
    if (!node1 || !node2)
        return nullptr;

    // Map to store parent pointers of each node
    std::unordered_map<TreeNode<T> *, TreeNode<T> *> parent;
    parent[root] = nullptr;

    std::stack<TreeNode<T> *> stack;
    stack.push(root);

    // Traverse the tree until both nodes are found
    while (!stack.empty() && (parent.find(node1) == parent.end() || parent.find(node2) == parent.end())) {
        TreeNode<T> *node = stack.top();
        stack.pop();

        if (node->left) {
            parent[node->left] = node;
            stack.push(node->left);
        }

        if (node->right) {
            parent[node->right] = node;
            stack.push(node->right);
        }
    }

    // Create a set of ancestors for node node1
    std::unordered_set<TreeNode<T> *> ancestors;
    while (node1) {
        ancestors.insert(node1);
        node1 = parent[node1];
    }

    // Traverse the ancestors of node2 until a common ancestor is found
    while (ancestors.find(node2) == ancestors.end()) {
        node2 = parent[node2];
    }

    return node2;
}


#endif //DATA_STRUCTURES_LOWEST_COMMON_ANCESTOR_H
