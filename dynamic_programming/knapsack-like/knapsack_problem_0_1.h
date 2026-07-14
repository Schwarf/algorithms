//
// Created by andreas on 14.07.23.
//

#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H

#include <algorithm>
#include <optional>
#include <unordered_map>
#include <vector>
#include "./../data_structures/source/hash_functions/hash_function_for_pairs.h"

// 0/1 Knapsack Problem
//
// Given a collection of items, where each item has a value and an integer weight,
// and a knapsack with a fixed maximum capacity, determine the maximum total value
// that can be obtained without exceeding the knapsack capacity.
//
// Each item can either be selected once or not selected at all. Items cannot be
// split and cannot be selected multiple times.
//
// Formally, choose a subset of items such that:
//   - the sum of their weights is at most knapsack_capacity, and
//   - the sum of their values is maximized.
//
// This file provides several solutions to the problem:
//   - a naive recursive implementation,
//   - a top-down dynamic-programming implementation using memoization,
//   - a bottom-up dynamic-programming implementation, and
//   - a memory-optimized bottom-up dynamic-programming implementation.

template <typename ValueType, std::integral WeightType>
    requires std::is_arithmetic_v<ValueType>
struct Item
{
    ValueType value;
    WeightType weight;
};

template <typename ValueType, std::integral WeightType>
    requires std::is_arithmetic_v<ValueType>
ValueType knapsack_problem_recursive(const std::vector<Item<ValueType, WeightType>>& items,
                                     WeightType knapsack_capacity, int item_index = -1)
{
    // Default initialize to last item if no item index is provided
    if (item_index == -1)
        item_index = items.size();

    constexpr WeightType Zero{};
    if (knapsack_capacity == Zero || item_index == 0)
        return 0;

    // Exclude if item weight is larger than remaining knapsack capacity
    if (items[item_index - 1].weight > knapsack_capacity)
        return knapsack_problem_recursive(items, knapsack_capacity, item_index - 1);

    auto remaining_capacity = knapsack_capacity - items[item_index - 1].weight;
    ValueType include_item =
        items[item_index - 1].value + knapsack_problem_recursive(items, remaining_capacity, item_index - 1);
    ValueType exclude_item = knapsack_problem_recursive(items, knapsack_capacity, item_index - 1);

    return std::max(include_item, exclude_item);
}

template <typename ValueType, std::integral WeightType>
    requires std::is_arithmetic_v<ValueType>
ValueType memoization(const std::vector<Item<ValueType, WeightType>>& items, WeightType knapsack_capacity,
                      std::vector<std::vector<std::optional<ValueType>>>& memo, int item_index)
{
    // Default initialize to last item if no item index is provided

    constexpr WeightType Zero{};
    if (knapsack_capacity == Zero || item_index == 0)
        return 0;

    // Check if this capacity with this number of items was computed before
    auto& cached_result = memo[item_index][knapsack_capacity];

    if (cached_result.has_value())
        return *cached_result;

    const auto current_item = items[item_index - 1];

    if (current_item.weight > knapsack_capacity)
    {
        cached_result = memoization(items, knapsack_capacity, memo, item_index - 1);
        return *cached_result;
    }

    auto remaining_capacity = knapsack_capacity - current_item.weight;

    ValueType include_item = current_item.value + memoization(items, remaining_capacity, memo, item_index - 1);
    ValueType exclude_item = memoization(items, knapsack_capacity, memo, item_index - 1);

    cached_result = std::max(include_item, exclude_item);

    return *cached_result;
}

template <typename ValueType, std::integral WeightType>
    requires std::is_arithmetic_v<ValueType>
ValueType knapsack_problem_top_down(const std::vector<Item<ValueType, WeightType>>& items, WeightType knapsack_capacity)
{
    std::vector<std::vector<std::optional<ValueType>>> memo(
        items.size() + 1, std::vector<std::optional<ValueType>>(knapsack_capacity + 1));
    return memoization(items, knapsack_capacity, memo, items.size());
}

template <typename ValueType, std::integral WeightType>
    requires std::is_arithmetic_v<ValueType>
