//
// Created by andreas on 19.03.23.
//

#include "setup_singly_linked_lists.h"
#include "linked_lists/partition_linked_list_for_element.h"

TEST_F(SetupSinglyLinkedLists, partition_element1)
{
	std::vector<int> input{2, 8, 7, 9, 5, 1, 2, 3, 4, 9};
	auto head = get_single_list_from_vector(input);
	auto node = head;
	size_t size{};
	while (node) {
		size++;
		node = node->next;
	}
	EXPECT_EQ(size, input.size());
	int partition_element{5};
	head = partition_linked_list_for_element(head, partition_element);
	node = head;
	size = 0;
	while (node) {
		size++;
		node = node->next;
	}
	EXPECT_EQ(size, input.size());
	node = head;
	while (node->value != partition_element) {
		EXPECT_TRUE(node->value < partition_element);
		node = node->next;
	}
	while (node) {
		EXPECT_TRUE(node->value >= partition_element);
		node = node->next;
	}
}
