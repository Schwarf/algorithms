#include <iostream>
#include "./binary_search_tree/binary_search_tree.h"
#include "./linked_lists/singly_linked_list.h"
#include "stacks_and_queues/stack_linked_list_based.h"
#include "stacks_and_queues/stack_array_based.h"
#include "stacks_and_queues/queue_array_based.h"
#include "heaps/binary_heap.h"
#include "heaps/k_ary_heap.h"
#include <vector>
#include <algorithm>
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

	QueueAB<int, 3> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	std::cout << "Queue \n" ;

	std::cout << queue.dequeue() <<std::endl;
	std::cout << queue.dequeue() <<std::endl;
	std::cout << queue.dequeue() <<std::endl;

	auto heap = new BinaryHeap<int, 8>();
	heap->insert(1);
	heap->insert(2);
	heap->insert(3);
	heap->insert(4);
	heap->insert(5);
	heap->insert(6);
	heap->insert(7);
	heap->get_maximum();
	heap->print_array();
	heap->insert(8);
	heap->get_maximum();
	heap->print_array();
	std::vector<int> v{1,2,3,4,5,6,7};
	std::make_heap(v.begin(), v.end());
	for(const auto & element: v)
	{
		std::cout <<" std::heap = "  << element << "\n";
	}

	return 0;
}

