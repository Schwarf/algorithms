//
// Created by andreas on 16.04.25.
//
#include "trees/binary_trees/boundary_of_binary_tree.h"
#include "setup_binary_tree.h"

TEST_F(SetupBinaryTree, TestBoundaryOfBinaryTreeSimple1)
{
    auto tree = small_binary_tree_root();
    std::vector<unsigned int> expected_result{3, 9, 15, 7, 20};
    EXPECT_EQ(expected_result, boundary_of_binary_tree(tree));
}

TEST_F(SetupBinaryTree, TestBoundaryOfBinaryTreeSimple2)
{
    auto tree = small_tree_with_subtree_duplicates();
    std::vector<unsigned int> expected_result{1, 2, 2};
    EXPECT_EQ(expected_result, boundary_of_binary_tree(tree));
}

TEST_F(SetupBinaryTree, TestBoundaryOfBinaryTreeSimple3)
{
    auto tree = medium_tree_with_subtree_duplicates2();
    std::vector<unsigned int> expected_result{1, 2, 3, 3, 2};
    EXPECT_EQ(expected_result, boundary_of_binary_tree(tree));
}

TEST_F(SetupBinaryTree, TestBoundaryOfBinaryTreeSimple4)
{
    auto tree = new TreeNode<int>(1);
    tree->right = new TreeNode<int>(2);
    tree->right->left = new TreeNode<int>(3);
    tree->right->right = new TreeNode<int>(4);
    std::vector<int> expected_result{1, 3, 4, 2};
    EXPECT_EQ(expected_result, boundary_of_binary_tree(tree));
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


TEST_F(SetupBinaryTree, TestBoundaryOfBinaryTreeOptimalSimple1)
{
    auto tree = small_binary_tree_root();
    std::vector<unsigned int> expected_result{3, 9, 15, 7, 20};
    EXPECT_EQ(expected_result, boundary_of_binary_tree_optimal(tree));
}

TEST_F(SetupBinaryTree, TestBoundaryOfBinaryTreeOptimalSimple2)
{
    auto tree = small_tree_with_subtree_duplicates();
    std::vector<unsigned int> expected_result{1, 2, 2};
    EXPECT_EQ(expected_result, boundary_of_binary_tree_optimal(tree));
}

TEST_F(SetupBinaryTree, TestBoundaryOfBinaryTreeOptimalSimple3)
{
    auto tree = medium_tree_with_subtree_duplicates2();
    std::vector<unsigned int> expected_result{1, 2, 3, 3, 2};
    EXPECT_EQ(expected_result, boundary_of_binary_tree_optimal(tree));
}

TEST_F(SetupBinaryTree, TestBoundaryOfBinaryTreeOptimalSimple4)
{
    auto tree = new TreeNode<int>(1);
    tree->right = new TreeNode<int>(2);
    tree->right->left = new TreeNode<int>(3);
    tree->right->right = new TreeNode<int>(4);
    std::vector<int> expected_result{1, 3, 4, 2};
    EXPECT_EQ(expected_result, boundary_of_binary_tree_optimal(tree));
}
