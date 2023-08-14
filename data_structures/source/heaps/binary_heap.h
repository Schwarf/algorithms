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

	void insert(const T &value) final
	{
		if (heap_size_ == heap_capacity)
			throw std::out_of_range("Heap is full!");
		elements_[heap_size_++] = value; // add value at the end and increase size
		promote_(); // promote_ the value to the correct position in heap
	}

	T pop_maximum() final
	{
		size_t index_for_maximum = 0;
		auto value = elements_[index_for_maximum];
		swap_(index_for_maximum, --heap_size_);
		demote_();
		return value;
	}

	T get_maximum() const final
	{
		return elements_[0];
	}

	bool is_empty() const final
	{
		return heap_size_ == 0;
	}

	size_t size() const final
	{
		return heap_size_;
	}

	T get_element(size_t index) const final
	{
		if (index > heap_size_)
			throw std::out_of_range(
				"Index " + std::to_string(index) + " in binary heap, is greater than heap size "
					+ std::to_string(heap_size_)
					+ "!");
		return elements_[index];
	}

	T *get_array()
	{
		return elements_;
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

	void promote_()
	{
		for (int child_index = heap_size_ - 1; child_index > 0;) {
			int parent_index = (child_index - 1) >> 1;
			if (elements_[parent_index] >= elements_[child_index])
				return;
			swap_(child_index, parent_index);
			child_index = parent_index;
		}
	}

	void swap_(size_t index1, size_t index2)
	{
		auto help = elements_[index1];
		elements_[index1] = elements_[index2];
		elements_[index2] = help;
	}
	void demote_()
	{
		for (size_t child_index = 1, parent_index = 0; child_index < heap_size_; child_index = (child_index << 1) + 1) {
			if (child_index + 1 < heap_size_ && elements_[child_index] < elements_[child_index + 1])
				child_index++;
			if (elements_[parent_index] < elements_[child_index])
				swap_(child_index, parent_index);
			parent_index = child_index;
		}
	}
};


#endif //BINARY_HEAP_H
