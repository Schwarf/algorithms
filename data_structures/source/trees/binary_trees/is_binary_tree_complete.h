//
// Created by andreas on 15.03.23.
//

#ifndef IS_BINARY_TREE_COMPLETE_H
#define IS_BINARY_TREE_COMPLETE_H
// Check if every level in a binary tree is filled except maybe the last one. A binary tree is called complete
// if all levels are filled from left to right except maybe the last level. Check if a given binary tree is complete
#include "tree_node.h"
#include <queue>

// Use breadth firtst search
// Check if every level in a binary tree is filled except maybe the last one. A binary tree is called complete
// if all levels are filled from left to right except maybe the last level. Check if a given binary tree is complete
#include "tree_node.h"
#include <queue>

// Use breadth firtst search
template <typename T>
bool is_tree_complete(TreeNode<T>* root)
{
    if (!root)
        return true;
    std::queue<TreeNode<T>*> q{{root}};
    bool is_nullptr_found{};
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (!node)
            is_nullptr_found = true;
        else
        {
            if (is_nullptr_found)
                return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}


template <typename T>
bool is_tree_complete2(TreeNode<T>* root)
{
    if (!root)
        return true;
    std::queue<TreeNode<T>*> queue{{root}};
    while (!queue.empty())
    {
        auto node = queue.front();
        queue.pop();
        if (!node)
        {
            // Now every remaining item in q must be nullptr:
            while (!queue.empty())
            {
                if (queue.front())
                    return false;
                queue.pop();
            }
            break;
        }
        queue.push(node->left);
        queue.push(node->right);
    }
    return true;
}


#endif //IS_BINARY_TREE_COMPLETE_H
