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

TEST(SortJumbledNumber1, simple2) {
    std::vector<unsigned short> mapping{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<unsigned short> values{789, 456, 123};
    std::vector<unsigned short> expected_result{123, 456, 789};
    EXPECT_EQ(expected_result, sort_jumbled_numbers(mapping, values));
}

TEST(SortJumbledNumber1, simple3) {
    std::vector<unsigned int> mapping{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<unsigned int> values{0, 999999999};
    std::vector<unsigned int> expected_result{0, 999999999};
    EXPECT_EQ(expected_result, sort_jumbled_numbers(mapping, values));
}

TEST(SortJumbledNumber1, simple4) {
    std::vector<unsigned int> mapping{3, 4, 8, 1, 0, 7, 9, 6, 5, 2};
    std::vector<unsigned int> values{8528, 50, 66634, 800991114, 39806, 3822, 624620, 88631070, 546691, 11, 9562};
    std::vector<unsigned int> expected_result{11, 50, 3822, 9562, 8528, 39806, 66634, 546691, 624620, 88631070,
                                              800991114};
    EXPECT_EQ(expected_result, sort_jumbled_numbers(mapping, values));
}

TEST(SortJumbledNumber1, simple5) {
    std::vector<unsigned int> mapping{9, 0, 3, 6, 8, 2, 4, 1, 5, 7};
    std::vector<unsigned int> values{87986890, 9191, 875, 88453, 481839962, 140741, 544020, 8955228, 88, 9418050,
                                     88238166, 47, 15621, 2318, 2991, 128, 465455032, 457, 2482, 7344939, 770};
    std::vector<unsigned int> expected_result{128, 88, 47, 770, 875, 457, 15621, 2318, 2991, 2482, 9191, 88453, 140741,
                                              544020, 7344939, 8955228, 9418050, 87986890, 88238166, 465455032,
                                              481839962};
    EXPECT_EQ(expected_result, sort_jumbled_numbers(mapping, values));
}