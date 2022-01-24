//
// Created by andreas on 23.01.22.
//

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H


template <typename T>
class SingleLinkedList{
	struct Node{
		T value;
		Node * next;
	};

public:
	SingleLinkedList(){
		head_ = nullptr;
	}

	void add_at_head(const T & value)
	{
		auto new_head = new Node();
		new_head->value = value;
		if(head_ == nullptr)
		{
			new_head->next = nullptr;
			head_ = new_head;
			length_ = 1;
			return;
		}
		new_head->next = head_;
		head_ = new_head;
		length_++;
	}
	void add_at_tail(const T & value){

		auto new_tail = new Node();
		new_tail->value = value;
		new_tail->next = nullptr;
		if(head_ == nullptr)
		{
			head_ = new_tail;
			new_tail->next = nullptr;
			length_ = 1;
			return;
		}
		auto current = head_;
		while(current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new_tail;
		length_++;
	}

	bool get(size_t index, T& return_value)
	{
		auto current = head_;
		size_t count{};
		while(current != nullptr)
		{
			if(index == count) {
				return_value = current->value;
				return true;
			}
			current = current->next;
			count++;
		}
		return false;
	}


	bool add_at_index(const T & value, size_t index)
	{
		if(index > length_ - 1)
			return false;
		if(index== length_ - 1) {
			add_at_tail(value);
			return true;
		}
		if(index ==0)
		{
			add_at_head(value);
			return true;
		}

		auto new_node = new Node();
		new_node->value =value;
		auto current = head_;
		Node * previous = nullptr;
		size_t count = 0;
		while(current != nullptr)
		{
			if(count == index)
			{
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
	Node * head_;
	size_t length_{};
};

#endif //SINGLE_LINKED_LIST_H
