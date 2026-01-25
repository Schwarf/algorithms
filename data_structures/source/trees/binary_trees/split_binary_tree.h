//
// Created by andreas on 25.01.26.
//

#ifndef ALGORITHMS_SPLIT_BINARY_TREE_H
#define ALGORITHMS_SPLIT_BINARY_TREE_H
// You’re given the root of a binary tree. You may remove exactly one edge (i.e., cut the connection between a parent and one of its children). This would split the tree into two separate trees.
// Return the sum of the values in each of the two resulting trees if there exists a cut such that the two sums are equal.
// If no such cut exists, return 0.
#include "tree_node.h"

template <typename T>
T get_tree_sum(TreeNode<T>* node)
{
    if (!node)
        return T{};
    return node->value + get_tree_sum(node->left) + get_tree_sum(node->right);
}

template <typename T>
T subtree_sum_and_find(TreeNode<T>* node, T wanted, bool &found)
{
    if (!node)
        return 0;
    int left_sum = subtree_sum_and_find(node->left, wanted, found);
    int right_sum = subtree_sum_and_find(node->right, wanted, found);
    if (node->left && left_sum == wanted)
        found = true;
    if (node->right && right_sum == wanted)
        found = true;
    return node->value + left_sum + right_sum;
}

template <typename T>
bool try_subtree(TreeNode<T>* node, T wanted)
{
    bool found = false;
    subtree_sum_and_find(node, wanted,found);
    return found;
}

template <typename T>
requires std::is_integral_v<T>
T split_binary_tree(TreeNode<T>* root)
{
    T sum = get_tree_sum(root);
    if (sum & 1)
        return 0; // Odd number -> no split possible
    T wanted = sum/2;
    return try_subtree(root, wanted) ? wanted : 0;
}


template <typename T>
T dfs(TreeNode<T>* node, T target, bool&found, bool is_root)
{
    if (!node)
        return T{};
    auto left_sum = dfs(node->left, target, found, false);
    auto right_sum = dfs(node->right, target, found, false);
    auto sum = node->value + left_sum + right_sum;

    if (!is_root && sum == target)
        found = true;
    return sum;
}

template <typename T>
requires std::is_integral_v<T>
T split_binary_tree2(TreeNode<T>* root)
{
    T sum = get_tree_sum(root);
    if (sum & 1)
        return 0; // Odd number -> no split possible
    T wanted = sum/2;
    return try_subtree(root, wanted) ? wanted : 0;
}


#endif //ALGORITHMS_SPLIT_BINARY_TREE_H