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
struct NodePlusRP: Node<T>
{
	NodePlusRP()
		: Node<T>::value(0),
		  Node<T>::next(nullptr),
		  random(nullptr)
	{}
	explicit NodePlusRP(T val)
		:
		Node<T>::value(val)
	{
	}

	Node<T> *random;
};

#endif //NODE_H
