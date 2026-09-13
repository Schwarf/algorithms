//
// Created by andreas on 13.09.26.
//

#ifndef ALGORITHMS_DELETE_NODE_H
#define ALGORITHMS_DELETE_NODE_H
// Delete a Node from a Binary Search Tree
//
// Given the root of a binary search tree and a key, remove the node whose
// value equals the key.
//
// Preserve the BST ordering after the deletion.
#include "trees/binary_trees/tree_node.h"


// We distinguish 3 cases
// - delete leaf node
// - delete node with one ancestor left or right
// - delete node with two ancestors left and right --> complicated

template<typename T>
TreeNode<T> * delete_node(TreeNode<T>* root, T value)
{
    if (!root)
        return nullptr;

    if (value < root->value)
        root->left = delete_node(root->left, value);
    else if (value > root->value)
        root->right = delete_node(root->right, value);
    else
    {
        if (!root->left)
        {
            auto right = root->right;
            delete root;
            return right;
        }
        else if (!root->right)
        {
            auto left = root->left;
            delete root;
            return left;
        }
        else
        {
            auto rightmost = root->left;
            while (rightmost->right)
                rightmost = rightmost->right;
            root->value = rightmost->value;
            root->left = delete_node(root->left, rightmost->value);
        }
    }
    return root;
}


#endif // ALGORITHMS_DELETE_NODE_H
