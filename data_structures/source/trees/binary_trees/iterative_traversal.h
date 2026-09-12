//
// Created by andreas on 12.09.26.
//

#ifndef ALGORITHMS_ITERATIVE_TRAVERSAL_H
#define ALGORITHMS_ITERATIVE_TRAVERSAL_H
// Iterative In-order Traversal
//
// Given a binary tree where each node has pointers to its left child,
// right child, and parent, traverse the tree in in-order without using
// recursion or an explicit stack.

#include "tree_node.h"

template <typename T>
void iterative_inorder_traversal(ParentedTreeNode<T>* root, void (*callback)(ParentedTreeNode<T>*))
{
    if (!root)
        return;

    ParentedTreeNode<T>* prev = nullptr;
    auto current = root;

    while (current)
    {
        ParentedTreeNode<T>* next = nullptr;
        if (current->parent == prev)
        {
            if (current->left)
                next = current->left;
            else
            {
                callback(current);
                if (current->right)
                    next = current->right;
                else
                    next = current->parent;
            }
        }
        else if (current->left == prev)
        {
            callback(current);
            if (current->right)
                next = current->right;
            else
                next = current->parent;
        }
        else if (current->right == prev)
            next = current->parent;

        prev = current;
        current = next;
    }

}


template <typename T>
void iterative_preorder_traversal(ParentedTreeNode<T>* root, void (*callback)(ParentedTreeNode<T>*))
{
    if (!root)
        return;

    ParentedTreeNode<T>* prev = nullptr;
    auto current = root;

    while (current)
    {
        ParentedTreeNode<T>* next = nullptr;
        if (current->parent == prev)
        {
            callback(current);
            if (current->left)
                next = current->left;
            else if (current->right)
                next = current->right;
            else
                next = current->parent;
        }
        else if (current->left == prev)
        {
            if (current->right)
                next = current->right;
            else
                next = current->parent;
        }
        else if (current->right == prev)
            next = current->parent;

        prev = current;
        current = next;
    }
}

#endif // ALGORITHMS_ITERATIVE_TRAVERSAL_H
