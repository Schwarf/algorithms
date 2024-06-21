//
// Created by andreas on 21.06.24.
//
#include "gtest/gtest.h"
#include "./../minimum_number_of_days.h"

TEST(TestMinimumNumberOfDays, simple1) {
    std::vector<int> bloom_days{1, 10, 3, 10, 2};
    constexpr int flowers_per_bouquet{1};
    constexpr int number_of_bouquets{3};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, minimal_days(bloom_days, number_of_bouquets, flowers_per_bouquet));
}

TEST(TestMinimumNumberOfDays, simple2) {
    std::vector<int> bloom_days{1, 10, 3, 10, 2};
    constexpr int flowers_per_bouquet{3};
    constexpr int number_of_bouquets{2};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, minimal_days(bloom_days, number_of_bouquets, flowers_per_bouquet));
}

TEST(TestMinimumNumberOfDays, simple3) {
    std::vector<int> bloom_days{7, 7, 7, 7, 12, 7, 7};
    constexpr int flowers_per_bouquet{3};
    constexpr int number_of_bouquets{2};
    constexpr int expected_result{12};
    EXPECT_EQ(expected_result, minimal_days(bloom_days, number_of_bouquets, flowers_per_bouquet));
}

TEST(TestMinimumNumberOfDays, medium1) {
    std::vector<int> bloom_days{62, 75, 98, 63, 47, 65, 51, 87, 22, 27, 73, 92, 76, 44, 13, 90, 100, 85};
    constexpr int flowers_per_bouquet{7};
    constexpr int number_of_bouquets{2};
    constexpr int expected_result{98};
    EXPECT_EQ(expected_result, minimal_days(bloom_days, number_of_bouquets, flowers_per_bouquet));
}

TEST(TestMinimumNumberOfDays, medium2) {
    std::vector<int> bloom_days{33, 92, 79, 46, 18, 64, 70, 33, 48, 43, 39, 45, 44, 41, 24, 25, 99, 27, 75, 72, 95};
    constexpr int flowers_per_bouquet{3};
    constexpr int number_of_bouquets{21};
    constexpr int expected_result{-1};
    EXPECT_EQ(expected_result, minimal_days(bloom_days, number_of_bouquets, flowers_per_bouquet));
}

TEST(TestMinimumNumberOfDays, complex1) {
    std::vector<int> bloom_days{36, 64, 44, 2, 91, 64, 29, 56, 20, 32, 92, 8, 74, 96, 27, 67, 75, 26, 49, 1, 90, 37, 71,
                                63, 60, 75, 67, 49, 53, 86, 93, 59, 79, 47, 3, 29, 99, 53, 87, 64, 21, 50, 10, 1, 85,
                                33, 98, 45, 62, 3, 59, 58, 92, 8, 35, 67, 90, 100, 97, 95, 89, 10, 75, 61, 86, 4, 93,
                                31};
    constexpr int flowers_per_bouquet{4};
    constexpr int number_of_bouquets{17};
    constexpr int expected_result{100};
    EXPECT_EQ(expected_result, minimal_days(bloom_days, number_of_bouquets, flowers_per_bouquet));
}
