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
	tree.insert(4);
	tree.insert(10);

	tree.print_inorder_traversal();
}

