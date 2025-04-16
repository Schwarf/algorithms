//
// Created by andreas on 16.04.25.
//

#ifndef BOUNDARY_OF_BINARY_TREE_H
#define BOUNDARY_OF_BINARY_TREE_H

// The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered
// from left-to-right, and the reverse order of the right boundary.
// The left boundary is the set of nodes defined by the following:
//  - The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
//  - If a node in the left boundary and has a left child, then the left child is in the left boundary.
//  - If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
//  - The leftmost leaf is not in the left boundary.
// The right boundary is similar to the left boundary, except it is the right side of the root's right subtree.
// Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.
// The leaves are nodes that do not have any children. For this problem, the root is not a leaf.
// Given the root of a binary tree, return the values of its boundary.
// LC: 545

#include <algorithm>
#include <vector>
#include "tree_node.h"


template <typename T>
void left_boundary(TreeNode<T>* root, std::vector<T> & left)
{
    if(root->left)
    {
        left.push_back(root->value);
        left_boundary(root->left, left);
        return;
    }
    if(root->right){
        left.push_back(root->value);
        left_boundary(root->right, left);
        return;
    }
}

template <typename T>
void right_boundary(TreeNode<T>* root, std::vector<T> & right)
{
    if(root->right)
    {
        right.push_back(root->value);
        right_boundary(root->right, right);
        return;
    }
    if(root->left){
        right.push_back(root->value);
        right_boundary(root->left, right);
        return;
    }
}

template <typename T>
void pre_order(TreeNode<T>* root, std::vector<T> & leaves)
{
    if(!root->left && !root->right)
    {
        leaves.push_back(root->value);
        return;
    }
    if(root->left)
        pre_order(root->left, leaves);
    if(root->right)
        pre_order(root->right, leaves);

}


template <typename T>
std::vector<T> boundary_of_binary_tree(TreeNode<T> * root)
{
    if(!root)
        return {};
    std::vector<T> left;
    std::vector<T> right;
    std::vector<T> leaves;
    left.push_back(root->value);
    if(root->left)
    {
        // compute boundary on left subtree
        left_boundary(root->left, left);
        // get the leaves of the left subtree
        pre_order(root->left, leaves);
    }
    if(root->right)
    {
        // compute boundary on right subtree
        right_boundary(root->right, right);
        // get the leaves of the right subtree
        pre_order(root->right, leaves);
    }
    // we need to reverse the right boundary values
    std::reverse(right.begin(), right.end());
    left.insert(left.end(), leaves.begin(), leaves.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

#endif //BOUNDARY_OF_BINARY_TREE_H
