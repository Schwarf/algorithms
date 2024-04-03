//
// Created by andreas on 03.04.24.
//

#ifndef MIN_MAX_HEAP_H
#define MIN_MAX_HEAP_H
#include <concepts>
#include <vector>
#include <stdexcept>

template<typename T>
concept Orderable = requires(T a, T b)
{
	{ a < b } -> std::convertible_to<bool>;
	{ a <= b } -> std::convertible_to<bool>;
	{ a > b } -> std::convertible_to<bool>;
	{ a >= b } -> std::convertible_to<bool>;
};

template<typename T> requires Orderable<T>
class min_max_heap
{


private:
	// In min-max heaps, the required ordering must be established between an element, its children, and its grandchildren.
	void trickle_down(int index)
	{
		const auto level = log2int(1 + index); // We add 1 since we can not deal with the zero (min) level in the log
		if (level & 1) {
			trickle_down_min(index);
		}
		else {
			trickle_down_max(index);
		}
	}

	int left_child(int index)
	{
		return 2 * index + 1;
	}

	int right_child(int index)
	{
		return 2 * index + 2;
	}

	void trickle_down_min(int index)
	{
		if (index >= heap_.size()) {
			throw std::invalid_argument("Index value " + std::to_string(index) + "does not exist!");
		}
		auto leftChild = left_child(index);
		if(leftChild < heap_.size() && leftChild+1 < heap_.size() && )
	}

	void trickle_down_max(int index)
	{

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

	std::vector<T> heap_;
};

#endif //MIN_MAX_HEAP_H
