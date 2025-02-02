//
// Created by andreas on 02.02.25.
//
#include "trees/binary_trees/count_good_nodes.h"
#include "setup_binary_tree.h"

TEST_F(SetupBinaryTree, TestCountGoodNodesDFSRecursiveSimple1)
{
    auto tree = even_odd_tree2();
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, count_good_nodes_dfs_recursive(tree));
}

TEST_F(SetupBinaryTree, TestCountGoodNodesDFSRecursiveSimple2)
{
    auto tree = palindromic_tree2();
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, count_good_nodes_dfs_recursive(tree));
}

TEST_F(SetupBinaryTree, TestCountGoodNodesDFSRecursiveSimple3)
{
    auto tree = new TreeNode<short>(1);
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, count_good_nodes_dfs_recursive(tree));
}


TEST_F(SetupBinaryTree, TestCountGoodNodesDFSRecursiveSimple4)
{
    auto tree = even_odd_tree1();
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, count_good_nodes_dfs_recursive(tree));
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


