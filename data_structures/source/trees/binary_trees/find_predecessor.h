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


#endif // ALGORITHMS_FIND_PREDECESSOR_H
