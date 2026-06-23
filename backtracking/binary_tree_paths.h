//
// Created by andreas on 23.06.26.
//

#ifndef ALGORITHMS_BINARY_TREE_PATHS_H
#define ALGORITHMS_BINARY_TREE_PATHS_H
// Given the root of a binary tree, return a list of strings representing every path from the root to a leaf node.
// A path should contain the node values in traversal order, separated by "->".
// Return the paths in any order.
#include<vector>
#include<string>
#include "./../data_structures/source/trees/binary_trees/tree_node.h"

void backtrack(std::vector<std::string> & result, std::string & current, TreeNode<int> * node)
{
    const size_t old_size = current.size();

    if(!current.empty())
    {
        current += "->";
    }

    current += std::to_string(node->value);

    if (!node->left && !node->right)
    {
        result.push_back(current);
    }
    else
    {
        if (node->left)
            backtrack(result, current, node->left);
        if (node->right)
            backtrack(result, current, node->right);
    }
    current.resize(old_size);
}

// Alternative version using copy by value for 'current' variable:
// void backtrack(std::vector<std::string>& result, std::string path, TreeNode<int> * node)
// {
//     if (!path.empty())
//         path += "->";
//
//     path += std::to_string(node->val);
//
//     if (!node->left && !node->right)
//     {
//         result.push_back(path);
//         return;
//     }
//
//     if (node->left)
//         dfs(node->left, path, result);
//
//     if (node->right)
//         dfs(node->right, path, result);
// }

std::vector<std::string> binary_tree_paths(TreeNode<int>* root)
{
    std::vector<std::string> result;
    if (!root)
        return result;
    std::string current;
    backtrack(result, current, root);
    return result;
}



#endif //ALGORITHMS_BINARY_TREE_PATHS_H
