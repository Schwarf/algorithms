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
	};

public:
	DoubleLinkedList()
	{
		head_ = nullptr;
		tail_ = nullptr;
	}

	void add_at_head(const T & value)
	{
		auto new_node = new Node();
		new_node->value = value;
		new_node->previous = nullptr;
		if(head_ == nullptr)
		{
			tail_ = new_node;
		}
		else
		{
			head_->previous = new_node;
		}
		head_= new_node;
	}

	void add_at_tail(const T & value)
	{
		auto new_node = new Node();
		new_node->value = value;
		new_node->next = nullptr;
		if(tail_ == nullptr)
		{
			head_ = new_node;
		}
		else
		{
			tail_->next = new_node;
		}
		tail_= new_node;
	}


private:
	Node * head_;
	Node * tail_;
};

#endif //DOUBLE_LINKED_LIST_H
