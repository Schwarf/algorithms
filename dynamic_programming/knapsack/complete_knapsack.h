//
// Created by andreas on 18.05.25.
//

#ifndef COMPLETE_KNAPSACK_H
#define COMPLETE_KNAPSACK_H
// The complete knapsack model is similar to the 0-1 knapsack, the only difference from the 0-1 knapsack is that an
// item can be selected an unlimited number of times instead of only once.
#include "knapsack_problem_0_1.h"

template <typename ValueType, typename WeightType>
    requires std::is_arithmetic_v<ValueType> && std::is_integral_v<WeightType>
ValueType complete_knapsack_problem_bottom_up(const std::vector<Item<ValueType, WeightType>>& items,
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
                    std::max(items[i - 1].value + dp[i][weight - items[i - 1].weight], dp[i][weight]);
            }
        }
    }
    return dp[number_of_items][knapsack_capacity];
}


#endif //COMPLETE_KNAPSACK_H
