//
// Created by andreas on 15.10.26.
//

#ifndef BEHAVIORAL_PATTERNS_BST_ITERATOR_H
#define BEHAVIORAL_PATTERNS_BST_ITERATOR_H
// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
//
//     BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
//     boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
//     int next() Moves the pointer to the right, then returns the number at the pointer.
//
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
//
// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order
// traversal when next() is called.
#include <stack>

#include "../trees/binary_trees/tree_node.h"
#include "trees/binary_trees/tree_node.h"

template <typename T>
class BinarySearchTreeIterator
{
    std::stack<TreeNode<T>*> stack;
    void pushleft(TreeNode<T>* node)
    {
        while (node)
        {
            stack.push(node);
            node = node->left;
        }
    }

public:
    explicit BinarySearchTreeIterator(TreeNode<T>* root)
    {
        pushleft(root);
    }

    T next()
    {
        auto current = stack.top();
        stack.pop();
        if (current->right)
        {
            pushleft(current->right);
        }

        return current->value;
    }

    bool hasNext()
    {
        return !stack.empty();
    }
};



#endif // BEHAVIORAL_PATTERNS_BST_ITERATOR_H
