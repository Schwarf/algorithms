//
// Created by andreas on 14.03.23.
//

#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
	Node()
		: value(0),
		  next(nullptr)
	{}

	explicit Node(T val)
		:
		value(val)
	{
	}
	T value;
	Node<T> *next{nullptr};
};
#endif //NODE_H
