//
// Created by andreas on 24.01.22.
//

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

template <typename T>
class DoubleLinkedList
{
	struct Node
	{
		T value;
		Node *next;
		Node *previous;
		explicit Node(const T & val)
		{
			value = val;
		}
	};

	size_t length_{};


public:
	DoubleLinkedList()
	{
		head_ = nullptr;
		tail_ = nullptr;
	}

	bool is_empty()
	{
		return head_ == nullptr == tail_;
	}

	void push_at_head(const T & value)
	{
		auto new_node = new Node(value);
		new_node->previous = nullptr;
		if(is_empty())
		{
			tail_ = new_node;
		}
		else
		{
			head_->previous = new_node;
		}
		head_= new_node;
	}

	void push_at_back(const T & value)
	{
		auto new_node = new Node(value);
		new_node->next = nullptr;
		if(is_empty())
		{
			head_ = new_node;
		}
		else
		{
			tail_->next = new_node;
		}
		tail_= new_node;
	}

	T pop_back()
	{
		if(is_empty())
			throw std::out_of_range("Doubly linked list is empty (pop_back).");
		auto value = tail_->value;
		auto help = tail_->previous;
		delete tail_;
		tail_ = help;
		tail_->next = nullptr;
		return value;
	}


private:
	Node * head_;
	Node * tail_;
};

#endif //DOUBLE_LINKED_LIST_H
