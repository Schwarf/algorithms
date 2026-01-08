//
// Created by andreas on 08.01.26.
//

#ifndef ALGORITHMS_TEST_HELPER_H
#define ALGORITHMS_TEST_HELPER_H
#include "./../../trees/binary_trees/tree_node.h"

template <typename T>
static void delete_tree(TreeNode<T>* root) {
    if (!root)
        return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

template <typename T>
bool is_valid_binary_search_tree(TreeNode<T>* root, TreeNode<T>* min = nullptr, TreeNode<T>* max = nullptr)
{
    if (!root)
        return true;
    if (min != nullptr && root->value < min->value) return false;
    if (max != nullptr && root->value >= max->value) return false;
    return is_valid_binary_search_tree(root->left, min, root) && is_valid_binary_search_tree(root->right, root, max);
}
#endif //ALGORITHMS_TEST_HELPER_H