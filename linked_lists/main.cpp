#include <iostream>
#include "revert_linked_list.h"
#include <vector>
#include <algorithm>
int main()
{
	std::vector<int> input{1, 2, 3, 4, 5, 6};
	auto head = new Node<int>(input[0]);
	auto node = head;
	for (int i = 1; i < input.size(); ++i) {
		node->next = new Node<int>(input[i]);
		node = node->next;
	}

	std::reverse(input.begin(), input.end());
	head = revert_linked_list_recursive(head);
	for (int i = 0; i < input.size(); ++i) {
		std::cout << head->value << ", " << input[i] << std::endl;
		head = head->next;
	}

	return 0;
}
