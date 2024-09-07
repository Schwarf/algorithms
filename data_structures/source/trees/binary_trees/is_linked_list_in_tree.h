//
// Created by andreas on 07.09.24.
//

#ifndef DATA_STRUCTURES_IS_LINKED_LIST_IN_TREE_H
#define DATA_STRUCTURES_IS_LINKED_LIST_IN_TREE_H
// Given a binary tree root and a linked list with head as the first node.
// Return True if all the elements in the linked list starting from the head correspond to some downward path
// connected in the binary tree otherwise return False.
// In this context downward path means a path that starts at some node and goes downwards.
#include "tree_node.h"
#include "./../../linked_lists/node.h"
#include <queue>

template<typename T>
bool is_in_tree(Node<T> *head, TreeNode<T> *node) {
    if (!head)
        return true;
    if (!node)
        return false;
    bool left{};
    bool right{};
    if (head->value == node->value) {
        left = is_in_tree(head->next, node->left);
        right = is_in_tree(head->next, node->right);
    }
    return left || right;
}


template<typename T>
bool is_linked_list_in_tree(Node<T> *head, TreeNode<T> *root) {
    if (!head)
        return true;
    if (!root)
        return false;
    std::queue<TreeNode<T> *> q;
    q.emplace(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (is_in_tree(head, node))
            return true;
        if (node->left)
            q.emplace(node->left);
        if (node->right)
            q.emplace(node->right);
    }
    return false;
}

#endif //DATA_STRUCTURES_IS_LINKED_LIST_IN_TREE_H
