//
// Created by andreas on 22.02.23.
//

#include "gtest/gtest.h"

#include "./../first_appearance_in_sorted_vector.h"

TEST(FirstAppearance, target_occurs_multiple_times)
{
    std::vector<int> input{0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
    constexpr int target = 5;
    constexpr int expected_result = 10;

    EXPECT_EQ(expected_result, first_appearance_index(input, target));
}

TEST(FirstAppearance, target_is_last_element)
{
    std::vector<int> input{1, 2, 3};
    constexpr int target = 3;
    constexpr int expected_result = 2;

    EXPECT_EQ(expected_result, first_appearance_index(input, target));
}

TEST(FirstAppearance, target_is_first_element)
{
    std::vector<int> input{1, 1, 1, 2, 3};
    constexpr int target = 1;
    constexpr int expected_result = 0;

    EXPECT_EQ(expected_result, first_appearance_index(input, target));
}

TEST(FirstAppearance, target_greater_than_all_values_returns_minus_one)
{
    std::vector<int> input{0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
    constexpr int target = 11;
    constexpr int expected_result = -1;

    EXPECT_EQ(expected_result, first_appearance_index(input, target));
}

TEST(FirstAppearance, target_less_than_all_values_returns_minus_one)
{
    std::vector<int> input{0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
    constexpr int target = -1;
    constexpr int expected_result = -1;

    EXPECT_EQ(expected_result, first_appearance_index(input, target));
}

TEST(FirstAppearance, target_between_values_returns_minus_one)
{
    std::vector<int> input{1, 3, 5, 7};
    constexpr int target = 4;
    constexpr int expected_result = -1;

    EXPECT_EQ(expected_result, first_appearance_index(input, target));
}

TEST(FirstAppearance, empty_input_returns_minus_one)
{
    std::vector<int> input{};
    constexpr int target = -1;
    constexpr int expected_result = -1;

    EXPECT_EQ(expected_result, first_appearance_index(input, target));
}
