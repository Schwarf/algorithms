//
// Created by andreas on 20.04.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/smallest_string_starting_from_leaf.h"


TEST_F(SetupBinaryTree, TestSmallestStringStartingFromLeaf1) {
    auto input_tree = medium_tree_with_subtree_duplicates2();
    const std::string expected_result{"cba"};
    std::string result;
    smallest_string_starting_from_leaf(input_tree, result);
}

TEST_F(SetupBinaryTree, TestSmallestStringStartingFromLeaf2) {
    auto input_tree = medium_tree_with_subtree_duplicates1();
    const std::string expected_result{"ecb"};
    std::string result;
    smallest_string_starting_from_leaf(input_tree, result);
}


TEST_F(SetupBinaryTree, TestSmallestStringStartingFromLeaf3) {
    auto input_tree = medium_tree_with_subtree_duplicates1();
    input_tree->value = 25;
    const std::string expected_result{"ecdz"};
    std::string result;
    smallest_string_starting_from_leaf(input_tree, result);
}
