//
// Created by andreas on 01.03.23.
//
#include "test_setup.h"
#include "counting_sort.h"

TEST_F(SetupSortingTests, counting_sort_int_vector) {
    int min_value = -1000;
    int max_value = 1000;
    auto result = get_N_random_number_vector(min_value, max_value, 1000);
    auto expected_result = result;
    EXPECT_EQ(result, expected_result);
    std::sort(expected_result.begin(), expected_result.end());
    EXPECT_NE(result, expected_result);
    counting_sort(result, max_value, min_value);
    EXPECT_EQ(result, expected_result);
}

