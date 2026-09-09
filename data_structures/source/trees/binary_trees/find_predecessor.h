//
// Created by andreas on 09.09.26.
//

#ifndef ALGORITHMS_FIND_PREDECESSOR_H
#define ALGORITHMS_FIND_PREDECESSOR_H

// Given a node in a binary tree where each node has a pointer to its parent,
// find the node's predecessor in an in-order, pre-order and post-order traversal.
#include "tree_node.h"

template <typename T>
ParentedTreeNode<T>* preorder_find_predecessor(ParentedTreeNode<T>* root, ParentedTreeNode<T>* node)
{
    (void)root;

    if (!node || !node->parent)
        return nullptr;

    if (node->parent->left ==node)
        return node->parent;
    if (node->parent->right ==node)
    {
        if (!node->parent->left)
            return node->parent;
        auto current = node->parent->left;
        while (current->left || current->right)
        {
            if (current->right)
                current = current->right;
            else
                current = current->left;
        }
        return current;
    }
    return nullptr;
}

template <typename T>
ParentedTreeNode<T>* inorder_find_predecessor(ParentedTreeNode<T>* root, ParentedTreeNode<T>* node)
{
    (void)root;

    if (!node)
        return nullptr;

    // Case 1: If a left child exists, the predecessor is the rightmost node in the left subtree.
    if (node->left)
    {
        auto current = node->left;
        while (current->right)
            current = current->right;
        return current;
    }

    // Case 2: climb until we come from a right child.
    auto current = node;

    while (current->parent &&
           current == current->parent->left)
    {
        current = current->parent;
    }

    return current->parent;
}

template <typename T>
ParentedTreeNode<T>* postorder_find_predecessor(ParentedTreeNode<T>* root, ParentedTreeNode<T>* node)
{
    (void)root;

    if (!node)
        return nullptr;

    if(node->right)
        return node->right;
    if (node->left)
        return node->left;

    auto current = node;

    while (current->parent)
    {
        if (current == current->parent->right &&
            current->parent->left)
        {
            return current->parent->left;
        }

        current = current->parent;
    }
    return nullptr;
}

#endif // ALGORITHMS_FIND_PREDECESSOR_H
