#include <iostream>
#include <vector>
#include "binary_search_tree/avl_tree.h"
#include "binary_trees/find_two_sum_in_binary_tree.h"
#include "binary_trees/tree_node.h"
int main()
{
	auto avl_tree = AVLTree<int>();
	avl_tree.insert(3);
	avl_tree.insert(5);
	avl_tree.insert(1);
	avl_tree.insert(2);
	avl_tree.insert(7);
	avl_tree.insert(6);
	avl_tree.insert(4);
	avl_tree.insert(10);

	avl_tree.print_inorder_traversal();
//	auto ordered = avl_tree.get_vector_inorder();
	std::cout << "******************" << std::endl;
	avl_tree.delete_node_with_value(5);
	avl_tree.delete_node_with_value(10);
	avl_tree.print_inorder_traversal();

	auto root = new TreeNode<int>(5);
	root->left = new TreeNode<int>(2);
	root->right = new TreeNode<int>(8);
	root->left->left = new TreeNode<int>(1);
	root->left->right = new TreeNode<int>(3);
	std::cout << "******************" << std::endl;
	std::cout << find_target_two_sum(root, 10) << std::endl;
	std::cout << find_target_two_sum(root, 27) << std::endl;
	std::cout << find_target_two_sum(root, 2) << std::endl;
}

