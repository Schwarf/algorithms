//
// Created by andreas on 28.07.24.
//
#include "graphs/minimum_cost_to_convert_string.h"
#include "gtest/gtest.h"

TEST(TestConversionCostsOfString, simple1) {
    std::string source{"abcd"};
    std::string target{"acbe"};
    std::vector<char> original{'a', 'b', 'c', 'c', 'e', 'd'};
    std::vector<char> changed{'b', 'c', 'b', 'e', 'b', 'e'};
    std::vector<int> costs{2, 5, 5, 1, 2, 20};
    constexpr long long expected_result{28};
    EXPECT_EQ(expected_result, minimum_cost_to_convert_string(source, target, original, changed, costs));
}