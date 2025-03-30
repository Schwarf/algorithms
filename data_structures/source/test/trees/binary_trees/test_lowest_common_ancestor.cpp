//
// Created by andreas on 16.07.24.
//
#include "gtest/gtest.h"
#include "setup_binary_tree.h"
#include "trees/binary_trees/lowest_common_ancestor.h"


TEST_F(SetupBinaryTree, LowestCommomAncestor1)
{
    auto tree = even_odd_tree1();
    constexpr int value1{2};
    constexpr int value2{12};
    auto expected_result = tree;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestor2)
{
    auto tree = even_odd_tree1();
    constexpr int value1{8};
    constexpr int value2{12};
    auto expected_result = tree->left->left;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestor3)
{
    auto tree = even_odd_tree1();
    constexpr int value1{21};
    constexpr int value2{22};
    auto expected_result = nullptr;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestor4)
{
    auto tree = infected_tree2();
    constexpr int value1{7};
    constexpr int value2{15};
    auto expected_result = tree->right->right;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor(tree, value1, value2));
}


TEST_F(SetupBinaryTree, LowestCommomAncestor5)
{
    auto tree = infected_tree2();
    constexpr int value1{2};
    constexpr int value2{8};
    auto expected_result = tree->left;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestor6_FoundOnlyOne)
{
    auto tree = infected_tree2();
    constexpr int value1{2};
    constexpr int value2{1278};
    auto expected_result = nullptr;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestor7_FoundOnlyOne)
{
    auto tree = infected_tree2();
    constexpr int value1{131};
    constexpr int value2{11};
    auto expected_result = nullptr;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor(tree, value1, value2));
}


TEST_F(SetupBinaryTree, LowestCommomAncestorIterative1)
{
    auto tree = even_odd_tree1();
    constexpr int value1{2};
    constexpr int value2{12};
    auto expected_result = tree;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor_iterative(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestorIterative2)
{
    auto tree = even_odd_tree1();
    constexpr int value1{8};
    constexpr int value2{12};
    auto expected_result = tree->left->left;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor_iterative(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor_iterative(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestorIterative3)
{
    auto tree = even_odd_tree1();
    constexpr int value1{21};
    constexpr int value2{22};
    auto expected_result = nullptr;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor_iterative(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor_iterative(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestorIterative4)
{
    auto tree = infected_tree2();
    constexpr int value1{7};
    constexpr int value2{15};
    auto expected_result = tree->right->right;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor_iterative(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor_iterative(tree, value1, value2));
}


TEST_F(SetupBinaryTree, LowestCommomAncestorIterative5)
{
    auto tree = infected_tree2();
    constexpr int value1{2};
    constexpr int value2{8};
    auto expected_result = tree->left;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor_iterative(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor_iterative(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestorIterative6_FoundOnlyOne)
{
    auto tree = infected_tree2();
    constexpr int value1{2};
    constexpr int value2{1278};
    auto expected_result = nullptr;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor_iterative(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor_iterative(tree, value1, value2));
}

TEST_F(SetupBinaryTree, LowestCommomAncestorIterative7_FoundOnlyOne)
{
    auto tree = infected_tree2();
    constexpr int value1{131};
    constexpr int value2{11};
    auto expected_result = nullptr;
    EXPECT_EQ(expected_result, find_lowest_common_ancestor_iterative(tree, value1, value2));
    EXPECT_NE(tree, find_lowest_common_ancestor_iterative(tree, value1, value2));
}
