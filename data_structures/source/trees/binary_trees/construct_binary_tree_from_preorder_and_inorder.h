//
// Created by andreas on 14.07.22.
//

#ifndef CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_H
#define CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_H
#include <vector>
#include "tree_node.h"
#include <unordered_map>
/*

Preorder traversal follows Root -> Left -> Right, therefore, given the preorder array preorder, we have easy access
to the root which is preorder[0].
Inorder traversal follows Left -> Root -> Right, therefore if we know the position of Root, we can recursively split
the entire array into two subtrees.
Design a recursion function: it will set the first element of preorder as the root, and then construct the entire tree.
To find the left and right subtrees, it will look for the root
in inorder, so that everything on the left should be the left subtree, and everything on the right should be the
right subtree. Both subtrees can be constructed by making another recursion call.

While recursively construct the subtrees, we should choose the next element in preorder to
initialize as the new roots. This is because the current one has already been initialized to a parent node for the
subtrees.

Algorithm

- Build a hashmap to record the relation of value -> index for inorder, so that we can find the position of root in constant time.
- Initialize an integer variable preorderIndex to keep track of the element that will be used to construct the root.
- Implement the recursion function arrayToTree which takes a range of inorder and returns the constructed binary tree:
	- if the range is empty, return null;
	- initialize the root with preorder[preorderIndex] and then increment preorderIndex;
	- recursively use the left and right portions of inorder to construct the left and right subtrees.
- Simply call the recursion function with the entire range of inorder.
*/

template<typename T>
TreeNode<T> *_construct_tree(std::vector<T> &preorder,
							 int left,
							 int right,
							 int &pre_order_index,
							 std::unordered_map<T, int> &inorder_value_to_index)
{
	if (left > right)
		return nullptr;
	int root_value = preorder[pre_order_index++];
	auto root = new TreeNode<T>(root_value);
	root->left = _construct_tree(preorder,
								 left,
								 inorder_value_to_index[root_value] - 1,
								 pre_order_index,
								 inorder_value_to_index);
	root->right = _construct_tree(preorder,
								  inorder_value_to_index[root_value] + 1,
								  right,
								  pre_order_index,
								  inorder_value_to_index);
	return root;
}

template<typename T>
TreeNode<T> *construct_from_preorder_and_inorder(std::vector<T> &pre_order, std::vector<T> &in_order)
{
	std::unordered_map<T, int> inorder_value_to_index;
	int pre_order_index{};
	for (int i = 0; i < in_order.size(); ++i)
		inorder_value_to_index[in_order[i]] = i;

	return _construct_tree(pre_order, 0, pre_order.size() - 1, pre_order_index, inorder_value_to_index);

}

#endif //CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_H
