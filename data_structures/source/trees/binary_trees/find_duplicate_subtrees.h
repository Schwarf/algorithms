//
// Created by andreas on 28.02.23.
//

#ifndef FIND_DUPLICATE_SUBTREES_H
#define FIND_DUPLICATE_SUBTREES_H

#include <vector>
#include <string>
#include <unordered_map>
#include "tree_node.h"

// This function builds strings from subtrees and stores them in a hash-map. If more
// than one subtree exists we push the root node into the duplicates vector.
template<typename T>
std::string serialize_subtrees(TreeNode<T> *node,
                               std::unordered_map<std::string, int> &subtrees,
                               std::vector<TreeNode<T> *> &duplicates) {
    if (!node)
        return "!"; // nullptr are represented by '!'

    std::string left = serialize_subtrees(node->left, subtrees, duplicates);
    std::string right = serialize_subtrees(node->right, subtrees, duplicates);
    // subtree is constructed in post-order. Left and right notes are separated by ','
    std::string
            subtree_string = left + "," + right + "," + std::to_string(node->value); // Serialize the current subtree

    if (subtrees[subtree_string] == 1)
        duplicates.push_back(node);
    subtrees[subtree_string]++;
    return subtree_string;
}

template<typename T>
std::vector<TreeNode<T> *> find_duplicate_subtrees(TreeNode<T> *root) {
    std::unordered_map<std::string, int> subtrees;
    std::vector<TreeNode<T> *> duplicates;
    serialize_subtrees(root, subtrees, duplicates);
    return duplicates;
}

#endif //FIND_DUPLICATE_SUBTREES_H
