//
// Created by andreas on 02.02.25.
//

#ifndef COUNT_GOOD_NODES_H
#define COUNT_GOOD_NODES_H
#include "tree_node.h"
#include <stack>
#include <queue>
// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
// Return the number of good nodes in the binary tree.
// Each node's value is between [-10^5, 10^5].

template <typename T>
requires std::is_signed_v<T>
int count_good_nodes_dfs_recursive(TreeNode<T>* root, T max = std::numeric_limits<T>::min())
{
    if(!root)
        return 0;
    if(root->value >= max)
        return 1 + count_good_nodes_dfs_recursive(root->left, root->value) + count_good_nodes_dfs_recursive(root->right, root->value);
    return count_good_nodes_dfs_recursive(root->left, max) + count_good_nodes_dfs_recursive(root->right, max);
}

template <typename T>
requires std::is_signed_v<T>
T count_good_nodes_dfs(TreeNode<T>* root)
{
    if(!root)
        return T{};
    T max{std::numeric_limits<T>::min()};
    int count{};
    std::stack<TreeNode<T> *> s{{root}};
    do
    {
        auto current = s.top();
        s.pop();
        if(current->value >= max)
        {
            max = current->value;
            count++;
        }
        if(current->left)
            s.push(current->left);
        if(current->right)
            s.push(current->right);

    }while(!s.empty());

    return count;
}

template <typename T>
requires std::is_signed_v<T>
T count_good_nodes_bfs(TreeNode<T>* root)
{
    if(!root)
        return T{};
    T max{std::numeric_limits<T>::min()};
    int count{};
    std::queue<TreeNode<T> *> q{{root}};
    do
    {
        auto current = q.front();
        q.pop();
        if(current->value >= max)
        {
            max = current->value;
            count++;
        }
        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);

    }while(!q.empty());

    return count;
}


#endif //COUNT_GOOD_NODES_H
