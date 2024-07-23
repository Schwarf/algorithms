//
// Created by andreas on 23.07.24.
//
#include "gtest/gtest.h"
#include "sort_array_by_increasing_frequency.h"

TEST(SortArrayByFrequency, simple1)
{
    std::vector<int> input{1,1,2,2,2,3};
    std::vector<int> expected_result{3,1,1,2,2,2};
    sort_by_increasing_frequency(input);
    EXPECT_EQ(expected_result, input);
}
