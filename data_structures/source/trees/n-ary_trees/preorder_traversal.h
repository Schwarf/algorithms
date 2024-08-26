//
// Created by andreas on 26.08.24.
//

#ifndef DATA_STRUCTURES_PREORDER_TRAVERSAL_H
#define DATA_STRUCTURES_PREORDER_TRAVERSAL_H

#include "tree_node.h"
#include <stack>

template<typename T>
void preorder_traversal(TreeNode<T> *node, std::vector<T> &result) {
    if (!node)
        return;
    result.push_back(node->value);
    for (const auto &child: node->children)
        preorder_traversal(child, result);

}

template<typename T>
std::vector<T> preorder_traversal_recursive(TreeNode<T> *root) {
    if (!root)
        return {};
    std::vector<T> result;
    preorder_traversal(root, result);
    return result;
}

template<typename T>
std::vector<T> preorder_traversal_iterative(TreeNode<T> *root) {
    if (!root)
        return {};
    std::vector<T> result;
    std::stack<TreeNode<T> *> stack;
    stack.push(root);
    while (!stack.empty()) {
        auto node = stack.top();
        stack.pop();
        result.push_back(node->value);
        for (auto it = node->children.rbegin(); it != node->children.rend(); it++) {
            stack.push(*it);
        }
    }
    return result;
}


#endif //DATA_STRUCTURES_PREORDER_TRAVERSAL_H
