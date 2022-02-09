//
// Created by andreas on 07.02.22.
//

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include "i_heap.h"
#include <iostream>

template<typename T, size_t heap_capacity>
class BinaryHeap: IHeap<T>
{
public:
	BinaryHeap()
	{
		// index 0 will be ignored/not used
		elements_ = new T[heap_capacity + 1];
	}

	~BinaryHeap()
	{
		delete[] elements_;
	}

	void insert(const T &value) final
	{
		elements_[++size_] = value; // add value at the end and increase size
		promote(size_); // promote the value to the correct position in heap
	}

	T pop_maximum() final
	{
		size_t index_for_maximum = 1;
		auto value = elements_[index_for_maximum];
		elements_[index_for_maximum] = elements_[size_--]; // reduce size by one
		demote(index_for_maximum);
	}

	T get_maximum() const final
	{
		return elements_[1];
	}

	bool is_empty() const final
	{
		return size_ == 0;
	}

	size_t size() const final
	{
		return size_;
	}

	void print_array()
	{
		std::cout << "*********************" << std::endl;
		for(size_t i =1; i <= size_; ++i)
		{
			std::cout <<"heap-element[" << i<< "] = " << elements_[i] << "\n";
		}

	}
private:
	T * elements_;
	size_t size_{};
	void promote(size_t element_index)
	{
		while (element_index > 1 && elements_[element_index / 2] < elements_[element_index]) {
			auto help = elements_[element_index / 2];
			elements_[element_index / 2] = elements_[element_index];
			elements_[element_index] = help;
			element_index /= 2;
		}
	}

	void demote(size_t element_index)
	{
		while (2 * element_index < size_) {
			auto double_index = 2 * element_index;
			if (double_index < size_ && elements_[double_index] < elements_[double_index + 1]) {
				double_index++;
			}
			if (elements_[element_index] > elements_[double_index]) {
				break;
			}
			auto help = elements_[element_index];
			elements_[element_index] = elements_[double_index];
			elements_[double_index] = help;
			element_index = double_index;
		}
	}
};


#endif //BINARY_HEAP_H
