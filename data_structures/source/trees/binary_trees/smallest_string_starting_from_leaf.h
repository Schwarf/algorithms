//
// Created by andreas on 20.04.24.
//

#ifndef DATA_STRUCTURES_SMALLEST_STRING_STARTING_FROM_LEAF_H
#define DATA_STRUCTURES_SMALLEST_STRING_STARTING_FROM_LEAF_H

#include <string>
#include <concepts>
#include "tree_node.h"

// You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters
// 'a' to 'z'.
// Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
// As a reminder, any shorter prefix of a string is lexicographically smaller.
// For example, "ab" is lexicographically smaller than "aba".
// A leaf of a node is a node that has no children.
template<typename T>
requires std::is_unsigned_v<T>
void
smallest_string_starting_from_leaf(TreeNode<T> *root, std::string &smallest_string, std::string current_string = "") {
    if (!root)
        return;
    current_string = static_cast<char>(root->value + 'a') + current_string;
    if (!root->left && !root->right) {
        if (smallest_string.empty() || smallest_string > current_string)
            smallest_string = current_string;
    }

    if (root->left)
        smallest_string_starting_from_leaf(root->left, smallest_string, current_string);
    if (root->right)
        smallest_string_starting_from_leaf(root->right, smallest_string, current_string);

}

#endif //DATA_STRUCTURES_SMALLEST_STRING_STARTING_FROM_LEAF_H
