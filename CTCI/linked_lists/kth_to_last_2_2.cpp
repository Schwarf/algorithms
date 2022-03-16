//
// Created by andreas on 15.03.22.
//
#include <iostream>
#include <cassert>
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
	T kth_to_last(size_t k)
	{
		size_t counter{};
		size_t size{};
		if (head_ == nullptr)
			throw std::out_of_range("Linked list is empty!");
		auto node = head_;
		while (node != nullptr) {
			counter++;
			node = node->next;
		}
		size = counter;
		if (size < k)
			throw std::out_of_range("k is larger than list size");

		counter = 0;
		node = head_;
		while ((size - counter) != k) {
			counter++;
			node = node->next;
		}
		return node->value;
	}
};

template<typename T>
Node<T> *kth_to_last_recursive(Node<T> *head, int k, int &i)
{
	if (head == nullptr)
		return nullptr;

	Node<T> *node = kth_to_last_recursive<T>(head->next, k, i);
	i++;
	if (i == k)
		return head;
	return node;
}

template<typename T>
Node<T> *kth_to_last_recursive(Node<T> *head, int k)
{
	int i = 0;
	return kth_to_last_recursive(head, k, i);
}

int main()
{
	auto single = LinkedList<int>();
	single.push_back(1);
	single.push_back(2);
	single.push_back(13);
	single.push_back(2);
	single.push_back(12);
	single.push_back(13);
	single.push_back(178);
	single.print_list();
	std::cout << single.kth_to_last(2) << std::endl;
	std::cout << kth_to_last_recursive(single.head(), 2)->value << std::endl;
	assert(single.kth_to_last(2)==kth_to_last_recursive(single.head(), 2)->value);
	assert(single.kth_to_last(1)==kth_to_last_recursive(single.head(), 1)->value);
	assert(single.kth_to_last(4)==kth_to_last_recursive(single.head(), 4)->value);
	assert(single.kth_to_last(7)==kth_to_last_recursive(single.head(), 7)->value);
}
