//
// Created by andreas on 23.02.23.
//

#ifndef MONOTONIC_STACK_H
#define MONOTONIC_STACK_H
#include <stack>
template<typename T, bool is_increasing = false>
class MonotonicStack
{
public:


	void push(T value)
	{
		if (is_increasing)
			push_increasing(value);
		else
			push_decreasing(value);
	}
	void pop()
	{
		stack_.pop();
	}
	T top() const
	{
		return stack_.top();
	}

	[[nodiscard]] bool empty() const
	{
		return stack_.empty();
	}

private:
	void push_increasing(T value)
	{
		while (!stack_.empty() && stack_.top() > value)
			stack_.pop();
		stack_.push(value);
	}
	void push_decreasing(T value)
	{
		while (!stack_.empty() && stack_.top() < value)
			stack_.pop();
		stack_.push(value);
	}

	std::stack<T> stack_;
};

#endif //MONOTONIC_STACK_H
