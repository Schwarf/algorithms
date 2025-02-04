//
// Created by andreas on 02.02.25.
//

#ifndef COUNT_GOOD_NODES_H
#define COUNT_GOOD_NODES_H
#include <memory>

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
int count_good_nodes_dfs(TreeNode<T>* root)
{

    if(!root)
        return T{};
    int count{};
    std::stack<std::pair<TreeNode<T>*, int>> s;
    s.push({root, std::numeric_limits<T>::min()});
    do
    {
        auto [current, max] = s.top();
        s.pop();
        if(current->value >= max)
        {
            max = current->value;
            count++;
        }
        if(current->left)
            s.emplace(current->left, max);
        if(current->right)
            s.emplace(current->right, max);

    }while(!s.empty());

    return count;
}

template <typename T>
requires std::is_signed_v<T>
int count_good_nodes_bfs(TreeNode<T>* root)
{
    if(!root)
        return T{};
    int count{};
    std::queue<std::pair<TreeNode<T> *, int>> q;
    q.emplace(root, std::numeric_limits<T>::min());
    do
    {
        auto [current, max] = q.front();
        q.pop();
        if(current->value >= max)
        {
            max = current->value;
            count++;
        }
        if(current->left)
            q.emplace(current->left, max);
        if(current->right)
            q.emplace(current->right, max);

    }while(!q.empty());

    return count;
}

std::shared_ptr<int>

#endif //COUNT_GOOD_NODES_H
