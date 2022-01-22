#include <iostream>
#include "./binary_search_tree/binary_search_tree.h"

int main()
{
	BinarySearchTree<int, double> bst;
	bst.add(1, 1.0);
	bst.add(2, 2.0);
	auto value = bst.get(1);
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
