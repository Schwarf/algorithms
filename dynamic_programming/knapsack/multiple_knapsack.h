//
// Created by andreas on 19.05.25.
//

#ifndef MULTIPLE_KNAPSACK_H
#define MULTIPLE_KNAPSACK_H
#include "knapsack_problem_0_1.h"

template <typename ValueType, typename WeightType>
    requires std::is_arithmetic_v<ValueType> && std::is_integral_v<WeightType>
struct ItemCounted : public Item<ValueType, WeightType>
{
    int count;
    // Constructor for ItemCounted
    ItemCounted(ValueType value, WeightType weight, int count)
        : Item<ValueType, WeightType>{value, weight}, count(count) {}
};

template <typename ValueType, typename WeightType>
    requires std::is_arithmetic_v<ValueType> && std::is_integral_v<WeightType>
ValueType multiple_knapsack_bottom_up(const std::vector<ItemCounted<ValueType, WeightType>>& items,
                                              WeightType knapsack_capacity)
{
    int number_of_items = items.size();
    std::vector<std::vector<ValueType>> dp(number_of_items + 1, std::vector<ValueType>(knapsack_capacity + 1, 0));

    // Loop over all items
    for (int i = 1; i <= number_of_items; ++i)
    {
        for (WeightType weight = 1; weight <= knapsack_capacity; ++weight)
        {
            dp[i][weight] = dp[i - 1][weight];
            // Try including multiple copies of the current item
            for (int copies = 1; copies <= items[i - 1].count; ++copies)
            {
                if (items[i - 1].weight * copies <= weight)
                {
                    dp[i][weight] = std::max(dp[i][weight],
                                             items[i - 1].value * copies + dp[i - 1][weight - items[i - 1].weight * copies]);
                }
                else
                {
                    break;  // No need to continue checking if item weight exceeds current weight
                }
            }
        }
    }

    return dp[number_of_items][knapsack_capacity];
}

template <typename ValueType, typename WeightType>
    requires std::is_arithmetic_v<ValueType> && std::is_integral_v<WeightType>
ValueType multiple_knapsack_bottom_up_optimized(const std::vector<ItemCounted<ValueType, WeightType>>& items,
                                              WeightType knapsack_capacity)
{
    int number_of_items = items.size();
    std::vector<ValueType> dp_current(knapsack_capacity + 1, {});
    std::vector<ValueType> dp_previous(knapsack_capacity + 1, {});

    // Loop over all items
    for (int i = 1; i <= number_of_items; ++i)
    {
        for (WeightType weight = 1; weight <= knapsack_capacity; ++weight)
        {
            dp_current[weight] = dp_previous[weight];
            // Try including multiple copies of the current item
            for (int copies = 1; copies <= items[i - 1].count; ++copies)
            {
                if (items[i - 1].weight * copies <= weight)
                {
                    dp_current[weight] = std::max(dp_current[weight],
                                             items[i - 1].value * copies + dp_previous[weight - items[i - 1].weight * copies]);
                }
                else
                {
                    break;  // No need to continue checking if item weight exceeds current weight
                }
            }
        }
        std::swap(dp_previous, dp_current);
    }

    return dp_previous[knapsack_capacity];
}

#endif //MULTIPLE_KNAPSACK_H
