//
// Created by andreas on 25.01.24.
//

#ifndef PSEUDO_PALINDROMIC_PATHS_H
#define PSEUDO_PALINDROMIC_PATHS_H
// Given a binary tree where node values are digits from 1 to 9.
// A path in the binary tree is said to be pseudo-palindromic if at least one
// permutation of the node values in the path is a palindrome.
// Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
#include "tree_node.h"

int pseudo_palindromic_paths(TreeNode<int> *root, int digit_frequency = 0) {
    if (!root)
        return 0;
    digit_frequency ^= (1 << root->value);
    int number_of_palindromes = pseudo_palindromic_paths(root->left, digit_frequency) +
                                pseudo_palindromic_paths(root->right, digit_frequency);
    if (!root->left && !root->right && (digit_frequency & (digit_frequency - 1)) == 0)
        number_of_palindromes++;
    return number_of_palindromes;
}

#endif //PSEUDO_PALINDROMIC_PATHS_H