ValueType knapsack_problem_bottom_up(const std::vector<Item<ValueType, WeightType>>& items,
                                     WeightType knapsack_capacity)
{
    int number_of_items = items.size();
    std::vector<std::vector<ValueType>> dp(number_of_items + 1, std::vector<ValueType>(knapsack_capacity + 1, 0));
    for (int i{1}; i <= number_of_items; ++i)
    {
        for (WeightType weight{1}; weight <= knapsack_capacity; ++weight)
        {
            dp[i][weight] = dp[i - 1][weight];
            if (items[i - 1].weight <= weight)
            {
                dp[i][weight] =
                    std::max(items[i - 1].value + dp[i - 1][weight - items[i - 1].weight], dp[i - 1][weight]);
            }
        }
    }
    return dp[number_of_items][knapsack_capacity];
}

// Memory optimized version
template <typename ValueType, std::integral WeightType>
    requires std::is_arithmetic_v<ValueType>
ValueType knapsack_problem_bottom_up_optimized(const std::vector<Item<ValueType, WeightType>>& items,
                                               WeightType knapsack_capacity)
{
    const int number_of_items = items.size();
    // Use two 1D arrays for the previous and current rows
    std::vector<ValueType> dp_previous(knapsack_capacity + 1, 0);
    std::vector<ValueType> dp_current(knapsack_capacity + 1, 0);

    for (int i = 1; i <= number_of_items; ++i)
    {
        for (WeightType weight = 1; weight <= knapsack_capacity; ++weight)
        {
            // Option 1: Don't take the current item
            dp_current[weight] = dp_previous[weight];

            // Option 2: Take the current item (if it fits)
            if (items[i - 1].weight <= weight)
            {
                dp_current[weight] =
                    std::max(items[i - 1].value + dp_previous[weight - items[i - 1].weight], dp_previous[weight]);
            }
        }

        // After processing the current row, swap dp_prev and dp_curr
        std::swap(dp_previous, dp_current);
    }

    return dp_previous[knapsack_capacity]; // Final answer is in dp_prev
}

// Old code using hashmap in top-down approach
//
// template <typename ValueType, typename WeightType>
//     requires std::is_arithmetic_v<ValueType> && std::is_integral_v<WeightType>
// ValueType memoization(const std::vector<Item<ValueType, WeightType>>& items,
//                       WeightType knapsack_capacity,
//                       std::unordered_map<std::pair<int, WeightType>,
//                                          ValueType,
//                                          non_commutative_pair_hash<int, WeightType>>& memo,
//                       int item_index = -1)
// {
//     if (item_index == -1)
//         item_index = items.size();
//     if (knapsack_capacity == WeightType{} || item_index == 0)
//         return 0;
//     // Check if this capacity with this number of items was computed before
//     std::pair<int, WeightType> key = std::make_pair(item_index, knapsack_capacity);
//     if (memo.find(key) != memo.end())
//         return memo[key];
//
//     if (items[item_index - 1].weight > knapsack_capacity)
//         return memoization(items, knapsack_capacity, memo, item_index - 1);
//
//     auto remaining_capacity = knapsack_capacity - items[item_index - 1].weight;
//
//     ValueType include_item = items[item_index - 1].value + memoization(items, remaining_capacity, memo,
//                                                                        item_index - 1);
//     ValueType exclude_item = memoization(items, knapsack_capacity, memo, item_index - 1);
//
//     auto result = std::max(include_item, exclude_item);
//     memo[key] = result;
//
//     return result;
// }
//
// template <typename ValueType, typename WeightType>
//     requires std::is_arithmetic_v<ValueType> && std::is_integral_v<WeightType>
// ValueType
// knapsack_problem_top_down(const std::vector<Item<ValueType, WeightType>>& items, WeightType knapsack_capacity)
// {
//     std::unordered_map<std::pair<int, WeightType>, ValueType, non_commutative_pair_hash<int, WeightType>>
//         memo;
//     return memoization(items, knapsack_capacity, memo);
// }

#endif // KNAPSACK_PROBLEM_H
