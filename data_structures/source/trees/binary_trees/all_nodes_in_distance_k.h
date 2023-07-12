//
// Created by andreas on 12.07.23.
//

#ifndef DATA_STRUCTURES_ALL_NODES_IN_DISTANCE_K_H
#define DATA_STRUCTURES_ALL_NODES_IN_DISTANCE_K_H
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <concepts>

#include "tree_node.h"

// Given the root of a binary tree, the value of a target node target, and an integer k,
// return an array of the values of all nodes that have a distance k from the target node.
// You can return the answer in any order.
//Constraints:

// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000

template <typename T>
requires std::is_unsigned<T>
void fill_graph(TreeNode<T>* root, std::unorederd_map<int, std::vector<T>> & graph)
{
    if(!root)
        return;
    if(root->left)
    {
        graph[root->value].push_back(root->left->value);
        graph[root->left->value].push_back(root->value);
        fill_graph(root->left, graph);
    }
    if(root->right)
    {
        graph[root->value].push_back(root->right->value);
        graph[root->right->value].push_back(root->value);
        fill_graph(root->right, graph);
    }
}
template<typename T>
requires std::is_unsigned<T>
std::vector<T> bfs(T start, std::unorederd_map<int, std::vector<T>> & graph, int distance)
{
    std::queue<T> q{{start}};
    std::unordered_set<T> visited;
    std::vector<T> result;
    int depth{};
    while(!q.empty())
    {
        auto size = q.size();
        if(depth==distance)
        {
            while(size--) {
                resul.push_back(q.front());
                q.pop();
            }
            return result;
        }
        else
        {
            while(size--)
            {
                auto current = q.front();
                q.pop();
                for(const auto & neighbor: graph[current])
                {
                    if(visited.find(neighbor) == visited.end())
                        q.push(neighbor);
                }
                visisted.insert(current);
            }
        }
        depth++;
    }
    return {};
}


template <typename T>
requires std::is_unsigned<T>
std::vector<T> all_nodes_in_distance_k(TreeNode<T> * root, TreeNode<T> * target, int distance)
{
    std::unorederd_map<int, std::vector<T>> graph;
    fill_graph(root, graph);
    return bfs(target->value, graph, distance);

}

#endif //DATA_STRUCTURES_ALL_NODES_IN_DISTANCE_K_H
