//
// Created by andreas on 04.10.22.
//
#include "basics.h"

template <typename T>
int depth_first_search_height(Node<T>* node)
{
		if(node==nullptr)
			return 0;
		auto left_height = depth_first_search_height(node->children[0]);
		if(left_height ==-1)
			return -1;
		auto right_height = depth_first_search_height(node->children[1]);
		if(right_height ==-1)
			return -1;
		if(std::abs(left_height - right_height) > 1)
			return -1;
		return 1 + std::max(left_height, right_height);
};
template<typename T>
bool is_tree_balanced(Node<T>* root)
{
	if(!root)
		return true;
	return depth_first_search_height(root) != -1;
}


int main()
{
	auto root = generate_balanced_binary_tree_with_random_values<int>(0,10);
	std::cout << is_tree_balanced(root) << std::endl;
	return 0;
}
