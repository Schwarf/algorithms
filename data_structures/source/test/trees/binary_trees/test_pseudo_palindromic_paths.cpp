//
// Created by andreas on 25.01.24.
//

#include "gtest/gtest.h"
#include "setup_binary_tree.h"
#include "trees/binary_trees/pseudo_palindromic_paths.h"


TEST_F(SetupBinaryTree, TestPalindrome1) {
    auto tree = SetupBinaryTree::palindromic_tree1();
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, pseudo_palindromic_paths(tree));
}

TEST_F(SetupBinaryTree, TestPalindrome2) {
    auto tree = SetupBinaryTree::palindromic_tree2();
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, pseudo_palindromic_paths(tree));
}

TEST_F(SetupBinaryTree, TestPalindrome3) {
    auto tree = SetupBinaryTree::infected_tree1();
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, pseudo_palindromic_paths(tree));
}
