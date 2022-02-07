//
// Created by andreas on 07.02.22.
//

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include "i_heap.h"

template<typename T, size_t heap_capacity>
class BinaryHeap : IHeap<T>
{
public:
	//virtual T find_max() const =0;
	//virtual void delete_max() =0;
	//virtual void insert(const T & value) =0;
	//virtual size_t size() const = 0;
	//virtual bool is_empty() const = 0;
	//virtual merge(IHeap & other) = 0;

private:
	T elements_[heap_capacity + 1];
	size_t size_{};
	void promote(size_t element_index)
	{
		while( element_index > 1 && elements_[element_index/2] < elements_[element_index])
		{
			auto help = elements_[element_index/2];
			elements_[element_index/2] = elements_[element_index];
			elements_[element_index] = help;
			element_index /=2;
		}
	}

public:
	void insert(const T & value)
	{
		elements_[++size_] = value;
		promote(size_);
	}


};


#endif //BINARY_HEAP_H
