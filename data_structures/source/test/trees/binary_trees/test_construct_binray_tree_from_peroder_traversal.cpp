//
// Created by andreas on 23.02.25.
//

#include "trees/binary_trees/construct_binary_tree_from_preorder_traversal.h"
#include "trees/binary_trees/pre_order_traversal.h"
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
    EXPECT_EQ(pre_order_traversal(result), pre_order_traversal(tree));
}

TEST(TestConstructBinaryTreeFromPreorderTraversal, simple2)
{
    std::string input{"1"};
    auto tree = new TreeNode<int>(1);

    auto result = construct_binary_tree_from_preorder<int>(input);
    EXPECT_EQ(pre_order_traversal(result), pre_order_traversal(tree));
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
    EXPECT_EQ(pre_order_traversal(result), pre_order_traversal(tree));
}

TEST(TestConstructBinaryTreeFromPreorderTraversal, no_uniqueness)
{
    std::string input{"1-2"};
    auto tree = new TreeNode<int>(1);
    tree->right = new TreeNode<int>(2);
    auto tree2 = new TreeNode<int>(1);
    tree2->left = new TreeNode<int>(2);

    auto result = construct_binary_tree_from_preorder<int>(input);
    EXPECT_EQ(pre_order_traversal(result), pre_order_traversal(tree));
    EXPECT_EQ(pre_order_traversal(result), pre_order_traversal(tree2));
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
    EXPECT_EQ(pre_order_traversal(result), pre_order_traversal(tree));
}
