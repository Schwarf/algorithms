//
// Created by andreas on 02.04.22.
//

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
	Node *next = nullptr;
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

	void push_back_and_close_loop_at_position(size_t position, T node_value)
	{
		auto node = head_;
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new Node<T>(node_value);
		size_t counter{1};
		auto start_loop = head_;
		while(counter != position)
		{
			start_loop = start_loop->next;
			counter++;
		}
		node->next->next = start_loop;
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

	LinkedList<T> reverse()
	{
		LinkedList<T> result;
		auto current = head_;
		while (current != nullptr) {
			result.push_front(current->value);
			current = current->next;
		}
		return result;
	}

};

template <class T>
Node<T> * has_loop (LinkedList<T> list)
{
	if (list.head() == nullptr)
		return nullptr;
	if (list.head()->next == list.head())
		return list.head();

	auto runner1 = list.head();
	auto runner2 = runner1;
	while (runner2->next != nullptr) {
		runner1 = runner1->next;
		runner2 = runner2->next;
		if (runner2->next != nullptr)
			runner2 = runner2->next;
		else
			return nullptr;
		if (runner2 == runner1) {
			break;
		}
	}

	runner1 = list.head();
	while (runner1 != runner2)
	{
		runner1 = runner1->next;
		runner2 = runner2->next;
	}

	return runner1;
}


int main()
{
	auto list = LinkedList<int>();
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back_and_close_loop_at_position(2, 6);

	std::cout << has_loop(list)->value << std:: endl;

	return 0;
}



