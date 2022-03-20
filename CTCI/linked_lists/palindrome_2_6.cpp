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
bool is_palindrome(LinkedList<T> list)
{
	if(list.head() == nullptr || list.head()->next == nullptr)
		return true;
	auto reverse = list;
	auto reverse_node = reverse.reverse().head();
	auto node = list.head();
	while(node != reverse_node)
	{
		if(node->value != reverse_node->value)
			return false;
		node = node->next;
		reverse_node = reverse_node->next;
	}
	return true;

}


int main()
{
	auto list = LinkedList<int>();
	list.push_back(1);
	list.push_back(2);
	list.push_back(2);
	list.push_back(1);
	auto reverted = list.reverse();
	std::cout << is_palindrome<int>(reverted) << std:: endl;

	return 0;
}



