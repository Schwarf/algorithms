//
// Created by andreas on 09.05.22.
//

#ifndef POST_ORDER_TRAVERSAL_H
#define POST_ORDER_TRAVERSAL_H

#include "tree_node.h"
#include <vector>
#include <stack>
#include <algorithm>

// For Post order, you traverse from the left subtree to the right subtree then to the root.
// Postorder => Left, Right, Root aka children get processed before parents
template<typename T>
std::vector<T> post_order_traversal(TreeNode<T> *root) {
    if (!root)
        return {};
    auto result = std::vector<T>();
    auto remember = std::stack<TreeNode<T> *>();
    remember.push(root);
    while (!remember.empty()) {
        root = remember.top();
        remember.pop();
        result.push_back(root->value);
        if (root->left)
            remember.push(root->left);
        if (root->right)
            remember.push(root->right);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

template<typename T>
void post_order_traversal(std::vector<T> &result, TreeNode<T> *root) {
    if (!root)
        return;
    post_order_traversal(result, root->left);
    post_order_traversal(result, root->right);
    result.push_back(root->value);
}

template<typename T>
std::vector<T> post_order_traversal_recursive(TreeNode<T> *root) {
    std::vector<T> result;
    post_order_traversal(result, root);
    return result;
}

#endif //POST_ORDER_TRAVERSAL_H
