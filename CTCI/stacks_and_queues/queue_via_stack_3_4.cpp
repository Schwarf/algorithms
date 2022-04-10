//
// Created by andreas on 02.04.22.
//
// This is not the best solution!!!!

#include <stack>
#include <queue>
#include <stdexcept>
#include <iostream>

template <typename T>
class StackBasedQueue{
private:
	std::stack<T> element_stack;
	std::stack<T> help_stack;
public:
	void add(const T & value)
	{
		element_stack.push(value);
	}
	void remove()
	{
		if(element_stack.empty())
			return;
		while(element_stack.size() !=1)
		{
			help_stack.push(element_stack.top());
			element_stack.pop();
		}
		element_stack.pop();
		while(!help_stack.empty())
		{
			element_stack.push(help_stack.top());
			help_stack.pop();
		}
	}

	T peek()
	{
		if(element_stack.empty())
			throw std::out_of_range("Queue is empty!");

		while(element_stack.size() !=1)
		{
			help_stack.push(element_stack.top());
			element_stack.pop();
		}
		auto value = element_stack.top();
		while(!help_stack.empty())
		{
			element_stack.push(help_stack.top());
			help_stack.pop();
		}
		return value;
	}
};

int main()
{
	int values[5] = {1,2,3,4,5};
	std::queue<int> q;
	StackBasedQueue<int> mq;
	for(size_t index =0; index < 5; index++)
	{
		q.push(values[index]);
		mq.add(values[index]);
	}
	for (size_t index =0; index < 5; index++)
	{
		std:: cout << q.front() - mq.peek() << std::endl;
		q.pop();
		mq.remove();
	}
	return 0;
}
