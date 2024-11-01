//
// Created by andreas on 16.07.24.
//

#ifndef DATA_STRUCTURES_DIRECTIONS_FROM_NODE_TO_NODE_H
#define DATA_STRUCTURES_DIRECTIONS_FROM_NODE_TO_NODE_H
// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n.
// You are also given an integer startValue representing the value of the start node s, and a different integer
// destValue representing the value of the destination node t.
// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of
// such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'.
// Each letter indicates a specific direction:
//  'L' means to go from a node to its left child node.
//  'R' means to go from a node to its right child node.
//  'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.
#include "tree_node.h"
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// ---------------------------------------------------------------------------------------------------------------------
// solution with back tracking
// we build a graph, then we bfs through the graph. Startting from start_node we track all nodes (strings) in 
// a hashmap until we reach end_node. Then we use the tracking-hashmap to construct the direction-string and reverse
// it to get the correct answer. Very complicated approach
template<typename T>
requires std::is_integral_v<T>
TreeNode<T> *find_start_node(TreeNode<T> *node, T start_value) {
    if (node == nullptr)
        return node;
    if (node->value == start_value)
        return node;
    auto left = find_start_node(node->left, start_value);
    // if left returns a non-nullptr it must be the
    if (left)
        return left;
    return find_start_node(node->right, start_value);
}

template<typename T>
requires std::is_integral_v<T>
void fill_parent_map(TreeNode<T> *node, std::unordered_map<T, TreeNode<T> *> &parent_map) {
    if (!node)
        return;

    if (node->left) {
        parent_map[node->left->value] = node;
        fill_parent_map(node->left, parent_map);
    }
    if (node->right) {
        parent_map[node->right->value] = node;
        fill_parent_map(node->right, parent_map);
    }

}

template<typename T>
requires std::is_integral_v<T>
std::string backtrack_string(TreeNode<T> *node,
                             std::unordered_map<TreeNode<T> *, std::pair<TreeNode<T> *, std::string>> path_tracker) {
    std::string path;
    std::unordered_set<TreeNode<T> *> visited;
    while (path_tracker.count(node)) {
        visited.insert(node);
        path += path_tracker[node].second;
        node = path_tracker[node].first;
    }
    std::reverse(path.begin(), path.end());
    return path;

}

template<typename T>
requires std::is_integral_v<T>
std::string get_directions(TreeNode<T> *root, T start_value, T end_value) {
    // create undirected graph with the help of a parent map that tracks the parent of each node
    std::unordered_map<T, TreeNode<T> *> parent_map;
    auto start_node = find_start_node(root, start_value);
    fill_parent_map(root, parent_map);

    std::queue<TreeNode<T> *> q;
    q.push(start_node);
    std::unordered_set<TreeNode<T> *> visited;
    std::unordered_map<TreeNode<T> *, std::pair<TreeNode<T> *, std::string>> string_tracker;
    visited.insert(start_node);
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        if (current->value == end_value)
            return backtrack_string(current, string_tracker);

        if (parent_map.find(current->value) != parent_map.end()) {
            auto parent = parent_map[current->value];
            if (visited.find(parent) == visited.end()) {
                q.push(parent);
                string_tracker[parent] = {current, "U"};
                visited.insert(parent);
            }
        }

        if (current->left && visited.find(current->left) == visited.end()) {
            q.push(current->left);
            string_tracker[current->left] = {current, "L"};
            visited.insert(current->left);
        }

        if (current->right && visited.find(current->right) == visited.end()) {
            q.push(current->right);
            string_tracker[current->right] = {current, "R"};
            visited.insert(current->right);
        }

    }
    return {};
}
// end solution without back tracking
// ---------------------------------------------------------------------------------------------------------------------



// another solution is to find the lowest common ancestor (LCA)

template<typename T>
TreeNode<T> *find_lca(TreeNode<T> *node, T value1, T value2) {
    if (!node)
        return nullptr;

    if (node->value == value1 || node->value == value2)
        return node;

    auto left_lca = find_lca(node->left, value1, value2);
    auto right_lca = find_lca(node->right, value1, value2);

    if (!left_lca)
        return right_lca;
    else if (!right_lca)
        return left_lca;
    // Both
    return node;

}

template<typename T>
bool find_path(TreeNode<T> *node, int value, std::string &path) {
    if (!node)
        return false;
    if (node->value == value)
        return true;
    // go down left tree
    path.push_back('L');
    if (find_path(node->left, value, path))
        return true;
    // backtrack, remove left tree if not found
    path.pop_back();
    // go down right tree

    path.push_back('R');
    if (find_path(node->right, value, path))
        return true;
    // backtrack, remove right tree if not found
    path.pop_back();

    return false;
}

template<typename T>
std::string get_directions_lca(TreeNode<T> *root, T start_value, T end_value) {
    auto lowest_common_ancestor = find_lca(root, start_value, end_value);

    std::string path_to_start{};
    std::string path_to_end{};

    find_path(lowest_common_ancestor, start_value, path_to_start);
    find_path(lowest_common_ancestor, end_value, path_to_end);

    std::string directions{};
    // we use the number of down-steps to start and reverse them ([L,R] --> U)
    directions.append(path_to_start.length(), 'U');

    directions.append(path_to_end);

    return directions;
}


#endif //DATA_STRUCTURES_DIRECTIONS_FROM_NODE_TO_NODE_H