//
// Created by andreas on 04.08.22.
//

#ifndef FLATTEN_BINARY_SEARCH_TREE_TO_LINKED_LIST_H
#define FLATTEN_BINARY_SEARCH_TREE_TO_LINKED_LIST_H

#include "../trees/binary_trees/tree_node.h"

// Write a function that takes in a Binary Tree, flattens it in preorder,
// and returns the first node of the flattened tree.
// A flattened Binary Tree is a structure that's nearly identical
// to a Doubly Linked List (except that nodes have left and right pointers
// instead of prev and next pointers).
// The nodes in the flattened tree should appear in the same
// order as a preorder traversal of the original tree.

template <typename T>
void preorder(TreeNode<T>* node, TreeNode<T> *& prev)
{
    if (!node)
        return;
    TreeNode<T>* right = node->right;
    TreeNode<T>* left = node->left;
    if (prev)
    {
        prev->right = node;
    }
    node->left = prev;
    prev = node;
    preorder(left, prev);
    preorder(right, prev);
}

template <typename T>
TreeNode<T>* flatten_to_linked_list_preorder(TreeNode<T>* root)
{
    TreeNode<T> * prev = nullptr;
    preorder(root, prev);
    return root;
}

#endif // FLATTEN_BINARY_SEARCH_TREE_TO_LINKED_LIST_H
