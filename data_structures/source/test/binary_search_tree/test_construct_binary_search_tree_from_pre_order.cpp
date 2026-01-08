//
// Created by andreas on 08.01.26.
//
#include "gtest/gtest.h"
#include "../../binary_search_tree/construct_binary_search_tree_from_pre_order.h"
#include "test_helper.h"

TEST(ConstructFromPreOrder, EmptyVectorReturnsNull) {
    std::vector<int> pre{};
    auto* root = construct_from_pre_order(pre);
    EXPECT_EQ(root, nullptr);
    delete_tree(root);
}

TEST(ConstructFromPreOrder, SingleElement) {
    std::vector<int> pre{42};
    auto* root = construct_from_pre_order(pre);
    EXPECT_EQ(root->value, 42);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}

TEST(ConstructFromPreOrder, IncreasingSequenceCreatesRightSkew) {
    std::vector<int> pre{1,2,3,4,5};
    auto* root = construct_from_pre_order(pre);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}


TEST(ConstructFromPreOrder, DecreasingSequenceCreatesLeftSkew) {
    std::vector<int> pre{5,4,3,2,1};
    auto* root = construct_from_pre_order(pre);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}

TEST(ConstructFromPreOrder, TypicalMixedShapeMatchesPreOrderRoundtrip) {
    // A common textbook preorder for a BST
    std::vector<int> pre{10, 5, 1, 7, 40, 50};
    auto* root = construct_from_pre_order(pre);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}

TEST(ConstructFromPreOrder, DuplicatesGoToRight_SubtreePolicy) {
    // Your implementation uses "< lower || >= upper" => duplicates belong to the RIGHT subtree.
    std::vector<int> pre{2, 0, 1, 4, 3, 3};
    auto* root = construct_from_pre_order(pre);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}

TEST(ConstructFromPreOrder, AllElementsSameValue_BecomesRightChain) {
    std::vector<int> pre{7,7,7,7};
    auto* root = construct_from_pre_order(pre);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}

TEST(ConstructFromPreOrder, HandlesExtremeValues_Int) {
    using T = int;
    const T mn = std::numeric_limits<T>::min();
    const T mx = std::numeric_limits<T>::max();

    // Valid preorder under dup-right policy
    std::vector<T> pre{0, mn, mn, -1, mx, mx};
    auto* root = construct_from_pre_order(pre);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}

TEST(ConstructFromPreOrder, PrefixThatStopsEarly_WhenRemainingValuesDontFitBounds) {
    // This is NOT a valid preorder for a BST under dup-right policy because "1" cannot appear after "3" in right subtree of 2.
    // Your helper will stop consuming when values no longer fit bounds, leaving suffix unconsumed.
    std::vector<int> pre{2, 1, 3, 1};
    auto* root = construct_from_pre_order(pre);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}

TEST(ConstructFromPreOrder, FloatingPointValuesAndDuplicatesRight) {
    // Also checks that "< lower || >= upper" works for doubles in a typical scenario.
    std::vector<double> pre{2.0, 1.0, 1.0, 1.5, 3.0, 3.0};
    auto* root = construct_from_pre_order(pre);
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    delete_tree(root);
}
