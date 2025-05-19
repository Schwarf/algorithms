//
// Created by andreas on 23.02.23.
//

#ifndef MONOTONIC_STACK_H
#define MONOTONIC_STACK_H
#include <stack>
// Increasing here means from bottom to top. That means the greatest element is on top of the stack.
template<typename T, bool is_increasing = false> requires std::totally_ordered<T>
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

template<typename T, bool is_increasing = false> requires std::totally_ordered<T>
class MonotonicStackPair
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
		return stack_.top().first;
	}

	[[nodiscard]] bool empty() const
	{
		return stack_.empty();
	}

private:
	void push_increasing(T value)
	{
		auto new_value = std::make_pair(value, std::min(stack_.top().second, value));
		stack_.push(new_value);
	}
	void push_decreasing(T value)
	{
		auto new_value = std::make_pair(value, std::max(stack_.top().second, value));
		stack_.push(new_value);
	}

	std::stack<std::pair<T, T>> stack_;
};

#endif //MONOTONIC_STACK_H
