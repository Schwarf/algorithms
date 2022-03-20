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
		prev_node = node;
		node = node->next;
		while (node != nullptr) {
			if (node->value < value) {
				auto new_head_node = new Node<int>(node->value);
				new_head_node->next = head_;
				head_ = new_head_node;
				if (node == end_node) {
					end_node = prev_node;
					delete node;
					end_node->next = nullptr;
					break;
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
	single.push_back(17);
	single.push_back(3);
	single.print_list();
	single.partition(5);
	single.print_list();

	auto single2 = LinkedList<int>();
	single2.push_back(5);
	single2.push_back(1);
	single2.push_back(2);
	single2.push_back(3);
	single2.print_list();
	single2.partition(5);
	single2.print_list();


	auto single3 = LinkedList<int>();
	single3.push_back(1);
	single3.push_back(2);
	single3.push_back(3);
	single3.push_back(5);
	single3.push_back(6);
	single3.push_back(7);
	single3.print_list();
	single3.partition(5);
	single3.print_list();

	auto single4 = LinkedList<int>();
	single4.push_back(1);
	single4.push_back(7);
	single4.push_back(3);
	single4.push_back(5);
	single4.push_back(2);
	single4.push_back(7);
	single4.print_list();
	single4.partition(5);
	single4.print_list();


	auto single5 = LinkedList<int>();
	single5.push_back(7);
	single5.push_back(5);
	single5.print_list();
	single5.partition(5);
	single5.print_list();


	auto single6 = LinkedList<int>();
	single6.push_back(5);
	single6.push_back(1);
	single6.print_list();
	single6.partition(5);
	single6.print_list();

	auto single7 = LinkedList<int>();
	single7.push_back(1);
	single7.print_list();
	single7.partition(5);
	single7.print_list();

	return 0;
}