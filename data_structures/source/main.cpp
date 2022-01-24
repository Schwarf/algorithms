#include <iostream>
#include "./binary_search_tree/binary_search_tree.h"
#include "./linked_lists/single_linked_list.h"
int main()
{
	SingleLinkedList<int> list;
	list.add_at_head(1);
	list.add_at_head(2);
	list.add_at_head(3);
	list.add_at_index(4, 0);
	list.add_at_index(5, 0);
	list.add_at_tail(0);
	list.add_at_index(-1, 5);
	int value;
	for(size_t index =0 ; index < list.size(); ++index)
	{
		list.get(index, value);
		std::cout << value << "  ";
	}
	std::cout << std::endl;
	return 0;
}
