//
// Created by andreas on 14.07.23.
//

#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H
#include <concepts>
#include <vector>
#include <unordered_map>
#include "./../data_structures/source/hash_functions/hash_function_for_pairs.h"

template<typename ValueType, typename WeightType> requires std::is_arithmetic_v<ValueType>
	&& std::is_arithmetic_v<WeightType>
struct Item
{
	ValueType value;
	WeightType weight;
};

template<typename ValueType, typename WeightType>
requires std::is_arithmetic_v<ValueType>
	&& std::is_arithmetic_v<WeightType>
int knapsack_problem_recursive(const std::vector<Item<ValueType, WeightType>> &items,
							   WeightType knapsack_capacity,
							   int number_of_items = -1)
{
	if (number_of_items == -1)
		number_of_items = items.size();
	if (knapsack_capacity == WeightType{} || number_of_items == 0)
		return 0;
	// Exclude if item weight is larger than remaining knapsack capacity
	if (items[number_of_items - 1].weight > knapsack_capacity)
		return knapsack_problem_recursive(items, knapsack_capacity, number_of_items - 1);

	auto remaining_capacity = knapsack_capacity - items[number_of_items - 1].weight;
	ValueType include_item = items[number_of_items - 1].value + knapsack_problem_recursive(items, remaining_capacity,
																						   number_of_items - 1);
	ValueType exclude_item = knapsack_problem_recursive(items, knapsack_capacity, number_of_items - 1);

	return std::max(include_item, exclude_item);
}

template<typename ValueType, typename WeightType>
requires std::is_arithmetic_v<ValueType>
	&& std::is_arithmetic_v<WeightType>
int memoization(std::vector<Item<ValueType, WeightType>> &items,
				WeightType knapsack_capacity,
				std::unordered_map<std::pair<int, WeightType>,
								   ValueType,
								   non_commutative_pair_hash<int, WeightType>> &memo,
				int number_of_items = -1)
{
	if (number_of_items == -1)
		number_of_items = items.size();
	if (knapsack_capacity == WeightType{} || number_of_items == 0)
		return 0;
	// Check if this capacity with this number of items was computed before
	std::pair<int, WeightType> key = std::make_pair<int, WeightType>(number_of_items, knapsack_capacity);
	if (memo.find(key) != memo.end())
		return memo[key];

	if (items[number_of_items - 1].weight > knapsack_capacity)
		return memoization(items, knapsack_capacity, memo, number_of_items - 1);

	auto remaining_capacity = knapsack_capacity - items[number_of_items - 1].weight;

	ValueType include_item = items[number_of_items - 1].value + memoization(items, remaining_capacity, memo,
																			number_of_items - 1);

	ValueType exclude_item = memoization(items, knapsack_capacity, memo, number_of_items - 1);

	auto result = std::max(include_item, exclude_item);
	memo[key] = result;

	return result;

}

template<typename ValueType, typename WeightType>
requires std::is_arithmetic_v<ValueType>
	&& std::is_arithmetic_v<WeightType>
int knapsack_problem_top_down(const std::vector<Item<ValueType, WeightType>> &items, WeightType knapsack_capacity)
{
	std::unordered_map<std::pair<int, WeightType>, ValueType, non_commutative_pair_hash<int, WeightType>>
		memo;
	return memoization(items, knapsack_capacity, memo);
}


#endif //KNAPSACK_PROBLEM_H
