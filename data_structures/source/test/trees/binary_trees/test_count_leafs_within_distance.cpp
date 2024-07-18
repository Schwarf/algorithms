//
// Created by andreas on 18.07.24.
//
#include "gtest/gtest.h"
#include "trees/binary_trees/count_leafs_within_distance.h"
#include "setup_binary_tree.h"

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple1) {
    auto tree = infected_tree2();
    constexpr int distance{2};
    constexpr int expected_result{4};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple2) {
    auto tree = infected_tree2();
    constexpr int distance{1};
    constexpr int expected_result{};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple3) {
    auto tree = infected_tree2();
    constexpr int distance{4};
    constexpr int expected_result{12};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple4) {
    auto tree = infected_tree2();
    constexpr int distance{5};
    constexpr int expected_result{12};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple5) {
    auto tree = infected_tree2();
    constexpr int distance{6};
    constexpr int expected_result{28};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple6) {
    auto tree = medium_tree_with_subtree_duplicates2();
    constexpr int distance{3};
    constexpr int expected_result{0};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple7) {
    auto tree = medium_tree_with_subtree_duplicates2();
    constexpr int distance{4};
    constexpr int expected_result{1};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple8) {
    auto tree = palindromic_tree1();
    constexpr int distance{3};
    constexpr int expected_result{1};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}

TEST_F(SetupBinaryTree, TestCountLeafsWithinDistance_simple9) {
    auto tree = palindromic_tree1();
    constexpr int distance{4};
    constexpr int expected_result{3};
    EXPECT_EQ(count_leafs_within_distance(tree, distance), expected_result);
}
