//
// Created by andreas on 19.01.26.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/height_balanced_binary_tree.h"

TEST_F(SetupBinaryTree, EmptyTreeIsBalanced) {
    TreeNode<int>* root = nullptr;
    EXPECT_TRUE(height_balanced_binary_tree(root));
}

TEST_F(SetupBinaryTree, OneNodeIsBalanced) {
    auto root = new TreeNode<int>(42);
    EXPECT_TRUE(height_balanced_binary_tree(root));
}

TEST_F(SetupBinaryTree, InvertedTreeIsBalanced) {
    auto root = inverted_small_binary_tree_root();
    EXPECT_TRUE(height_balanced_binary_tree(root));
}

TEST_F(SetupBinaryTree, EvenOddTreeIsNotBalanced) {
    auto root = even_odd_tree1();
    EXPECT_FALSE(height_balanced_binary_tree(root));
}

TEST_F(SetupBinaryTree, TwoNodesIsBalanced) {
    auto root = new TreeNode<int>(1);
    root->right = new TreeNode<int>(2);
    EXPECT_TRUE(height_balanced_binary_tree(root));
}
