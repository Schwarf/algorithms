//
// Created by andreas on 10.12.22.
//

#ifndef MAXIMUM_PRODUCT_OF_SPLITTED_TREE_H
#define MAXIMUM_PRODUCT_OF_SPLITTED_TREE_H
#include "tree_node.h"
#include <algorithm>

template<typename T>
void get_total_sum(TreeNode<T> *node, T &total_sum)
{
	if (!node)
		return;
	total_sum += node->value;
	get_total_sum(node->left, total_sum);
	get_total_sum(node->right, total_sum);
}
template<typename T>
T compute_maximum_product(TreeNode<T> *node, const T &total_sum, T &maximum_product)
{
	if (!node)
		return 0;
	T sub_sum_left = compute_maximum_product(node->left, total_sum, maximum_product);
	T sub_sum_right = compute_maximum_product(node->right, total_sum, maximum_product);
	T left_product = (total_sum - sub_sum_left) * sub_sum_left;
	T right_product = (total_sum - sub_sum_right) * sub_sum_right;
	maximum_product = std::max({maximum_product, left_product, right_product});
	return sub_sum_left + sub_sum_right + node->value;
}

template<typename T>
T get_maximum_product(TreeNode<T> *root)
{
	T total_sum{};
	T result{};
	get_total_sum(root, total_sum);

}


#endif //MAXIMUM_PRODUCT_OF_SPLITTED_TREE_H
