//
// Created by andreas on 31.01.22.
//

#ifndef I_LINKED_LIST_H
#define I_LINKED_LIST_H

template<typename T>
class ILinkedList
{
	virtual void push_at_front(const T & value) = 0;
	virtual void push_at_back(const T & value) = 0;
	virtual bool push_at_index(const T &value, size_t index) = 0;
	virtual T pop_back() = 0;
	virtual T pop_front() = 0;
	virtual T pop_at_index(size_t index) = 0;
};

#endif //I_LINKED_LIST_H
