//
// Created by andreas on 15.03.23.
//

#ifndef SETUP_SINGLY_LINKED_LISTS_H
#define SETUP_SINGLY_LINKED_LISTS_H
#include "gtest/gtest.h"
#include <vector>
#include "linked_lists/node.h"

class SetupSinglyLinkedLists: public testing::Test
{
public:
	SetupSinglyLinkedLists() = default;
protected:
	template<typename T>
	Node<T> *get_single_list_from_vector(const std::vector<T> &input)
	{
		if (input.size() < 1)
			return nullptr;
		auto head = new Node<T>(input[0]);
		auto node = head;
		for (size_t i{1}; i < input.size(); ++i) {
			node->next = new Node<T>(input[i]);
			node = node->next;
		}
		return head;
	}

	template<typename T>
	NodePlusRP<T> *get_single_list_with_random_pointer_from_vector_and_value_pairs(const std::vector<T> &input,
																				   const std::unordered_map<T,
																											T> &from_to)
	{
		std::unordered_map<T, NodePlusRP<T> *> help;
		auto head = new NodePlusRP<T>(input[0]);
		auto node = head;
		help[input[0]] = node;

		for (size_t i{1}; i < input.size(); ++i) {
			node->next = new NodePlusRP<T>(input[i]);
			node = static_cast<NodePlusRP<int> *>(node->next);
			help[input[i]] = node;
		}
		for (const auto &[from, to]: from_to) {
			help[from]->random = help[to];
		}
		return head;
	}

	template<typename T>
	size_t get_size(Node<T> *head)
	{
		size_t size{};
		while (head) {
			size++;
			head = head->next;
		}
		return size;
	}

};
#endif //SETUP_SINGLY_LINKED_LISTS_H
