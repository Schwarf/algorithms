//
// Created by andreas on 30.09.22.
//

#include "basics.h"
#include <queue>
#include <vector>

// We use one Node<T> implementation for:
// Binary tree: 2 children, left = children[0], right = children[1]
// Linked list: 1 child, next = children[0]
template <typename T>
std::vector<Node<T>* > build_linked_lists_from_binary_tree(Node<T>* binary_tree_root)
{
	auto root = binary_tree_root;
	if(!root)
		return {};
	std::queue<Node<T>*> help;
	help.push(root);
	help.push(nullptr);
	std::vector<Node<T>*> result;
	Node<T>* node;
	Node<T>* list_head = nullptr;
	Node<T>* list_tail = list_head;
	while(!help.empty())
	{
		if(help.front())
		{
			while(help.front()) {
				node = help.front();
				help.pop();
				auto left = node->children[0];
				auto right = node->children[1];
				if (!list_head) {
					list_head = new Node<T>(node->value);
					list_tail = list_head;
				}
				else {
					list_tail->children.push_back(new Node<T>(node->value));
					list_tail = list_tail->children[0];
				}
				help.push(left);
				help.push(right);
			}
			help.push(nullptr);
		}
		else
		{
			help.pop();
			result.push_back(list_head);
			list_head = nullptr;
		}
	}
	return result;
}

int main()
{
	int number_of_nodes{9};
	auto root = generate_balanced_binary_tree_with_random_values<int>(0, number_of_nodes);
	auto result = build_linked_lists_from_binary_tree(root);
	auto x = 1;
}