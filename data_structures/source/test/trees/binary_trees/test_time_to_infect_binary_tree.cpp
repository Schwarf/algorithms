//
// Created by andreas on 10.01.24.
//
#include "setup_binary_tree.h"
#include "trees/binary_trees/time_to_infect_binary_tree.h"

TEST_F(SetupBinaryTree, TestInfectionTree1)
{
	auto tree = SetupBinaryTree::infected_tree1();
	constexpr int start_value{3};
	constexpr int expected_result{4};
	EXPECT_EQ(time_to_infect_binary_tree(tree, start_value), expected_result);
}

TEST_F(SetupBinaryTree, TestInfectionTree2)
{
	auto tree = SetupBinaryTree::infected_tree1();
	constexpr int start_value{5};
	constexpr int expected_result{3};
	EXPECT_EQ(time_to_infect_binary_tree(tree, start_value), expected_result);
}

TEST_F(SetupBinaryTree, TestInfectionTree3)
{
	auto tree = SetupBinaryTree::infected_tree1();
	constexpr int start_value{9};
	constexpr int expected_result{5};
	EXPECT_EQ(time_to_infect_binary_tree(tree, start_value), expected_result);
}

TEST_F(SetupBinaryTree, TestInfectionTree4)
{
	auto tree = SetupBinaryTree::infected_tree1();
	constexpr int start_value{1};
	constexpr int expected_result{3};
	EXPECT_EQ(time_to_infect_binary_tree(tree, start_value), expected_result);
}


TEST_F(SetupBinaryTree, TestInfectionTree5)
{
	auto tree = SetupBinaryTree::infected_tree2();
	constexpr int start_value{8};
	constexpr int expected_result{6};
	EXPECT_EQ(time_to_infect_binary_tree(tree, start_value), expected_result);
}

TEST_F(SetupBinaryTree, TestInfectionTree6)
{
	auto tree = SetupBinaryTree::infected_tree2();
	constexpr int start_value{1};
	constexpr int expected_result{3};
	EXPECT_EQ(time_to_infect_binary_tree(tree, start_value), expected_result);
}