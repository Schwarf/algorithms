//
// Created by andreas on 07.09.26.
//

#ifndef ALGORITHMS_FIND_SUCCESSOR_H
#define ALGORITHMS_FIND_SUCCESSOR_H
#include "tree_node.h"

// Given a node in a binary tree where each node has a pointer to its parent,
// find the node's successor in an in-order traversal.

template <typename T>
ParentedTreeNode<T>* inorder_find_successor(ParentedTreeNode<T>* root, ParentedTreeNode<T>* node)
{
    (void)root;

    if (!node)
        return nullptr;

    // Only two cases:
    // 1. If the node has a right child. Walk down the left tree.
    // 2. If the node has no right child, walk up the tree until the current node is the left child of its parent.
    // The root node is not needed ... its a ruse.
    // Case 1.:
    if (node->right)
    {
        auto current = node->right;
        while (current->left)
            current = current->left;
        return current;
    }

    // Case 2.:
    auto current = node;
    while (current->parent && current == current->parent->right)
        current = current->parent;
    return current->parent;
}


template <typename T>
ParentedTreeNode<T>* preorder_find_successor(ParentedTreeNode<T>* root, ParentedTreeNode<T>* node)
{
    (void)root;

    if (!node)
        return nullptr;

    // Only two cases:
    // 1. If the node has a left child, the successor is this child.
    // 2. If has no left child but has a right child it is the right child.
    // 3. climb until we find an ancestor whose right subtree has not yet been visited.
    // Case 1.:
    if (node->left)
    {
        return node->left;
    }
    // Case 2.:
    if (node->right)
    {
        return node->right;
    }

    // Case 3.:
    auto current = node;
    while (current->parent)
    {
        if (current == current->parent->left && current->parent->right)
            return current->parent->right;
        current = current->parent;
    }
    return nullptr;
}

#endif // ALGORITHMS_FIND_SUCCESSOR_H
