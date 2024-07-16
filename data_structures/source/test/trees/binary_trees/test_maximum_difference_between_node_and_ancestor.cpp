//
// Created by andreas on 10.12.22.
//
#include "gtest/gtest.h"
#include "trees/binary_trees/tree_node.h"
#include "trees/binary_trees/maximum_difference_between_node_and_ancestor.h"

class SetupTestTrees : public testing::Test {
public:
    SetupTestTrees() = default;

protected:
    static TreeNode<int> *first_tree_root() {
        auto root = new TreeNode<int>(8);
        root->left = new TreeNode<int>(3);
        root->right = new TreeNode<int>(10);
        root->left->left = new TreeNode<int>(1);
        root->left->right = new TreeNode<int>(6);
        root->left->right->left = new TreeNode<int>(4);
        root->left->right->right = new TreeNode<int>(7);
        root->right->right = new TreeNode<int>(14);
        root->right->right->left = new TreeNode<int>(13);
        return root;
    }

    const int result1{7};

    static TreeNode<int> *second_tree_root() {
        auto root = new TreeNode<int>(1);
        root->right = new TreeNode<int>(2);
        root->right->right = new TreeNode<int>(0);
        root->right->right->left = new TreeNode<int>(3);
        return root;
    }

    const int result2{3};

};


TEST_F(SetupTestTrees, first_tree_test_brute_force) {
    auto root = SetupTestTrees::first_tree_root();
    auto result = brute_force_solution(root);
    EXPECT_EQ(result, result1);
}

TEST_F(SetupTestTrees, first_tree_one_recursion) {
    auto root = SetupTestTrees::first_tree_root();
    auto result = one_recursion_solution(root);
    EXPECT_EQ(result, result1);
}


TEST_F(SetupTestTrees, second_tree_test_brute_force) {
    auto root = SetupTestTrees::second_tree_root();
    auto result = brute_force_solution(root);
    EXPECT_EQ(result, result2);
}

TEST_F(SetupTestTrees, second_tree_one_recursion) {
    auto root = SetupTestTrees::second_tree_root();
    auto result = one_recursion_solution(root);
    EXPECT_EQ(result, result2);
}