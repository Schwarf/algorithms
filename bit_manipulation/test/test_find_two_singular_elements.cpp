//
// Created by andreas on 31.05.24.
//

#include "gtest/gtest.h"
#include "./../find_two_singular_elements.h"
#include <ranges>

TEST(TestFindTwoSingularElements, simple1)
{
    std::vector<int> input{-2,1,2,1,2,4,4,6};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{-2,6};
    EXPECT_EQ(expected_result, result);
}


TEST(TestFindTwoSingularElements, simple2)
{
    std::vector<int> input{-2,0};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{-2,0};
    EXPECT_EQ(expected_result, result);
}

TEST(TestFindTwoSingularElements, complex1)
{
    std::vector<int> input{1,1,0,-2147483648};
    auto result = find_singular_elements(input);
    std::ranges::sort(result);
    const std::vector<int> expected_result{-2,0};
    EXPECT_EQ(expected_result, result);
}
