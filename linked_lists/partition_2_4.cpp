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
};

template<typename T>
void partition(Node<T> *head, T value)
{
	if(head == nullptr || head->next == nullptr)
		return;

	auto value_node = head;
	auto end_node = head;
	while (end_node->next != nullptr) {
		end_node = end_node->next;
	}
	while (value_node->value != value) {
		value_node = value_node->next;
	}
	if (value_node->next == nullptr)
		return;

	if(head->value == value)
	{
		auto node = head->next;
		while(node->next !=nullptr)
		{
			if(node->value < value) {
				auto new_head = new Node<int>(value);
				new_head->next = head;
				head = new_head;
			}
			node = node->next;
		}
	}
	auto start = head->next;
	Node<int>* start_prev = nullptr;
	while (start != value_node) {
		if (start->value > value) {
			auto new_end_node = new Node<int>(start->value);
			end_node->next = new_end_node;
			end_node = new_end_node;
			end_node->next = nullptr;
			if(start_prev == nullptr) {
				start_prev = start->next;
			}
			start_prev->next = start->next;
			delete start;
			start = start_prev->next;

		}
		else {
			start_prev = start;
			start = start->next;
		}

	}

}

int main()
{
	auto single = LinkedList<int>();
	single.push_back(7);
	single.push_back(6);
	single.push_back(6);
	single.push_back(5);
	single.push_back(1);
	single.push_back(2);
	single.push_back(3);
	single.print_list();
	partition<int>(single.head(), 5);
	single.print_list();


	return 0;
}