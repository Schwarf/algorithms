//
// Created by andreas on 10.04.22.
//
#include <stack>
#include <vector>
#include <iostream>


// This creates a sorted_stack but asked was to sort an existing stack
template<typename T>
class sorted_stack
{
private:
	std::stack<T> help_stack_;
	std::stack<T> sorted_stack_;
public:
	void push(const T &value)
	{
		if (sorted_stack_.empty()) {
			sorted_stack_.push(value);
			return;
		}
		if (value <= sorted_stack_.top()) {
			sorted_stack_.push(value);
			return;
		}

		help_stack_.push(sorted_stack_.top());
		sorted_stack_.pop();
		while (!sorted_stack_.empty()) {
			if (sorted_stack_.top() < value) {
				help_stack_.push(sorted_stack_.top());
				sorted_stack_.pop();
			}
			else
				break;
		}
		sorted_stack_.push(value);
		while (!help_stack_.empty()) {
			sorted_stack_.push(help_stack_.top());
			help_stack_.pop();
		}
	}

	T top()
	{
		return sorted_stack_.top();
	}

	void pop()
	{
		return sorted_stack_.pop();
	}
};

int main()
{
	auto vec = std::vector<int>{1, 2, 4, 3, -2, 2};
	auto min_vec = std::vector<int>{-2, 1, 2, 2, 3, 4};
	auto sorted = sorted_stack<int>();
	for(const auto & element: vec)
	{
		sorted.push(element);
	}
	for(const auto & element: min_vec)
	{
		std::cout << sorted.top() - element << std::endl;
		std::cout << sorted.top() << std::endl;
		sorted.pop();
	}

	return 0;
}