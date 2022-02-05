#include <iostream>
#include "./binary_search_tree/binary_search_tree.h"
#include "./linked_lists/singly_linked_list.h"
#include "stacks/stack_linked_list_based.h"
#include "stacks/stack_array_based.h"
int main()
{
	StackAB<int, 3> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	std::cout << stack.pop() <<std::endl;
	std::cout << stack.top() <<std::endl;
	std::cout << stack.pop() <<std::endl;
	std::cout << stack.pop() <<std::endl;
	//std::cout << stack.top() <<std::endl;
	return 0;
}

