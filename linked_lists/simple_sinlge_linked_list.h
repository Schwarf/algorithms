//
// Created by andreas on 21.07.22.
//

#ifndef SIMPLE_SINLGE_LINKED_LIST_H
#define SIMPLE_SINLGE_LINKED_LIST_H

template<typename T>
struct Node
{
	Node(T val)
	{
		value = val;
	}
	Node *next = nullptr;
	T value{};
};

#endif //SIMPLE_SINLGE_LINKED_LIST_H
