//
// Created by andreas on 29.02.24.
//

#include "setup_binary_tree.h"
#include "trees/binary_trees/is_tree_even_odd_tree.h"

TEST_F(SetupBinaryTree, IsEvenOddTreeSimple1) {
    auto tree = even_odd_tree1();
    EXPECT_TRUE(is_even_odd_tree(tree));
}

TEST_F(SetupBinaryTree, IsEvenOddTreeSimple2) {
    auto tree = new TreeNode<short int>(1);
    EXPECT_TRUE(is_even_odd_tree(tree));
}

TEST_F(SetupBinaryTree, IsEvenOddTreeSimple3) {
    auto tree = new TreeNode<short int>(2);
    EXPECT_FALSE(is_even_odd_tree(tree));
}

TEST_F(SetupBinaryTree, IsEvenOddTreeSimple4) {
    auto tree = infected_tree1();
    EXPECT_FALSE(is_even_odd_tree(tree));
}

TEST_F(SetupBinaryTree, IsEvenOddTreeSimple5) {
    auto tree = even_odd_tree2();
    EXPECT_TRUE(is_even_odd_tree(tree));
}
