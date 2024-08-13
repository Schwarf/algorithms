//
// Created by andreas on 13.08.24.
//

#include "gtest/gtest.h"
#include "./../find_all_summand_combinations_for_sum.h"

TEST(TestFindAllSumCombinations, simple1) {
    std::vector<int> input{10, 1, 2, 7, 6, 1, 5};
    constexpr int target{8};
    std::vector<std::vector<int>> expected_output{
            {1, 1, 6},
            {1, 2, 5},
            {1, 7},
            {2, 6}
    };
    EXPECT_EQ(find_all_combinations_brute_force(input, target), expected_output);
}

