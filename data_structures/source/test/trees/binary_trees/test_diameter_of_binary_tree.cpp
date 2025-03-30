//
// Created by andreas on 28.02.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/diameter_of_binary_tree.h"


TEST_F(SetupBinaryTree, simple1)
{
    auto tree = small_binary_tree_root();
    constexpr int expected_diameter{3};
    EXPECT_EQ(expected_diameter, diameter_of_tree(tree));
}

TEST_F(SetupBinaryTree, simple2)
{
    auto tree = binary_tree_root();
    constexpr int expected_diameter{6};
    EXPECT_EQ(expected_diameter, diameter_of_tree(tree));
}

TEST_F(SetupBinaryTree, simple3)
{
    auto tree = medium_tree_with_subtree_duplicates1();
    constexpr int expected_diameter{5};
    EXPECT_EQ(expected_diameter, diameter_of_tree(tree));
}

TEST_F(SetupBinaryTree, simple5)
{
    auto tree = new TreeNode<float>{0.f};
    constexpr int expected_diameter{0};
    EXPECT_EQ(expected_diameter, diameter_of_tree(tree));
}

TEST_F(SetupBinaryTree, simple6)
{
    auto tree = new TreeNode<float>{0.f};
    tree->left = new TreeNode<float>{2.f};
    constexpr int expected_diameter{1};
    EXPECT_EQ(expected_diameter, diameter_of_tree(tree));
}

TEST_F(SetupBinaryTree, medium1)
{
    auto tree = new TreeNode<float>{0.f};
    tree->left = new TreeNode<float>{2.f};
    tree->right = new TreeNode<float>{2.f};
    tree->left->right = new TreeNode<float>{2.f};
    tree->left->left = new TreeNode<float>{2.f};
    tree->left->right->left = new TreeNode<float>{2.f};
    tree->left->left->right = new TreeNode<float>{2.f};
    tree->left->right->left->right = new TreeNode<float>{2.f};
    tree->left->left->right->left = new TreeNode<float>{2.f};
    constexpr int expected_diameter{6};
    EXPECT_EQ(expected_diameter, diameter_of_tree(tree));
}


TEST_F(SetupBinaryTree, simple_optimal1)
{
    auto tree = small_binary_tree_root();
    constexpr int expected_diameter{3};
    EXPECT_EQ(expected_diameter, diameter_of_tree_optimal(tree));
}

TEST_F(SetupBinaryTree, simple_optimal2)
{
    auto tree = binary_tree_root();
    constexpr int expected_diameter{6};
    EXPECT_EQ(expected_diameter, diameter_of_tree_optimal(tree));
}

TEST_F(SetupBinaryTree, simple_optimal3)
{
    auto tree = medium_tree_with_subtree_duplicates1();
    constexpr int expected_diameter{5};
    EXPECT_EQ(expected_diameter, diameter_of_tree_optimal(tree));
}

TEST_F(SetupBinaryTree, simple_optimal5)
{
    auto tree = new TreeNode<float>{0.f};
    constexpr int expected_diameter{0};
    EXPECT_EQ(expected_diameter, diameter_of_tree_optimal(tree));
}

TEST_F(SetupBinaryTree, simple_optimal6)
{
    auto tree = new TreeNode<float>{0.f};
    tree->left = new TreeNode<float>{2.f};
    constexpr int expected_diameter{1};
    EXPECT_EQ(expected_diameter, diameter_of_tree_optimal(tree));
}

TEST_F(SetupBinaryTree, medium_optimal1)
{
    auto tree = new TreeNode<float>{0.f};
    tree->left = new TreeNode<float>{2.f};
    tree->right = new TreeNode<float>{2.f};
    tree->left->right = new TreeNode<float>{2.f};
    tree->left->left = new TreeNode<float>{2.f};
    tree->left->right->left = new TreeNode<float>{2.f};
    tree->left->left->right = new TreeNode<float>{2.f};
    tree->left->right->left->right = new TreeNode<float>{2.f};
    tree->left->left->right->left = new TreeNode<float>{2.f};
    constexpr int expected_diameter{6};
    EXPECT_EQ(expected_diameter, diameter_of_tree_optimal(tree));
}
