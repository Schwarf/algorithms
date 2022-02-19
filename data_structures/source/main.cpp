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
#include "hash_functions/division_hashing.h"
#include "hash_functions/multiplication_hashing.h"
#include "hash_functions/testing_hash_functions/test_hash_functions.h"
int main()
{
	constexpr size_t hash_table_size = 4*4*4*4 * 4*4*4*4; // 2**16
	auto division_hashing = DivisionHashing<hash_table_size, 256>();
	auto test = TestHashFunctions<hash_table_size>();
	test.test(division_hashing);
	auto multi_hashing = MultiplicationHashing<64, 14>();
	division_hashing.hash(100012);
	std::cout << multi_hashing.hash(123456) << std::endl;
	StackAB<int, 3> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	std::cout << stack.pop() << std::endl;
	std::cout << stack.top() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	//std::cout << stack.top() <<std::endl;

	QueueAB<int, 3> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	std::cout << "Queue \n";

	std::cout << queue.dequeue() << std::endl;
	std::cout << queue.dequeue() << std::endl;
	std::cout << queue.dequeue() << std::endl;

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
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
	std::make_heap(v.begin(), v.end());
	for (const auto &element: v) {
		std::cout << " std::heap = " << element << "\n";
	}

	return 0;
}

