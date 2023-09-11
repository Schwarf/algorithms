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

// Node with random pointer
template<typename T>
struct NodePlusRP
{
	NodePlusRP()
		: random(nullptr)
	{}
	explicit NodePlusRP(T val)
		:
		value(val),
		next(nullptr),
		random(nullptr)
	{
	}

	NodePlusRP<T> *random;
	T value;
	NodePlusRP<T> *next{nullptr};

};

#endif //NODE_H
