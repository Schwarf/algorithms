//
// Created by andreas on 23.01.22.
//

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template<typename T>
class SinglyLinkedList
{
	struct Node
	{
		T value;
		Node *next;
	};
private:
	bool is_index_valid(size_t index)
	{
		return index < length_;
	}

public:
	SinglyLinkedList()
	{
		head_ = nullptr;
	}

	bool is_empty()
	{
		return head_ == nullptr;
	}

	T pop_front()
	{
		if (is_empty())
			throw std::out_of_range("Singly linked list is empty (pop_front).");

		auto value = head_->value;
		auto help = head_->next;
		delete head_;
		head_ = help;
		length_--;
		return value;
	}

	T pop_back()
	{
		if (is_empty())
			throw std::out_of_range("Singly linked list is empty (pop_back).");
		if (head_->next == nullptr) {
			T value = head_->value;
			head_ = nullptr;
			length_--;
			return value;
		}
		auto current = head_;

		while (current->next->next != nullptr)
			current = current->next;
		T value = current->next->value;
		delete current->next;
		current->next = nullptr;
		length_--;
		return value;
	}

	T pop_at_index(size_t index)
	{
		if (is_empty())
			throw std::out_of_range("Singly linked list is empty (pop_at_index).");
		if (!is_index_valid(index))
			throw std::out_of_range("The index in singly linked list is out of range in method 'pop_at_index'");
		T value;
		length_--;
		if(index == 0) {
			return pop_front();
		}
		if(index == 1) {
			value= head_->next->value;
			delete head_->next;
			head_->next = nullptr;
			return value;
		}
		size_t counter = 2;
		auto previous = head_->next;
		auto current = head_->next->next;
		while(counter < index)
		{
			previous = current;
			current = current->next;
			counter++;
		}
		value = current->value;
		previous->next = current->next;
		delete current;
		return value;

	}

	void push_at_front(const T &value)
	{
		auto new_head = new Node();
		new_head->value = value;
		if (head_ == nullptr) {
			new_head->next = nullptr;
			head_ = new_head;
			length_ = 1;
			return;
		}
		new_head->next = head_;
		head_ = new_head;
		length_++;
	}
	void push_at_back(const T &value)
	{

		auto new_tail = new Node();
		new_tail->value = value;
		new_tail->next = nullptr;
		if (head_ == nullptr) {
			head_ = new_tail;
			new_tail->next = nullptr;
			length_ = 1;
			return;
		}
		auto current = head_;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new_tail;
		length_++;
	}

	bool get(size_t index, T &return_value)
	{
		if (!is_index_valid(index))
			throw std::out_of_range("The index in singly linked list is out of range in method 'get'");
		auto current = head_;
		size_t count{};
		while (current != nullptr) {
			if (index == count) {
				return_value = current->value;
				return true;
			}
			current = current->next;
			count++;
		}
		return false;
	}

	bool add_at_index(const T &value, size_t index)
	{
		if (!is_index_valid(index))
			return false;
		if (index == length_ - 1) {
			push_at_back(value);
			return true;
		}
		if (index == 0) {
			push_at_front(value);
			return true;
		}

		auto new_node = new Node();
		new_node->value = value;
		auto current = head_;
		Node *previous = nullptr;
		size_t count = 0;
		while (current != nullptr) {
			if (count == index) {
				previous->next = new_node;
				new_node->next = current;
				length_++;
				return true;
			}
			previous = current;
			current = current->next;
			count++;
		}
		return false;
	}
	size_t size() const
	{
		return length_;
	}


private:
	Node *head_;
	size_t length_{};
};

#endif //SINGLY_LINKED_LIST_H
