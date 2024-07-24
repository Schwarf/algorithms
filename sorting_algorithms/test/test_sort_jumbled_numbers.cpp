//
// Created by andreas on 24.07.24.
//
#include "gtest/gtest.h"
#include "sort_jumbled_numbers.h"

TEST(SortJumbledNumber1, simple1) {
    std::vector<unsigned short> mapping{8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    std::vector<unsigned short> values{991, 338, 38};
    std::vector<unsigned short> expected_result{338, 38, 991};
    EXPECT_EQ(expected_result, sort_jumbled_numbers(mapping, values));
}