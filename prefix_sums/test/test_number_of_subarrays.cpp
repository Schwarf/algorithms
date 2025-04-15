//
// Created by andreas on 22.06.24.
//

#include "gtest/gtest.h"
#include "./../number_of_subarrays.h"

TEST(TestNumberOfSubArrays, simple1)
{
    std::vector<int> input{1, 1, 2, 1, 1};
    constexpr int number_of_required_odd_elements{3};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, number_of_sub_arrays(input, number_of_required_odd_elements));
}

TEST(TestNumberOfSubArrays, simple2)
{
    std::vector<int> input{2, 4, 6};
    constexpr int number_of_required_odd_elements{1};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, number_of_sub_arrays(input, number_of_required_odd_elements));
}

TEST(TestNumberOfSubArrays, simple3)
{
    std::vector<int> input{1, 1, 1, 3, 5};
    constexpr int number_of_required_odd_elements{1};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, number_of_sub_arrays(input, number_of_required_odd_elements));
}

TEST(TestNumberOfSubArrays, simple4)
{
    std::vector<int> input{1, 1, 1, 3, 5};
    constexpr int number_of_required_odd_elements{2};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, number_of_sub_arrays(input, number_of_required_odd_elements));
}

TEST(TestNumberOfSubArrays, simple5)
{
    std::vector<int> input{2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    constexpr int number_of_required_odd_elements{2};
    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, number_of_sub_arrays(input, number_of_required_odd_elements));
}

TEST(TestNumberOfSubArrays, simple6)
{
    std::vector<int> input{
        45627, 50891, 94884, 11286, 35337, 46414, 62029, 20247, 72789, 89158, 54203, 79628, 25920,
        16832, 47469, 80909
    };
    constexpr int number_of_required_odd_elements{1};
    constexpr int expected_result{28};
    EXPECT_EQ(expected_result, number_of_sub_arrays(input, number_of_required_odd_elements));
}
