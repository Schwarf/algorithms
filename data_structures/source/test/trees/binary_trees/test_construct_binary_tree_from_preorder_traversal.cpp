//
// Created by andreas on 23.02.25.
//

#include "trees/binary_trees/construct_binary_tree_from_preorder_traversal.h"
#include "setup_binary_tree.h"
#include "gtest/gtest.h"

TEST(TestConstructBinaryTreeFromPreorderTraversal, simple1)
{
    std::string input{"1-2--3--4-5--6--7"};
    auto tree = new TreeNode<int>(1);
    tree->left = new TreeNode<int>(2);
    tree->right = new TreeNode<int>(5);
    tree->left->left = new TreeNode<int>(3);
    tree->left->right = new TreeNode<int>(4);
    tree->right->left = new TreeNode<int>(6);
    tree->right->right = new TreeNode<int>(7);

    auto result = construct_binary_tree_from_preorder<int>(input);
    EXPECT_TRUE(is_same_tree(result, tree));
}

TEST(TestConstructBinaryTreeFromPreorderTraversal, simple2)
{
    std::string input{"1"};
    auto tree = new TreeNode<int>(1);

    auto result = construct_binary_tree_from_preorder<int>(input);
    EXPECT_TRUE(is_same_tree(result, tree));
}


TEST(TestConstructBinaryTreeFromPreorderTraversal, simple3)
{
    std::string input{"11-41--49---901--888"};
    auto tree = new TreeNode<int>(11);
    tree->left = new TreeNode<int>(41);
    tree->left->left = new TreeNode<int>(49);
    tree->left->right = new TreeNode<int>(888);
    tree->left->left->left = new TreeNode<int>(901);

    auto result = construct_binary_tree_from_preorder<int>(input);
    EXPECT_TRUE(is_same_tree(result, tree));
}

TEST(TestConstructBinaryTreeFromPreorderTraversal, single_child_is_left_child)
{
    std::string input{"1-2"};
    auto tree = new TreeNode<int>(1);
    tree->left = new TreeNode<int>(2);

    auto result = construct_binary_tree_from_preorder<int>(input);
    EXPECT_TRUE(is_same_tree(result, tree));
}

TEST(TestConstructBinaryTreeFromPreorderTraversal, simple4)
{
    std::string input{"1-2--3---4-5--6---7"};
    auto tree = new TreeNode<int>(1);
    tree->left = new TreeNode<int>(2);
    tree->left->left = new TreeNode<int>(3);
    tree->left->left->left = new TreeNode<int>(4);
    tree->right = new TreeNode<int>(5);
    tree->right->left = new TreeNode<int>(6);
    tree->right->left->left = new TreeNode<int>(7);
    auto result = construct_binary_tree_from_preorder<int>(input);
    EXPECT_TRUE(is_same_tree(result, tree));
}
