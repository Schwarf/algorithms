//
// Created by andreas on 02.02.22.
//

#ifndef STACK_LINKED_LIST_BASED_H
#define STACK_LINKED_LIST_BASED_H
#include "i_stack.h"

template <class T>
class StackLLB : IStack<T>{
private:
	struct Node{
		Node(const T & val){
			value = val;
			next = nullptr;

		}
		T value;
		Node * next;
	};
	Node * head_;
	size_t size_{};

public:
	StackLLB(){
		head_ = nullptr;
	}
	StackLLB(const T & value){
		head_ = new Node(value);
	}
	~StackLLB(){
		std::cout << "Called destructor of stack (linked list based)!" << std::endl;
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
			size_++;
			return;
		}
		auto new_node = new Node(value);
		auto help = head_;
		head_ = new_node;
		head_->next = help;
		size_++;
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
		size_--;
		return value;
	}

	T top() const final
	{
		if(is_empty()) {
			throw std::out_of_range("Can not top. The stack is empty.");
		}
		return head_->value;
	}

	bool is_empty() const final
	{
		return head_ == nullptr;
	}

	size_t size() const final
	{
		return size_;
	}
};

#endif //STACK_LINKED_LIST_BASED_H
