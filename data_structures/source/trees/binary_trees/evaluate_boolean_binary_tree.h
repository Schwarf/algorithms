//
// Created by andreas on 19.05.24.
//

#ifndef DATA_STRUCTURES_EVALUATE_BOOLEAN_BINARY_TREE_H
#define DATA_STRUCTURES_EVALUATE_BOOLEAN_BINARY_TREE_H
// You are given the root of a full binary tree with the following properties:
// Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
// Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
// The evaluation of a node is as follows:
// If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
// Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
// Return the boolean result of evaluating the root node.
// A full binary tree is a binary tree where each node has either 0 or 2 children.
// A leaf node is a node that has zero children.
#include <stack>
#include <unordered_map>
#include "tree_node.h"


using Node = TreeNode<int>;

bool evaluate_binary_tree(Node *root) {
    if (!root->left && !root->right)
        return root->value == 1 ? true : false;
    auto left = evaluate_binary_tree(root->left);
    auto right = evaluate_binary_tree(root->right);
    return root->value == 2 ? left || right : left && right;
}

bool evaluate_binary_tree_iterative(Node *root) {
    std::stack<Node *> s;
    s.push(root);
    std::unordered_map<Node *, bool> evaluated;
    while (!s.empty()) {
        auto current = s.top();
        // Is leaf node?
        if (!current->left && !current->right) {
            s.pop();
            evaluated[current] = current->value;
            continue;
        }

        if (evaluated.find(current->left) != evaluated.end() && evaluated.find(current->right) != evaluated.end()) {
            s.pop();
            if (current->value == 2) {
                evaluated[current] = evaluated[current->left] || evaluated[current->right];
            } else {
                evaluated[current] = evaluated[current->left] && evaluated[current->right];
            }
        } else {
            s.push(current->left);
            s.push(current->right);
        }
    }
    return evaluated[root];
}


#endif //DATA_STRUCTURES_EVALUATE_BOOLEAN_BINARY_TREE_H
