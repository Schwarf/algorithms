//
// Created by andreas on 30.05.24.
//
#include "./../path_sum_binary_tree.h"
#include "gtest/gtest.h"

TEST(TestPathSumBinaryTree, simple1) {
    auto root = new TreeNode<unsigned int>(1);
    root->left = new TreeNode<unsigned int>(2);
    root->right = new TreeNode<unsigned int>(2);
    root->left->left = new TreeNode<unsigned int>(3);
    root->right->left = new TreeNode<unsigned int>(3);
    constexpr unsigned int target_sum{6};
    std::vector<std::vector<unsigned int>> paths{{1, 2, 3},
                                                 {1, 2, 3}};
    EXPECT_EQ(paths, path_sum(root, target_sum));
}


TEST(TestPathSumBinaryTree, simple2) {
    auto root = new TreeNode<unsigned int>(1);
    root->left = new TreeNode<unsigned int>(2);
    root->right = new TreeNode<unsigned int>(2);
    root->left->left = new TreeNode<unsigned int>(5);
    root->right->left = new TreeNode<unsigned int>(11);
    root->right->right = new TreeNode<unsigned int>(1);
    constexpr unsigned int target_sum{4};
    std::vector<std::vector<unsigned int>> paths{{1, 2, 1}};
    EXPECT_EQ(paths, path_sum(root, target_sum));
}


TEST(TestPathSumBinaryTree, simple3) {
    auto root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(4);
    root->right = new TreeNode<int>(2);
    root->left->left = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(11);
    root->right->right = new TreeNode<int>(1);
    constexpr int target_sum{100};
    std::vector<std::vector<int>> paths{};
    EXPECT_EQ(paths, path_sum(root, target_sum));
}

TEST(TestPathSumBinaryTree, simple4) {
    auto root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(4);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(2);
    root->right->left = new TreeNode<int>(3);
    constexpr int target_sum{7};
    std::vector<std::vector<int>> paths{{1, 4, 2}, {1, 3, 3}};
    EXPECT_EQ(paths, path_sum(root, target_sum));
}

