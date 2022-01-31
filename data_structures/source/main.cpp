#include <iostream>
#include "./binary_search_tree/binary_search_tree.h"
#include "./linked_lists/singly_linked_list.h"
int main()
{
	SingleLinkedList<int> list;
	list.push_at_front(1);
	list.push_at_front(2);
	list.push_at_front(3);
	list.push_at(0, 4);
	list.push_at(0, 5);
	list.push_back(0);
	list.push_at(5, -1);
	int value;
	for(size_t index =0 ; index < list.size(); ++index)
	{
		list.get(index, value);
		std::cout << value << "  ";
	}
	std::cout << std::endl;
	return 0;
}
