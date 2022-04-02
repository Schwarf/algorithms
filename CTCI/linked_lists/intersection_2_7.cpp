//
// Created by andreas on 02.04.22.
//
#include <vector>
#include <memory>
#include <iostream>

template<typename T>
struct Node
{
	explicit Node(T val)
	{
		value = val;
	}
	T value;
	Node *next = nullptr;
};

template<typename T>
class LinkedList
{
public:
	void push_back_node(Node<T> * node)
	{
		if(head_ == nullptr)
		{
			head_ = node;
			return;
		}
		auto current = head_;
		while(current-> next != nullptr)
		{
			current = current->next;
		}

		current->next = node;
		node->next = nullptr;

	}

	void push_front_node(Node<T> * node)
	{
		if(head_ == nullptr)
		{
			head_ = node;
			return;
		}
		node->next = head_;
		head_ = node;
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

private:
	Node<T> * head_ = nullptr;
};


Node<int>* do_linked_lists_intersect(Node<int> *head1, Node<int>* head2)
{
	size_t size1{};
	size_t size2{};
	auto current = head1;
	while (current->next != nullptr) {
		size1++;
		current = current->next;
	}
	auto tail1 = current;
	current = head2;
	while (current->next != nullptr) {
		size2++;
		current = current->next;
	}
	auto tail2 = current;

	if(tail1 != tail2) {
		std::cout << "No intersection" << std::endl;
		return nullptr;
	}
	if(size1 > size2)
		while(size1 > size2)
		{
			head1 = head1->next;
			size1--;
		}
	if(size2 > size1)
		while(size2 > size1)
		{
			head2 = head2->next;
			size2--;
		}
	while(head1 != head2)
	{
		head1 =head1->next;
		head2 =head2->next;
	}
	return head1;
}

int main()
{
	auto one_1 = new Node<int>(1);
	auto one_2 = new Node<int>(2);
	auto one_3 = new Node<int>(3);
	auto one_4 = new Node<int>(4);
	auto one_5 = new Node<int>(5);
	auto one = LinkedList<int>();
	one.push_back_node(one_1);
	one.push_back_node(one_2);
	one.push_back_node(one_3);
	one.push_back_node(one_4);
	one.push_back_node(one_5);

	auto two_1 = new Node<int>(1);
	auto two_2 = new Node<int>(2);
	auto two_3 = new Node<int>(3);
	auto two_4 = new Node<int>(4);
	auto two_5 = new Node<int>(6);

	auto two = LinkedList<int>();
	two.push_back_node(two_1);
	two.push_back_node(two_2);
	two.push_back_node(two_3);
	two.push_back_node(one_5);
	two.push_back_node(two_5);
	one.print_list();

	two.print_list();
	std::cout << do_linked_lists_intersect(one.head(), two.head())->value << std::endl;
	return 0;
}
