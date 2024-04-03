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
	// Compute the level for index i in the min-max-heap by using floor(log2int(i))
	unsigned int log2int(unsigned int n)
	{
		if (n == 0U)
			throw std::domain_error("log2 of 0 is undefined!");
		unsigned int result{0U};
		while (n > 1U) {
			n >>= 1;
			result++;
		}
		return result;
	}

	std::vector<T> elements_;
};

#endif //MIN_MAX_HEAP_H
