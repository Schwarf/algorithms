//
// Created by andreas on 23.02.25.
//

#ifndef CONSTRUCT_BINARY_TREE_FROM_PREORDER_TRAVERSAL_H
#define CONSTRUCT_BINARY_TREE_FROM_PREORDER_TRAVERSAL_H
#include "tree_node.h"
// We run a preorder depth-first search (DFS) on the root of a binary tree.
// At each node in this traversal, we output D dashes (where D is the depth of this node),
// then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.
// The depth of the root node is 0.
// If a node has only one child, that child is guaranteed to be the left child.

// Given the output traversal of this traversal, recover the tree and return its root.
#include <stack>
#include <string>

template <typename T>
TreeNode<T>* construct_binary_tree_from_preorder(std::string preorder_traversal)
{
    std::stack<TreeNode<T>*> node_stack;
    int index{};
    while (index < preorder_traversal.size())
    {
        int depth{};
        while (index < preorder_traversal.size() && preorder_traversal[index] == '-')
        {
            depth++;
            index++;
        }
        int value{};
        while (index < preorder_traversal.size() && std::isdigit(preorder_traversal[index]))
        {
            value = value * 10 + (preorder_traversal[index] - '0');
            index++;
        }
        TreeNode<T>* new_node = new TreeNode<T>(value);
        // Adjust the stack to the correct depth
        while (node_stack.size() > depth)
        {
            node_stack.pop();
        }
        if (!node_stack.empty())
        {
            if (node_stack.top()->left == nullptr)
            {
                node_stack.top()->left = new_node;
            }
            else
            {
                node_stack.top()->right = new_node;
            }
        }
        node_stack.push(new_node);
    }
    while (node_stack.size() > 1)
    {
        node_stack.pop();
    }
    return node_stack.top();
}

#endif //CONSTRUCT_BINARY_TREE_FROM_PREORDER_TRAVERSAL_H
