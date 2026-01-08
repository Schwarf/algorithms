//
// Created by andreas on 08.01.26.
//

#ifndef ALGORITHMS_CONSTRUCT_BINARY_SEARCH_TREE_FROM_PRE_ORDER_H
#define ALGORITHMS_CONSTRUCT_BINARY_SEARCH_TREE_FROM_PRE_ORDER_H

#include <limits>

#include "../trees/binary_trees/tree_node.h"
#include <vector>


template <typename T>
TreeNode<T> * helper(const std::vector<T> &pre_order, int & index, T lower, T upper)
{
    if(index >= pre_order.size() || pre_order[index] < lower || pre_order[index] >= upper)
        return nullptr;

    auto node = new TreeNode<T>(pre_order[index++]);
    node->left = helper(pre_order, index, lower, node->value);
    node->right = helper(pre_order, index, node->value, upper);
    return node;
}

template <typename T>
requires std::is_arithmetic_v<T>
TreeNode<T>* construct_from_pre_order(const std::vector<T> &pre_order)
{
    T upper = std::numeric_limits<T>::max();
    T lower = std::numeric_limits<T>::min();
    int index{};
    auto root = helper(pre_order, index, lower, upper);
    return root;
}


#endif //ALGORITHMS_CONSTRUCT_BINARY_SEARCH_TREE_FROM_PRE_ORDER_H