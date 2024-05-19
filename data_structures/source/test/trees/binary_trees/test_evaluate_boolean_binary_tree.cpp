//
// Created by andreas on 19.05.24.
//
#include "trees/binary_trees/evaluate_boolean_binary_tree.h"
#include "gtest/gtest.h"


TEST(TestEvaluateBinaryTree, simple1) {
    auto root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(0);
    EXPECT_TRUE(evaluate_binary_tree(root));
}

TEST(TestEvaluateBinaryTree, simple2) {
    auto root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(0);
    root->left->left = new Node(1);
    root->left->right = new Node(0);
    EXPECT_FALSE(evaluate_binary_tree(root));
}

TEST(TestEvaluateBinaryTree, simple3) {
    auto root = new Node(0);
    EXPECT_FALSE(evaluate_binary_tree(root));
}

TEST(TestEvaluateBinaryTree, simple4) {
    auto root = new Node(1);
    EXPECT_TRUE(evaluate_binary_tree(root));
}


TEST(TestEvaluateBinaryTreeIterative, simple1) {
    auto root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(0);
    EXPECT_TRUE(evaluate_binary_tree_iterative(root));
}

TEST(TestEvaluateBinaryTreeIterative, simple2) {
    auto root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(0);
    root->left->left = new Node(1);
    root->left->right = new Node(0);
    EXPECT_FALSE(evaluate_binary_tree_iterative(root));
}

TEST(TestEvaluateBinaryTreeIterative, simple3) {
    auto root = new Node(0);
    EXPECT_FALSE(evaluate_binary_tree_iterative(root));
}

TEST(TestEvaluateBinaryTreeIterative, simple4) {
    auto root = new Node(1);
    EXPECT_TRUE(evaluate_binary_tree_iterative(root));
}
