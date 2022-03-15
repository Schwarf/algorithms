//
// Created by andreas on 15.03.22.
//

#include <iostream>

template<class T>
struct Node
{
	explicit Node(T val)
	{
		value = val;
	}
	T value;
	Node *next;
};

template<class T>
class LinkedList
{
	Node<T> *head_;

public:
	LinkedList()
		:
		head_(nullptr)
	{}
	Node<T> *head()
	{
		return head_;
	}

	void push_back(T value)
	{
		if (head_ == nullptr) {
			head_ = new Node<T>(value);
			return;
		}
		auto node = head_;
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new Node<T>(value);
	}
	void print_list()
	{
		auto node = head_;
		while (node->next != nullptr) {
			std::cout << node->value << ", ";
			node = node->next;
		}
		std::cout << node->value << std::endl;
	}

};

template<typename T>
void delete_middle_element(Node<T> *node)
{
	if(node->next ==nullptr)
		return;
	auto prev = node;
	while(node->next != nullptr)
	{
		node->value = node->next->value;
		prev = node;
		node = node->next;
	}
	delete node;
	prev->next = nullptr;
}

int main()
{
	auto single = LinkedList<int>();
	single.push_back(1);
	single.push_back(2);
	single.push_back(3);
	single.push_back(4);
	single.push_back(5);
	single.push_back(6);
	single.push_back(7);
	single.print_list();
	auto node = single.head()->next->next->next->next->next;
	delete_middle_element<int>(node);
	single.print_list();
	node = single.head()->next;
	delete_middle_element<int>(node);
	single.print_list();
}
