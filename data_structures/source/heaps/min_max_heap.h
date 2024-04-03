//
// Created by andreas on 03.04.24.
//

#ifndef MIN_MAX_HEAP_H
#define MIN_MAX_HEAP_H
#include <concepts>
#include <vector>

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

};

#endif //MIN_MAX_HEAP_H
