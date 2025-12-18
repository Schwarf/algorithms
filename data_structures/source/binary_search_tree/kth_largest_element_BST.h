//
// Created by andreas on 18.12.25.
//

#ifndef ALGORITHMS_KTH_LARGEST_ELEMENT_BST_H
#define ALGORITHMS_KTH_LARGEST_ELEMENT_BST_H

// You’re given the root of a Binary Search Tree (BST) and an integer k.
// Write a function that returns the k-th largest value stored in the BST.
// A BST is a binary tree where, for every node:
// - values in the left subtree are strictly less than the node’s value,
// - values in the right subtree are greater than or equal to the node’s value.
// Assume k is valid (i.e., 1 ≤ k ≤ number of nodes), and return an integer.
#include <vector>

#include "../trees/binary_trees/tree_node.h"

template <typename T>
void inorder(TreeNode<T>* node, std::vector<T> & values)
{
    if(!node)
        return;
    inorder(node->left, values);
    values.push_back(node->value);
    inorder(node->right, values);

}

// Straightforward inorder traversal. O(n) time and O(n) space
template <typename T>
int find_Kth_largest_value(TreeNode<T>* tree, int k)
{
    std::vector<T> values;
    inorder(tree, values);
    return values[values.size()-k];
}




#endif //ALGORITHMS_KTH_LARGEST_ELEMENT_BST_H