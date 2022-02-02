//
// Created by andreas on 02.02.22.
//

#ifndef STACK_LINKED_LIST_BASED_H
#define STACK_LINKED_LIST_BASED_H
#include "i_stack.h"

template <class T>
class Stack : IStack<T>{
private:
	struct Node{
		Node(const T val){
			value = val;
		}
		T value;
		Node * next;
	};
	Node * head_;

public:
	Stack(){
		head_ = nullptr;
	}
	Stack(const T & value){
		head_ = new Node(value);
	}
	~Stack(){
		if(head_ == nullptr)
			return;
		auto next = head_->next;
		while(next != nullptr)
		{
			delete head_;
			head_ = next;
			next = next->next;
		}
	}
	void push(const T & value) final
	{
		if(head_ == nullptr) {
			head_ = new Node(value);
			return;
		}
		auto new_node = new Node(value);
		auto help = head_;
		head_ = new_node;
		head_->next = help;
	}

	T pop() final
	{
		if(is_empty()) {
			throw std::out_of_range("Can not pop. The stack is empty.");
		}
		T value = head_->value;
		auto help = head_;
		head_ = head_->next;
		delete help;
		return value;
	}

	T top() final
	{
		if(is_empty()) {
			throw std::out_of_range("Can not top. The stack is empty.");
		}
		return head_->value;
	}

	bool is_empty()
	{
		return head_ == nullptr;
	}

};

#endif //STACK_LINKED_LIST_BASED_H
