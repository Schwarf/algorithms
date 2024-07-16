//
// Created by andreas on 09.05.22.
//

#ifndef PRE_ORDER_TRAVERSAL_H
#define PRE_ORDER_TRAVERSAL_H

#include "tree_node.h"
#include <vector>
#include <stack>

// For Preorder, you traverse from the root to the left subtree then to the right subtree.
// Preorder => Root, Left, Right aka parents get processed before children
template<typename T>
std::vector<T> pre_order_traversal(TreeNode<T> *root) {
    if (!root)
        return {};
    std::vector<T> result;
    std::stack<TreeNode<T> *> remember_nodes;
    remember_nodes.push(root);
    while (!remember_nodes.empty()) {
        auto current_node = remember_nodes.top();
        remember_nodes.pop();
        if (current_node != nullptr) {
            result.push_back(current_node->value);
            remember_nodes.push(current_node->right);
            remember_nodes.push(current_node->left);
        }
    }
    return result;
}

template<typename T>
void pre_order_traversal(std::vector<T> &result, TreeNode<T> *root) {
    if (!root)
        return;
    result.push_back(root->value);
    pre_order_traversal(result, root->left);
    pre_order_traversal(result, root->right);
}

template<typename T>
std::vector<T> pre_order_traversal_recursive(TreeNode<T> *root) {
    std::vector<T> answer;
    pre_order_traversal(answer, root);
    return answer;
}


#endif //PRE_ORDER_TRAVERSAL_H
