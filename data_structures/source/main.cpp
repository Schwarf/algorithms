#include <iostream>
#include <vector>
#include "binary_search_tree/binary_search_tree.h"


int main()
{
	auto tree = BinarySearchTree<int>();
	tree.insert(3);
	tree.insert(5);
	tree.insert(1);
	tree.insert(2);
	tree.insert(7);
	tree.insert(6);
	tree.insert(4);
	tree.insert(10);

	tree.print_inorder_traversal();
//	auto ordered = tree.write_to_vector_inorder();
	std::cout << "******************" << std::endl;
	tree.delete_node_with_value(5);
	tree.print_inorder_traversal();
}

