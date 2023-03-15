//
// Created by andreas on 28.02.23.
//

#include "gtest/gtest.h"
#include "trees/binary_trees/find_duplicate_subtrees.h"
#include "setup_binary_tree.h"


TEST_F(SetupBinaryTree, small_tree_with_duplicates)
{
	auto tree = small_tree_with_subtree_duplicates();
	auto result = find_duplicate_subtrees(tree);
	auto expected_result = std::vector<TreeNode<int> *>{new TreeNode<int>(2)};
	EXPECT_EQ(result.size(), expected_result.size());
	for (int i{}; i < result.size(); ++i) {
		EXPECT_EQ(result[i]->value, expected_result[i]->value);
	}

}

TEST_F(SetupBinaryTree, medium_tree_with_duplicates1)
{
	auto tree = medium_tree_with_subtree_duplicates1();
	auto result = find_duplicate_subtrees(tree);
	auto expected_result = std::vector<TreeNode<int> *>{new TreeNode<int>(4), new TreeNode<int>(2)};
	EXPECT_EQ(result.size(), expected_result.size());
	for (int i{}; i < result.size(); ++i)
		EXPECT_EQ(result[i]->value, expected_result[i]->value);
}

TEST_F(SetupBinaryTree, medium_tree_with_duplicates2)
{
	auto tree = medium_tree_with_subtree_duplicates2();
	auto result = find_duplicate_subtrees(tree);
	auto expected_result =
		std::vector<TreeNode<int> *>{new TreeNode<int>(3, new TreeNode<int>(2), nullptr), new TreeNode<int>(2)};
	EXPECT_EQ(result.size(), expected_result.size());
	for (int i{}; i < result.size(); ++i)
		EXPECT_EQ(result[i]->value, expected_result[i]->value);
}
