//
// Created by andreas on 14.07.22.
//

#ifndef CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_H
#define CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_H
#include <vector>
#include "tree_node.h"
#include <unordered_map>


template<typename T>
TreeNode<T> *_construct_tree(std::vector<T> &postorder,
							 int left,
							 int right,
							 int &post_order_index,
							 std::unordered_map<T, int> &inorder_value_to_index)
{
	if (left > right)
		return nullptr;
	int root_value = postorder[post_order_index--];
	auto root = new TreeNode<T>(root_value);
	root->right = _construct_tree(postorder,
								  inorder_value_to_index[root_value] + 1,
								  right,
								  post_order_index,
								  inorder_value_to_index);
	root->left = _construct_tree(postorder,
								 left,
								 inorder_value_to_index[root_value] - 1,
								 post_order_index,
								 inorder_value_to_index);
	return root;
}

template<typename T>
TreeNode<T> *construct_from_inorder_and_postorder(std::vector<T> &post_order, std::vector<int> &in_order)
{
	std::unordered_map<T, int> inorder_value_to_index;
	int post_order_index = post_order.size() - 1;
	for (int i = 0; i < in_order.size(); ++i)
		inorder_value_to_index[in_order[i]] = i;

	return _construct_tree(post_order, 0, post_order.size() - 1, post_order_index, inorder_value_to_index);

}

#endif //CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_H
