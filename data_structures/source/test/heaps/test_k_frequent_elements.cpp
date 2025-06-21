//
// Created by andreas on 21.06.25.
//
#include "heaps/k_frequent_elements.h"
#include "gtest/gtest.h"

TEST(TestKFrequentElements, simple1)
{
    std::vector<int> input{1, 1, 1, 2, 2, 3};
    constexpr int k = 2;
    std::vector<int> expected_result{1, 2};
    EXPECT_EQ(expected_result, k_frequent_elements(input, k));
}

TEST(TestKFrequentElements, simple2)
{
    std::vector<int> input{1, 1, 1, 2, 2, 3};
    constexpr int k = 4;
    std::vector<int> expected_result{1, 2, 3};
    EXPECT_EQ(expected_result, k_frequent_elements(input, k));
}

TEST(TestKFrequentElements, simple3)
{
    std::vector<int> input{1, 2, 2, 2, 3, 3};
    constexpr int k = 1;
    std::vector<int> expected_result{2};
    EXPECT_EQ(expected_result, k_frequent_elements(input, k));
}

TEST(TestKFrequentElements, simple4)
{
    std::vector<int> input{1, 2, 2, 3, 4, 4};
    constexpr int k = 0;
    std::vector<int> expected_result{};
    EXPECT_EQ(expected_result, k_frequent_elements(input, k));
}
