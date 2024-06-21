//
// Created by andreas on 21.06.24.
//
#include "gtest/gtest.h"
#include "./../minimum_number_of_days.h"

TEST(TestMinimumNumberOfDays, simple1) {
    std::vector<int> bloom_days{1, 10, 3, 10, 2};
    constexpr int flowers_per_bouquet{3};
    constexpr int number_of_bouquets{1};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, minimal_days(bloom_days, flowers_per_bouquet, number_of_bouquets));
}

TEST(TestMinimumNumberOfDays, simple2) {
    std::vector<int> bloom_days{1, 10, 3, 10, 2};
    constexpr int flowers_per_bouquet{3};
    constexpr int number_of_bouquets{2};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, minimal_days(bloom_days, flowers_per_bouquet, number_of_bouquets));
}