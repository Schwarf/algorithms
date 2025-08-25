//
// Created by andreas on 14.07.22.
//

#ifndef CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_H
#define CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_H

#include <vector>
#include <unordered_map>
#include "tree_node.h"


template <typename T>
TreeNode<T>* construct_tree_post_in(std::vector<T>& postorder,
                                    int left_in_order_index,
                                    int right_in_order_index,
                                    int& post_order_index,
                                    std::unordered_map<T, int>& inorder_value_to_index)
{
    if (left_in_order_index > right_in_order_index)
        return nullptr;
    int root_value = postorder[post_order_index--];
    auto root = new TreeNode<T>(root_value);
    auto pivot = inorder_value_to_index[root_value];
    root->right = construct_tree_post_in(postorder,
                                         pivot + 1,
                                         right_in_order_index,
                                         post_order_index,
                                         inorder_value_to_index);
    root->left = construct_tree_post_in(postorder,
                                        left_in_order_index,
                                        pivot - 1,
                                        post_order_index,
                                        inorder_value_to_index);
    return root;
}

template <typename T>
TreeNode<T>* construct_from_inorder_and_postorder(std::vector<T>& in_order, std::vector<T>& post_order)
{
    if (in_order.size() != post_order.size() || in_order.empty())
        return nullptr;
    std::unordered_map<T, int> inorder_value_to_index;
    int post_order_index = in_order.size() - 1;
    for (int i = 0; i < in_order.size(); ++i)
        inorder_value_to_index[in_order[i]] = i;

    return construct_tree_post_in(post_order, 0, post_order.size() - 1, post_order_index, inorder_value_to_index);
}

#endif //CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_H
