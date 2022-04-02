#include <iostream>
#include <stdexcept>


template<typename T, size_t max_size>
class Stack
{
public:
	void push(T value)
	{
		stack_index_++;
		if (stack_index_ > max_size)
			throw std::out_of_range("The stack has reached is maximum size");
		elements_[stack_index_] = value;

	}

	T pop()
	{
		if (stack_index_ == 0)
			throw std::out_of_range("The stack is empty");

		auto value = elements_[stack_index_];
		stack_index_--;
		return value;
	}

	T peek()
	{
		if (stack_index_ == 0)
			throw std::out_of_range("The stack is empty");
		auto value = elements_[stack_index_];
		return value;

	}

	size_t size()
	{
		return stack_index_;
	}


private:

	T elements_[max_size + 1];
	size_t stack_index_{};
};

template<typename T, size_t max_size>
class MinStack
{
public:
	MinStack()
	{
		min_ = Stack<T, max_size>();
	}

	void push(T value)
	{
		stack_index_++;
		if (stack_index_ > max_size)
			throw std::out_of_range("The stack has reached is maximum size");
		elements_[stack_index_] = value;
		if (min_.size() == 0) {
			min_.push(value);
		}
		else {
			if (value < min_.peek()) {
				min_.push(value);
			}
		}
	}

	T pop()
	{
		if (stack_index_ == 0)
			throw std::out_of_range("The stack is empty");

		auto value = elements_[stack_index_];
		if (min_.size() > 0 && value == min_.peek()) {
			min_.pop();
		}
		stack_index_--;
		if (min_.size() == 0) {
			min_.push(peek());
		}
		return value;
	}

	T peek()
	{
		if (stack_index_ == 0)
			throw std::out_of_range("The stack is empty");
		auto value = elements_[stack_index_];
		return value;

	}

	T min()
	{
		if (stack_index_ == 0)
			throw std::out_of_range("The stack is empty");

		return min_.peek();

	}

private:
	Stack<T, max_size> min_;
	size_t stack_index_{};
	T elements_[max_size + 1];

};

int main()
{
	auto test = MinStack<int, 5>();
	test.push(1);
	test.push(0);
	test.push(3);
	test.push(4);
	test.push(-1);
	std::cout <<test.peek() <<std::endl;
	std::cout <<test.min() <<std::endl;
	std::cout <<test.pop() <<std::endl;
	std::cout <<test.min() <<std::endl;
	std::cout <<test.pop() <<std::endl;
	std::cout <<test.min() <<std::endl;
	std::cout <<test.pop() <<std::endl;
	std::cout <<test.min() <<std::endl;
	std::cout <<test.pop() <<std::endl;
	std::cout <<test.min() <<std::endl;
	return 0;
}
