//
// Created by andreas on 09.01.24.
//
#include "gtest/gtest.h"
#include "./../count_unique_binary_search_trees.h"

TEST(TestCountUniqueBinarySearchTrees, one_recursive) {
    constexpr int n{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, count_unique_BST_recursive(n));
}

TEST(TestCountUniqueBinarySearchTrees, three_recursive) {
    constexpr int n{3};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_unique_BST_recursive(n));
}

TEST(TestCountUniqueBinarySearchTrees, ten_recursive) {
    constexpr int n{10};
    constexpr int expected_result{16796};
    EXPECT_EQ(expected_result, count_unique_BST_recursive(n));
}

TEST(TestCountUniqueBinarySearchTrees, nineteen_recursive) {
    constexpr int n{19};
    constexpr int expected_result{1767263190};
    EXPECT_EQ(expected_result, count_unique_BST_recursive(n));
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
TEST(TestCountUniqueBinarySearchTrees, one_top_down) {
    constexpr int n{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, count_unique_BST_top_down(n));
}

TEST(TestCountUniqueBinarySearchTrees, three_top_down) {
    constexpr int n{3};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_unique_BST_top_down(n));
}

TEST(TestCountUniqueBinarySearchTrees, ten_top_down) {
    constexpr int n{10};
    constexpr int expected_result{16796};
    EXPECT_EQ(expected_result, count_unique_BST_top_down(n));
}

TEST(TestCountUniqueBinarySearchTrees, nineteen_top_down) {
    constexpr int n{19};
    constexpr int expected_result{1767263190};
    EXPECT_EQ(expected_result, count_unique_BST_top_down(n));
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
TEST(TestCountUniqueBinarySearchTrees, one_bottom_up) {
    constexpr int n{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, count_unique_BST_bottom_up(n));
}

TEST(TestCountUniqueBinarySearchTrees, three_bottom_up) {
    constexpr int n{3};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_unique_BST_bottom_up(n));
}

TEST(TestCountUniqueBinarySearchTrees, ten_bottom_up) {
    constexpr int n{10};
    constexpr int expected_result{16796};
    EXPECT_EQ(expected_result, count_unique_BST_bottom_up(n));
}

TEST(TestCountUniqueBinarySearchTrees, nineteen_bottom_up) {
    constexpr int n{19};
    constexpr int expected_result{1767263190};
    EXPECT_EQ(expected_result, count_unique_BST_bottom_up(n));
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

TEST(TestCountUniqueBinarySearchTrees, one_bottom_up_other) {
    constexpr int n{1};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, count_unique_BST_bottom_up_other_catalan_formula(n));
}

TEST(TestCountUniqueBinarySearchTrees, three_bottom_up_other) {
    constexpr int n{3};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, count_unique_BST_bottom_up_other_catalan_formula(n));
}

TEST(TestCountUniqueBinarySearchTrees, ten_bottom_up_other) {
    constexpr int n{10};
    constexpr int expected_result{16796};
    EXPECT_EQ(expected_result, count_unique_BST_bottom_up_other_catalan_formula(n));
}


