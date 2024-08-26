//
// Created by andreas on 26.08.24.
//
#include "trees/n-ary_trees/preorder_traversal.h"
#include "gtest/gtest.h"

TEST(TestPreorderTraversalRecursive, simple1) {
    auto tree = new TreeNode<int>(1);
    tree->children.push_back(new TreeNode<int>(3));
    tree->children.push_back(new TreeNode<int>(2));
    tree->children.push_back(new TreeNode<int>(4));
    tree->children[0]->children.push_back(new TreeNode<int>(5));
    tree->children[0]->children.push_back(new TreeNode<int>(6));
    const std::vector<int> expected_output{1, 3, 5, 6, 2, 4};
    EXPECT_EQ(preorder_traversal_recursive(tree), expected_output);
}

TEST(TestPreOrderTraversalIterative, simple2) {
    auto tree = new TreeNode<int>(1);
    tree->children.push_back(new TreeNode<int>(2));
    tree->children.push_back(new TreeNode<int>(3));
    tree->children.push_back(new TreeNode<int>(4));
    tree->children.push_back(new TreeNode<int>(5));
    tree->children[1]->children.push_back(new TreeNode<int>(6));
    tree->children[1]->children.push_back(new TreeNode<int>(7));
    tree->children[1]->children[1]->children.push_back(new TreeNode<int>(11));
    tree->children[1]->children[1]->children[0]->children.push_back(new TreeNode<int>(14));
    tree->children[2]->children.push_back(new TreeNode<int>(8));
    tree->children[2]->children[0]->children.push_back(new TreeNode<int>(12));
    tree->children[3]->children.push_back(new TreeNode<int>(9));
    tree->children[3]->children.push_back(new TreeNode<int>(10));
    tree->children[3]->children[0]->children.push_back(new TreeNode<int>(13));
    const std::vector<int> expected_output{1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10};
    EXPECT_EQ(preorder_traversal_recursive(tree), expected_output);
}

TEST(TestPreOrderTraversalIterative, simple3) {
    auto tree = new TreeNode<int>(3);
    tree->children.push_back(new TreeNode<int>(5));
    tree->children.push_back(new TreeNode<int>(1));
    const std::vector<int> expected_output{3, 5, 1};
    EXPECT_EQ(preorder_traversal_recursive(tree), expected_output);
}

TEST(TestPreOrderTraversalIterative, simple4) {
    auto tree = new TreeNode<int>(3);
    tree->children.push_back(new TreeNode<int>(1));
    tree->children[0]->children.push_back(new TreeNode<int>(5));
    const std::vector<int> expected_output{3, 1, 5};
    EXPECT_EQ(preorder_traversal_recursive(tree), expected_output);
}

TEST(TestPreOrderTraversalIterative, simple5) {
    TreeNode<float> *tree = nullptr;
    const std::vector<float> expected_output{};
    EXPECT_EQ(preorder_traversal_recursive(tree), expected_output);
}
