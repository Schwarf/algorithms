//
// Created by andreas on 11.07.22.
//


#include "setup_binary_tree.h"
#include "trees/binary_trees/right_side_view.h"
#include <queue>

// ITERATIVE IMPLEMENTATION OF RIGHT-SIDE-VIEW
template<typename T>
std::vector<T> test_right_side_view(TreeNode<T> *root)
{
	if (!root)
		return {};

	std::vector<T> test_result;
	std::queue<TreeNode<T> *> queue{{root}};

	while (!queue.empty()) {
		const size_t size = queue.size();
		for (size_t i = 0; i < size; ++i) {
			TreeNode<T> *node = queue.front();
			queue.pop();
			if (i == size - 1)
				test_result.push_back(node->value);
			if (node->left)
				queue.push(node->left);
			if (node->right)
				queue.push(node->right);
		}
	}

	return test_result;
}


TEST_F(SetupBinaryTree, test_right_side_view)
{
	auto root = SetupBinaryTree::binary_tree_root();
	auto result = right_side_view(root);
	auto test_result = test_right_side_view(root);
	for (int index = 0; index < result.size(); ++index) {
		EXPECT_EQ(result[index], test_result[index]);
	}
}


