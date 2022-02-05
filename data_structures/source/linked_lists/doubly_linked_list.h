//
// Created by andreas on 24.01.22.
//

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "i_linked_list.h"

template<typename T>
class DoublyLinkedList: ILinkedList<T>
{
	struct Node
	{
		T value;
		Node *next;
		Node *previous;
		explicit Node(const T &val)
		{
			value = val;
		}
	};

	bool is_index_valid_(size_t index)
	{
		return index < length_;
	}

public:
	DoublyLinkedList()
	{
		head_ = nullptr;
		tail_ = nullptr;
	}
	~DoublyLinkedList()
	{
		std::cout<< "Call to destructor doubly linked list " << std::endl;
		if (head_ == nullptr)
			return;
		auto next = head_->next;
		while (next != nullptr) {
			delete head_;
			head_ = next;
			next = next->next;
		}
	}

	bool is_empty() const final
	{
		return head_ == nullptr;
	}

	size_t size() const final
	{
		return length_;
	}

	bool push_at(size_t index, const T &value) final
	{
		if (index == 0) {
			push_front(value);
			return true;
		}
		if (!is_index_valid_(index))
			return false;
		if (index == length_ - 1) {
			push_back(value);
			return true;
		}

		auto new_node = new Node(value);
		auto current = head_->next;
		size_t index_counter = 1;
		while (index_counter < index) {
			index_counter++;
			current = current->next;
		}
		new_node->next = current;
		new_node->previous = current->previous;
		current->previous->next = new_node;
		current->previous = new_node;
		length_++;
		return true;
	}

	void push_front(const T &value) final
	{
		auto new_node = new Node(value);
		if (is_empty()) {
			tail_ = new_node;
			head_ = tail_;
			length_++;
			return;
		}
		auto help = head_;
		help->previous = new_node;
		new_node->previous = nullptr;
		new_node->next = help;
		head_ = new_node;
		length_++;
	}

	void push_back(const T &value) final
	{
		auto new_node = new Node(value);
		new_node->next = nullptr;
		if (is_empty()) {
			head_ = new_node;
			tail_ = head_;
			length_++;
			return;
		}
		auto help = tail_;
		help->next = new_node;
		new_node->previous = help;
		new_node->next = nullptr;
		tail_ = new_node;
		length_++;
	}

	T pop_back() final
	{
		if (is_empty())
			throw std::out_of_range("Doubly linked list is empty (pop_back).");
		auto value = tail_->value;
		auto help = tail_->previous;
		if (tail_ == head_) {
			delete tail_;
			length_--;
			return value;
		}
		tail_ = help;
		tail_->next = nullptr;
		length_--;
		return value;
	}

	T pop_front() final
	{
		if (is_empty())
			throw std::out_of_range("Doubly linked list is empty (pop_front).");
		auto value = head_->value;
		auto help = head_->next;
		if (tail_ == head_) {
			delete head_;
			length_--;
			return value;
		}
		delete head_;
		head_ = help;
		head_->previous = nullptr;
		length_--;
		return value;
	}

	T pop_at(size_t index) final
	{
		if (is_empty())
			throw std::out_of_range("Doubly linked list is empty (pop_at).");
		if (!is_index_valid_(index))
			throw std::out_of_range("The index in doubly linked list is out of range in method 'pop_at'");
		if (index == 0)
			return pop_front();
		if (index == length_ - 1)
			return pop_back();

		size_t index_counter = 1;
		auto current = head_->next;
		auto previous = head_;
		while (index_counter < index) {
			index_counter++;
			previous = current;
			current = current->next;
		}
		auto value = current->value;
		previous->next = current->next;
		current->next->previous = previous;
		delete current;
		length_--;
		return value;
	}

	T get(size_t index)
	{
		if (is_empty())
			throw std::out_of_range("Doubly linked list is empty (get).");
		if (!is_index_valid_(index))
			throw std::out_of_range("The index in doubly linked list is out of range in method 'get'");
		size_t index_counter = 0;
		auto current = head_;
		while (index_counter < index) {
			current = current->next;
			index_counter++;
		}
		return current->value;

	}

	T get_from_back(size_t index)
	{
		if (is_empty())
			throw std::out_of_range("Doubly linked list is empty (get).");
		if (!is_index_valid_(index))
			throw std::out_of_range("The index in doubly linked list is out of range in method 'get'");
		int index_counter = length_ - 1;
		auto current = tail_;
		while (index_counter > index) {
			current = current->previous;
			index_counter--;
		}
		return current->value;

	}


private:
	Node *head_;
	Node *tail_;
	size_t length_{};
};

#endif //DOUBLE_LINKED_LIST_H
