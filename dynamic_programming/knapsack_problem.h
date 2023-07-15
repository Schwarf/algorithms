//
// Created by andreas on 14.07.23.
//

#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H
#include <concepts>
#include <vector>
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
int knapsack_problem_recursive(std::vector<Item<ValueType, WeightType>> &items,
							   WeightType knapsack_capacity,
							   int number_of_items = -1)
{
	if (number_of_items == -1)
		number_of_items = items.size();
	if (knapsack_capacity == WeightType{} || number_of_items == 0)
		return 0;
	if (items[number_of_items - 1].weight > knapsack_capacity)
		return knapsack_problem_recursive(items, knapsack_capacity, number_of_items - 1);
	return std::max(items[number_of_items - 1].value + knapsack_problem_recursive(items,
																				  knapsack_capacity
																					  - items[number_of_items - 1]
																						  .weight,
																				  number_of_items - 1),
					knapsack_problem_recursive(items, knapsack_capacity, number_of_items - 1));
}
#endif //KNAPSACK_PROBLEM_H
