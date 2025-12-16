//
// Created by andreas on 03.08.22.
//

#ifndef BINARY_SEARCH_TREE_FROM_SORTED_ARRAY_H
#define BINARY_SEARCH_TREE_FROM_SORTED_ARRAY_H

#include "../trees/binary_trees/tree_node.h"
#include <vector>

template<typename T>
TreeNode<T> *build_tree(std::vector<int> &array, int left, int right) {
    if (left > right)
        return nullptr;
    int mid = (right + left) / 2;
    auto root = new TreeNode<T>(array[mid]);
    root->left = build_tree<T>(array, left, mid - 1);
    root->right = build_tree<T>(array, mid + 1, right);
    return root;
}

template<typename T>
TreeNode<T> *binary_search_tree_from_sorted_array(std::vector<int> &array) {
    return build_tree<T>(array, 0, array.size() - 1);
}

#endif //BINARY_SEARCH_TREE_FROM_SORTED_ARRAY_H
