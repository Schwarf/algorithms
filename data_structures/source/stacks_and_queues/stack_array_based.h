//
// Created by andreas on 05.02.22.
//

#ifndef STACK_ARRAY_BASED_H
#define STACK_ARRAY_BASED_H
#include "i_stack.h"

template<class T, size_t stack_capacity>
class StackAB: IStack<T>
{
private:
	T elements_[stack_capacity + 1]; // +1 because the zero-index element is not used.
	size_t head_{};
public:
	StackAB() = default;

	explicit StackAB(const T &value)
	{
		head_++;
		elements_[head_] = value;
	}

	void push(const T &value) final
	{
		head_++;
		if (head_ > stack_capacity) {
			throw std::out_of_range("Can not push. The stack (array based) is full.");
		}
		elements_[head_] = value;
	}

	bool is_empty() const final
	{
		return head_ == 0;
	}

	T pop() final
	{
		if (is_empty()) {
			throw std::out_of_range("Can not pop. The stack (array based) is empty.");
		}
		auto value = top();
		head_--;
		return value;
	}

	T top() const final
	{
		if (is_empty()) {
			throw std::out_of_range("Can not top. The stack (array based) is empty.");
		}
		return elements_[head_];
	}

	size_t size() const final
	{
		return head_;
	}

};

#endif //STACK_ARRAY_BASED_H
