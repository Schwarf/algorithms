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

	Node<T> *head()
	{
		return head_;
	}

	void partition(T value)
	{
		auto node = head_;
		while (node->value != value) {
			node = node->next;
		}
		auto value_node = node;
		while (node->next != nullptr) {
			node = node->next;
		}
		auto end_node = node;
		node = head_;
		Node<int> *prev_node = nullptr;
		while (node != value_node) {
			if (node->value > value) {
				auto new_end_node = new Node<int>(node->value);
				end_node->next = new_end_node;
				end_node = new_end_node;
				if (node == head_) {
					node = node->next;
					delete head_;
					head_ = node;
				}
				else {
					auto help = node;
					prev_node->next = node->next;
					node = node->next;
					delete help;
				}

			}
			else {
				prev_node = node;
				node = node->next;
			}

		}
	}

};

int main()
{
	auto single = LinkedList<int>();
	single.push_back(7);
	single.push_back(2);
	single.push_back(6);
	single.push_back(6);
	single.push_back(5);
	single.push_back(1);
	single.push_back(2);
	single.push_back(3);
	single.print_list();
	single.partition(5);
	single.print_list();


	return 0;
}