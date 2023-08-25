//
// Created by andreas on 07.02.22.
//

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include "i_heap.h"
#include <iostream>


template<typename T, size_t heap_capacity, class Compare = std::less<T>>
class StackHeap
{
public:
	StackHeap() = default;

	bool insert(const T &value)
	{
		if (heap_size_ == heap_capacity)
			return false;
		elements_[heap_size_++] = value; // add value at the end and increase size
		promote_(); // promote_ the value to the correct position in heap
		return true;
	}

	T pop()
	{
		size_t index_for_extremum = 0;
		auto value = elements_[index_for_extremum];
		std::swap(elements_[index_for_extremum], elements_[--heap_size_]);
		demote_();
		return value;
	}

	T top() const
	{
		return elements_[0];
	}

	bool is_empty() const
	{
		return heap_size_ == 0;
	}

	size_t size() const
	{
		return heap_size_;
	}

	void print_array()
	{
		std::cout << "*********************" << std::endl;
		for (size_t i = 0; i < heap_size_; ++i) {
			std::cout << "heap-element[" << i + 1 << "] = " << elements_[i] << "\n";
		}

	}
private:
	T elements_[heap_capacity];
	size_t heap_size_{};

	int parent(int index) const
	{
		return (index - 1) / 2;
	}

	int left_child(int index) const
	{
		return 2 * index + 1;
	}

	int right_child(int index) const
	{
		return 2 * index + 2;
	}

	void promote_()
	{
		for (int child_index = heap_size_ - 1; child_index > 0;) {
			int parent_index = parent(child_index);
			if (Compare()(elements_[child_index], elements_[parent_index]))
				return;
			std::swap(elements_[child_index], elements_[parent_index]);
			child_index = parent_index;
		}
	}

	void demote_()
	{
		for (size_t child_index = 1, parent_index = 0; child_index < heap_size_; child_index = (child_index << 1) + 1) {
			if (child_index + 1 < heap_size_ && elements_[child_index] < elements_[child_index + 1])
				child_index++;
			if (Compare()(elements_[parent_index], elements_[child_index]))
				std::swap(elements_[child_index], elements_[parent_index]);
			parent_index = child_index;
		}
	}
};


#endif //BINARY_HEAP_H
