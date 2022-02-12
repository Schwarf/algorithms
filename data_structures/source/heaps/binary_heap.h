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
		elements_ = new T[heap_capacity];
		//		for(size_t index = 0; index < heap_size_; ++index)
//		{
//			elements_[index] = T{};
//		}
	}

	~BinaryHeap()
	{
		delete[] elements_;
	}

	void insert(const T &value) final
	{
		heap_size_++;
		auto index = heap_size_ - 1;
		elements_[index] = value; // add value at the end and increase size
		promote(index); // promote the value to the correct position in heap
	}

	T pop_maximum() final
	{
		size_t index_for_maximum = 0;
		auto value = elements_[index_for_maximum];
		elements_[index_for_maximum] = elements_[heap_size_ - 1];
		elements_[heap_size_ - 1] = T{};
		heap_size_--;
		demote(index_for_maximum);
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
			std::out_of_range(
				"Index " + std::to_string(index) + " in binary heap, is greater than heap size " + std::to_string(heap_size_)
					+ "!");
		return elements_[index];
	}

	T * get_array()
	{
		return elements_;
	}
	void print_array()
	{
		std::cout << "*********************" << std::endl;
		for (size_t i = 0; i < heap_size_; ++i) {
			std::cout << "heap-element[" << i+1 << "] = " << elements_[i] << "\n";
		}

	}
private:
//	T elements_[heap_capacity] ;
	T * elements_;
	size_t heap_size_{};

	size_t parent_index(size_t element_index){
		return (element_index - 1)/2;
	}

	size_t left_child_index(size_t element_index){
		return 2*element_index + 1;
	}

	size_t right_child_index(size_t element_index){
		return 2*element_index + 2;
	}

	void promote(size_t element_index)
	{
		while (element_index != 0 &&  elements_[parent_index(element_index)] < elements_[element_index]) {
			swap(element_index, parent_index(element_index));
			element_index = parent_index(element_index);
		}
	}

	void swap(size_t index1, size_t index2)
	{
		auto help = elements_[index1];
		elements_[index1] = elements_[index2];
		elements_[index2] = help;
	}
	void demote(size_t element_index)
	{
		while (2*element_index + 2 < heap_size_) {
			auto new_index = 2*element_index + 1;
			if (elements_[new_index+1] >  elements_[new_index])
				new_index++;

			if(elements_[new_index] > elements_[element_index] ){
				swap(new_index, element_index);
				element_index = new_index;
			}
		}
	}
};


#endif //BINARY_HEAP_H
