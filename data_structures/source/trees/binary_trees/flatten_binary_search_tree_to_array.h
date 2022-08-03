//
// Created by andreas on 03.08.22.
//

#ifndef FLATTEN_BINARY_SEARCH_TREE_TO_ARRAY_H
#define FLATTEN_BINARY_SEARCH_TREE_TO_ARRAY_H
#include "tree_node.h"
#include <vector>

template<typename T>
int flatten_binary_search_tree(TreeNode<T> * root, std::vector<int> & result, int index)
{
	if(!root)
		return index;
	index = flatten_binary_search_tree(root->left, result, index);
	if(index > result.size()-1)
		result.resize(index);
	result[index] = root->value;
	index = flatten_binary_search_tree(root->right, result, index+1);
	return index;
}

#endif //FLATTEN_BINARY_SEARCH_TREE_TO_ARRAY_H
