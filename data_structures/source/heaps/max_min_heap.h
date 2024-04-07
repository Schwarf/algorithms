//
// Created by andreas on 03.04.24.
//

#ifndef MAX_MIN_HEAP_H
#define MAX_MIN_HEAP_H
#include <concepts>
#include <vector>

#include <stdexcept>

template<typename T>
concept Ordered = requires(T a, T b)
{
	{ a < b } -> std::convertible_to<bool>;
	{ a <= b } -> std::convertible_to<bool>;
	{ a > b } -> std::convertible_to<bool>;
	{ a >= b } -> std::convertible_to<bool>;
};

template<typename T, class Container = std::vector<T>, class Comparator = std::less<T>> requires Ordered<T>
class MaxMinHeap
{

public:
	MaxMinHeap() = default;

	void push(T element)
	{
		heap_.push_back(element);
		trickle_up(heap_.size() - 1);
	}

	size_t size() const
	{
		return heap_.size();
	}

	bool empty() const
	{
		return heap_.empty();
	}

	const T &max() const
	{
		if (empty())
			throw std::underflow_error("Heap is empty. No max-element can be retrieved!");
		return heap_[0];
	}

	const T &min() const
	{
		if (empty())
			throw std::underflow_error("Heap is empty. No min-element can be retrieved!");
		if (heap_.size() == 1)
			return heap_[0];
		if (heap_.size() == 2)
			return heap_[1];
		return comparator_(heap_[1], heap_[2]) ? heap_[1] : heap_[2];
	}

	void pop_min()
	{
		if (empty())
			throw std::underflow_error("Heap is empty. No min-element can be popped!");
		int min_index = heap_.size() == 1 ? 0 : heap_.size() == 2 ? 1 : comparator_(heap_[1], heap_[2]) ? 1 : 2;
		delete_element(min_index);
	}

	void pop_max()
	{
		if (empty())
			throw std::underflow_error("Heap is empty. No max-element can be popped!");
		delete_element(0);
	}


private:
	Container container_;
	Comparator comparator_;

	void delete_element(int index)
	{
		if (index >= heap_.size())
			throw std::underflow_error("Provided index is greater than heap size!");

		// The last element can be deleted without any additional operations
		if (index == heap_.size() - 1) {
			heap_.pop_back();
			return;
		}
		// Put element to delete on last position
		std::swap(heap_[index], heap_[heap_.size() - 1]);
		heap_.pop_back();
		// Restore heap property
		trickle_down(index);
	}

	void trickle_up(int index)
	{
		if (index == 0)
			return;
		// parent is on opposite level than index (min <--> max)
		auto parentIndex = parent(index);
		const auto level = log2int(1 + index); // We add 1 since we can not deal with the zero (max) level in the log
		if (level & 1) // min level
		{
			if (comparator_(heap_[parentIndex], heap_[index])) {
				std::swap(heap_[parentIndex], heap_[index]);
				trickle_up_<true>(parentIndex);
			}
			else
				trickle_up_<false>(index);
		}
		else {
			if (comparator_(heap_[index], heap_[parentIndex])) {
				std::swap(heap_[parentIndex], heap_[index]);
				trickle_up_<false>(parentIndex);
			}
			else
				trickle_up_<true>(index);
		}
	}

	template<bool is_max_level>
	void trickle_up_(int index)
	{
		if (index == 0)
			return;
		auto parentIndex = parent(index);
		if (parentIndex == 0)
			return;
		auto grandParentIndex = parent(parentIndex);

		if (comparator_(heap_[index], heap_[grandParentIndex]) ^ is_max_level) {
			std::swap(heap_[grandParentIndex], heap_[index]);
			trickle_up_<is_max_level>(grandParentIndex);
		}

	}

	// In min-max heaps, the required ordering must be established between an element, its children, and its grandchildren.
	void trickle_down(int index)
	{
		const auto level = log2int(1 + index); // We add 1 since we can not deal with the zero (min) level in the log
		if (level & 1) // min level
		{
			trickle_down_<!is_max_level>(index);
		}
		else // max level
		{
			trickle_down_<is_max_level>(index);
		}
	}

	int parent(int index)
	{
		return (index - 1) / 2;
	}

	int left_child(int index)
	{
		return 2 * index + 1;
	}

	int right_child(int index)
	{
		return 2 * index + 2;
	}

	template<bool is_max_level>
	void trickle_down_(int index)
	{
		if (index >= heap_.size()) {
			throw std::invalid_argument("Index value " + std::to_string(index) + "does not exist!");
		}
		auto leftChild = left_child(index);
		auto rightChild = right_child(index);
		// Determine the child to compare
		auto childToCompare = index;
		if (leftChild < heap_.size() && (is_max_level ^ comparator_(container_[leftChild], container_[index])))
			childToCompare = leftChild;
		if (rightChild < heap_.size() && (is_max_level ^ comparator_(container_[rightChild], container_[index])))
			childToCompare = rightChild;
		// Determine the grandchild to compare. All grandchildren lie next to each other in memory.
		auto leftLeftGrandChild = left_child(leftChild);
		bool grandChildWasChosen{false};
		for (int i{}; i < 4 && leftLeftGrandChild + i < heap_.size(); ++i)
			if (compare_(heap_[leftLeftGrandChild + i], heap_[childToCompare]) ^ is_max_level) {
				childToCompare = leftLeftGrandChild + i;
				grandChildWasChosen = true;
			}
		// Are we already at the right position?
		if (index == childToCompare)
			return;
		std::swap(heap_[childToCompare], heap_[index]);

		if (grandChildWasChosen) {
			if (comparator_(heap_[parent(childToCompare)], heap_[childToCompare]) ^ is_max_level)
				std::swap(heap_[parent(childToCompare)], heap_[childToCompare]);
			trickle_down_<is_max_level>(childToCompare);
		}
	}

	// Compute the level for index i in the min-max-heap by using floor(log2int(i))
	int log2int(int n)
	{
		if (n == 0)
			throw std::domain_error("log2 of 0 is undefined!");
		int result{0};
		while (n > 1) {
			n >>= 1;
			result++;
		}
		return result;
	}
	static constexpr bool is_max_level{true};
	std::vector<T> heap_;
};

#endif //MAX_MIN_HEAP_H
