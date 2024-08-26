//
// Created by andreas on 26.08.24.
//

#ifndef DATA_STRUCTURES_POSTORDER_TRAVERSAL_H
#define DATA_STRUCTURES_POSTORDER_TRAVERSAL_H

#include "tree_node.h"
#include <stack>

template<typename T>
void postorder_traversal(TreeNode<T> *node, std::vector<T> &result) {
    if (!node)
        return;
    for (const auto &child: node->children) {
        postorder_traversal(child, result);
    }
    result.push_back(node->value);
}


template<typename T>
std::vector<T> postorder_traversal_recursive(TreeNode<T> *root) {
    if (!root) {
        return {};
    }
    std::vector<T> result;
    postorder_traversal(root, result);
    return result;
}

#endif //DATA_STRUCTURES_POSTORDER_TRAVERSAL_H
