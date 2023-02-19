//
// Created by andreas on 14.07.22.
//

#include "setup_binary_tree.h"
#include "./../../../trees/binary_trees/level_order_traversal.h"


TEST_F(SetupBinaryTree, test_level_order_traversal)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = level_order_traversal(root);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j)
			EXPECT_EQ(result[i][j], levelorder[i][j]);
	}

}
TEST_F(SetupBinaryTree, test_level_order_traversal_inverted)
{
	auto root = SetupBinaryTree::inverted_tree();
	auto result = level_order_traversal(root);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j)
			EXPECT_EQ(result[i][j], levelorder_inverted_tree[i][j]);
	}

}

TEST_F(SetupBinaryTree, test_level_order_traversal_small_tree)
{
	auto root = SetupBinaryTree::small_binary_tree_root();
	auto result = level_order_traversal(root);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j)
			EXPECT_EQ(result[i][j], levelorder_small_tree[i][j]);
	}

}

TEST_F(SetupBinaryTree, test_level_order_traversal_empty)
{
	auto root = nullptr;
	auto result = level_order_traversal<int>(root);
	EXPECT_TRUE(result.empty());

}


TEST_F(SetupBinaryTree, testconcise_level_order_traversal)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = concise_level_order_traversal(root);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j)
			EXPECT_EQ(result[i][j], levelorder[i][j]);
	}

}
TEST_F(SetupBinaryTree, testconcise_level_order_traversal_inverted)
{
	auto root = SetupBinaryTree::inverted_tree();
	auto result = concise_level_order_traversal(root);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j)
			EXPECT_EQ(result[i][j], levelorder_inverted_tree[i][j]);
	}

}

TEST_F(SetupBinaryTree, testconcise_level_order_traversal_small_tree)
{
	auto root = SetupBinaryTree::small_binary_tree_root();
	auto result = concise_level_order_traversal(root);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j)
			EXPECT_EQ(result[i][j], levelorder_small_tree[i][j]);
	}

}

TEST_F(SetupBinaryTree, testconcise_level_order_traversal_empty)
{
	auto root = nullptr;
	auto result = concise_level_order_traversal<int>(root);
	EXPECT_TRUE(result.empty());

}