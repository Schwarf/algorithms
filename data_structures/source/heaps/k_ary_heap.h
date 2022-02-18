//
// Created by andreas on 12.02.22.
//

#ifndef K_ARY_HEAP_H
#define K_ARY_HEAP_H
#include "i_heap.h"

template<typename T, size_t number_of_nodes, size_t heap_capacity>
class K_aryHeap: IHeap<T>
{
public:
	K_aryHeap()
	{
		elements_ = new T[heap_capacity];
	};
	~K_aryHeap()
	{
		delete [] elements_;
	}

	T *get_array()
	{
		return elements_;
	}

	size_t size() const final
	{
		return heap_size_;
	}

	bool is_empty() const final
	{
		return heap_size_ == 0;
	}

	T get_maximum() const final
	{
		return elements_[0];
	}

	T get_element(size_t index) const final
	{
		if (index > heap_size_)
			std::out_of_range(
				"Index " + std::to_string(index) + " in k-ary heap (k=" + std::to_string(number_of_nodes)
					+ "), is greater than heap size " + std::to_string(heap_size_)
					+ "!");

		return elements_[index];
	}

	void insert(const T &element) final
	{
		if (heap_size_ == 0) {
			elements_[heap_size_++] = element;
			return;
		}
		heap_size_++;
		size_t index = heap_size_ - 1;
		elements_[index] = element;
		promote_(index);
	}
	T pop_maximum() final
	{
		size_t index_of_maximum = 0;
		auto maximum = elements_[index_of_maximum];
		size_t index_last_element = heap_size_ - 1;
		swap_(index_of_maximum, index_last_element);
		heap_size_--;
		demote_(index_of_maximum);
		return maximum;
	}
private:
	//T elements_[heap_capacity];
	T *elements_;
	size_t heap_size_{};
	size_t parent_index_(size_t element_index)
	{
		return (element_index - 1) / number_of_nodes;
	}
	void swap_(size_t index1, size_t index2)
	{
		auto help = elements_[index1];
		elements_[index1] = elements_[index2];
		elements_[index2] = help;
	}

	void promote_(size_t element_index)
	{
		while (element_index != 0 && elements_[parent_index_(element_index)] < elements_[element_index]) {
			swap_(parent_index_(element_index), element_index);
			element_index = parent_index_(element_index);
		}
	}

	size_t get_index_of_max_element_in_sub_sequence(size_t element_index)
	{
		auto max = T{};
		size_t index_of_maximum = 0;
		auto number_of_children = number_of_children_(element_index);
		for (size_t node_index = 1; node_index <= number_of_children; ++node_index) {
			if (elements_[number_of_nodes * element_index + node_index] > max) {
				max = elements_[number_of_nodes * element_index + node_index];
				index_of_maximum = number_of_nodes * element_index + node_index;
			}
		}
		return index_of_maximum;

	}

	size_t number_of_children_(size_t element_index)
	{
		size_t number_of_children{};

		while (true) {
			auto highest_index = element_index * number_of_nodes + number_of_children;
			if ((highest_index >= heap_size_ - 1) || number_of_children == number_of_nodes)
				return number_of_children;
			number_of_children++;
		}
	}
	void demote_(size_t element_index)
	{

		while (number_of_nodes * element_index + number_of_children_(element_index) < heap_size_) {
			auto index_of_maximum = get_index_of_max_element_in_sub_sequence(element_index);
			if (elements_[index_of_maximum] > elements_[element_index]) {
				swap_(index_of_maximum, element_index);
				element_index = index_of_maximum;
			}
			else
				break;
		}
	}
};

#endif //K_ARY_HEAP_H
