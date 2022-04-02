//
// Created by andreas on 02.04.22.
//

#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T>
struct Node
{
	explicit Node(T val)
	{
		value= val;
	}
	T value;
	Node * next = nullptr;
};


template <typename T, size_t max_size>
class Stack
{
public:
	void push(T value)
	{
		auto new_head = new Node<T>(value);
		size_++;
		if(head_ == nullptr)
		{
			head_ = new_head;
			return;
		}

		auto help = head_;
		head_ = new_head;
		head_->next = help;
	}

	T pop()
	{
		if(head_ == nullptr)
			throw std::out_of_range("Stack is empty");
		size_--;
		T value = head_->value;
		if(head_->next == nullptr)
		{
			delete head_;
			head_ = nullptr;
			return value;
		}

		auto help = head_;
		head_ = head_->next;
		delete help;
		return value;
	}

	T peek()
	{
		if(head_ == nullptr)
			throw std::out_of_range("Stack is empty");
		T value = head_->value;
		return value;
	}

	bool is_full()
	{
		return size_ == max_size;
	}

	bool is_empty()
	{
		return size_ == 0;
	}


private:
	size_t size_{};
	Node <T> * head_ = nullptr;

};



template <typename T, size_t max_size>
class SetOfStacks
{
public:
	SetOfStacks()
	{
		auto initial_stack = new Stack<T, max_size>();
		set_of_stacks_.push_back(initial_stack);
	}

	void push(T value)
	{
		auto current_stack = set_of_stacks_.back();
		if(current_stack->is_full())
		{
			auto new_stack = new Stack<T, max_size>();
			set_of_stacks_.push_back(new_stack);
			current_stack = set_of_stacks_.back();
		}

		current_stack->push(value);
	}

	T popAt(size_t index)
	{
		if(index > set_of_stacks_.size())
		{
			throw std::out_of_range("Index out of range.");
		}
		auto current_stack = set_of_stacks_.at(index);
		if(current_stack->is_empty())
		{
			throw std::out_of_range("Stack at given index is empty!");
		}
		return current_stack->pop();

	}

	T pop()
	{
		auto current_stack = set_of_stacks_.back();
		if(current_stack->is_empty())
		{
			set_of_stacks_.pop_back();
			if(!set_of_stacks_.empty())
				current_stack = set_of_stacks_.back();
			else
				throw std::out_of_range("Set of stacks is empty!");
		}
		current_stack->pop();
	}

	T peek()
	{
		auto current_stack = set_of_stacks_.back();
		if(current_stack->is_empty())
		{
			set_of_stacks_.pop_back();
			if(!set_of_stacks_.empty())
				current_stack = set_of_stacks_.back();
			else
				throw std::out_of_range("Set of stacks is empty!");
		}
		current_stack->peek();
	}


private:
	std::vector<Stack<T, max_size> * > set_of_stacks_;

};

int main()
{
	auto test =SetOfStacks<int, 2>();
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);

	std::cout << test.popAt(1) << std::endl;
	std::cout << test.popAt(1) << std::endl;
	std::cout << test.popAt(1) << std::endl;
	std::cout << test.pop() << std::endl;
	std::cout << test.pop() << std::endl;
	std::cout << test.pop() << std::endl;
	std::cout << test.pop() << std::endl;

	return 0;
}