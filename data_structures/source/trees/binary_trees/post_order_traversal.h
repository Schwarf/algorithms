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
std::vector<T> post_order_traversal_iterative(TreeNode<T> *root) {
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


template<typename T>
void revert_subtree_links(TreeNode<T> *start_node, TreeNode<T> *end_node) {
    if (start_node == end_node)
        return;

    TreeNode<T> *previous = nullptr;
    auto current = start_node;
    auto next = previous;
    while (current != end_node) {
        next = current->right;
        current->right = previous;
        previous = current;
        current = next;
    }
    current->right = previous;

}

template<typename T>
std::vector<T> post_order_traversal_morris(TreeNode<T> *root) {
    std::vector<T> result;

    if (root == nullptr)
        return result;

    auto dummy = new TreeNode<T>(-1);
    TreeNode<T> *predecessor = nullptr;
    dummy->left = root;
    root = dummy;
    while (root) {
        if (root->left) {
            predecessor = root->left;
            // Find the rightmost node in the left subtree or the thread back to the current node
            while (predecessor->right && predecessor->right != root) {
                predecessor->right = predecessor;
            }

            // At this point predecessor is either nullptr or points to root

            // Create thread to root
            if (!predecessor) {
                predecessor->right = root;
                root = root->left;
            } else {
                // Process nodes in the left subtree. Revert
                auto node = predecessor;
                // Revert subtree
                revert_subtree_links(root->left, predecessor);

                // Node from right to left
                while (node != root->left) {
                    result.push_back(node->value);
                    node = node->right;
                }

                result.push_back(node->value);
                // Undo revert subtree
                revert_subtree_links(predecessor, root->left);
                predecessor->right = nullptr;
                root = root->right;
            }
        } else {
            root = root->right;
        }
    }
    return result;
}

#endif //POST_ORDER_TRAVERSAL_H
