//
// Created by andreas on 26.08.24.
//
#include "trees/n-ary_trees/postorder_traversal.h"
#include "gtest/gtest.h"

TEST(TestPostOrderTraversalRecursive, simple1) {
    auto tree = new TreeNode<int>(1);
    tree->children.push_back(new TreeNode<int>(3));
    tree->children.push_back(new TreeNode<int>(2));
    tree->children.push_back(new TreeNode<int>(4));
    tree->children[0]->children.push_back(new TreeNode<int>(5));
    tree->children[0]->children.push_back(new TreeNode<int>(6));
    const std::vector<int> expected_output{5, 6, 3, 2, 4, 1};
    EXPECT_EQ(postorder_traversal_recursive(tree), expected_output);
}

TEST(TestPostOrderTraversalRecursive, simple2) {
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
    const std::vector<int> expected_output{2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
    EXPECT_EQ(postorder_traversal_recursive(tree), expected_output);
}

TEST(TestPostOrderTraversalRecursive, simple3) {
    auto tree = new TreeNode<int>(3);
    tree->children.push_back(new TreeNode<int>(5));
    tree->children.push_back(new TreeNode<int>(1));
    const std::vector<int> expected_output{5, 1, 3};
    EXPECT_EQ(postorder_traversal_recursive(tree), expected_output);
}

TEST(TestPostOrderTraversalRecursive, simple4) {
    auto tree = new TreeNode<int>(3);
    tree->children.push_back(new TreeNode<int>(1));
    tree->children[0]->children.push_back(new TreeNode<int>(5));
    const std::vector<int> expected_output{5, 1, 3};
    EXPECT_EQ(postorder_traversal_recursive(tree), expected_output);
}

TEST(TestPostOrderTraversalRecursive, simple5) {
    TreeNode<float> *tree = nullptr;
    const std::vector<float> expected_output{};
    EXPECT_EQ(postorder_traversal_recursive(tree), expected_output);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////


TEST(TestPostOrderTraversalIterative, simple1) {
    auto tree = new TreeNode<int>(1);
    tree->children.push_back(new TreeNode<int>(3));
    tree->children.push_back(new TreeNode<int>(2));
    tree->children.push_back(new TreeNode<int>(4));
    tree->children[0]->children.push_back(new TreeNode<int>(5));
    tree->children[0]->children.push_back(new TreeNode<int>(6));
    const std::vector<int> expected_output{5, 6, 3, 2, 4, 1};
    EXPECT_EQ(postorder_traversal_iterative(tree), expected_output);
}

TEST(TestPostOrderTraversalIterative, simple2) {
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
    const std::vector<int> expected_output{2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1};
    EXPECT_EQ(postorder_traversal_iterative(tree), expected_output);
}

TEST(TestPostOrderTraversalIterative, simple3) {
    auto tree = new TreeNode<int>(3);
    tree->children.push_back(new TreeNode<int>(5));
    tree->children.push_back(new TreeNode<int>(1));
    const std::vector<int> expected_output{5, 1, 3};
    EXPECT_EQ(postorder_traversal_iterative(tree), expected_output);
}

TEST(TestPostOrderTraversalIterative, simple4) {
    auto tree = new TreeNode<int>(3);
    tree->children.push_back(new TreeNode<int>(1));
    tree->children[0]->children.push_back(new TreeNode<int>(5));
    const std::vector<int> expected_output{5, 1, 3};
    EXPECT_EQ(postorder_traversal_iterative(tree), expected_output);
}

TEST(TestPostOrderTraversalIterative, simple5) {
    TreeNode<float> *tree = nullptr;
    const std::vector<float> expected_output{};
    EXPECT_EQ(postorder_traversal_iterative(tree), expected_output);
}
