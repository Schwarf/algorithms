//
// Created by andreas on 20.03.22.
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
	void push_front(T value)
	{
		if (head_ == nullptr) {
			head_ = new Node<T>(value);
			return;
		}
		auto new_node = new Node<T>(value);
		new_node->next = head_;
		head_ = new_node;
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
	LinkedList<T> add(LinkedList<T> &number1, LinkedList<T> number2)
	{
		LinkedList<T> result;
		auto node1 = number1.head_;
		auto node2 = number2.head_;
		if(node1 == nullptr && node2 == nullptr)
			return result;

		if(node1 == nullptr)
			return number2;
		if(node2 == nullptr)
			return number2;

		T transfer{};
		while (node1 != nullptr && node2 != nullptr)
		{
				T value = (node1->value + node2->value + transfer) % 10;
				transfer = (node1->value + node2->value + transfer) / 10;
				result.push_back(value);
				node1 = node1->next;
				node2 = node2->next;
		}
		while(node2 !=nullptr)
		{
			T value = (node2->value + transfer) % 10;
			transfer = (node2->value + transfer) / 10;
			result.push_back(value);
			node2 = node2->next;

		}
		while(node1 !=nullptr)
		{
			T value = (node1->value + transfer) % 10;
			transfer = (node1->value + transfer) / 10;
			result.push_back(value);
			node1 = node1->next;
		}

		if (transfer)
			result.push_back(transfer);
		return result;
	}



};

int main()
{
	auto number1 = LinkedList<int>();
	auto number2 = LinkedList<int>();
	number1.push_back(4);
	number1.push_back(3);

	number2.push_back(6);
	number2.push_back(2);
	number2.push_back(8);

	number1.print_list();
	number2.print_list();

	auto test = number1.add(number1, number2);
	test.print_list();
	return 0;
}