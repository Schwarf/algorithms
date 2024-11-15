//
// Created by andreas on 08.07.23.
//
#include "gtest/gtest.h"
#include "./../pascal_triangle.h"

constexpr std::array<std::tuple<int, int, long long>, 12> pascal_triangle{
    std::make_tuple(0, 0, 1),
    std::make_tuple(1, 0, 1),
    std::make_tuple(1, 1, 1),
    std::make_tuple(4, 4, 1),
    std::make_tuple(5, 4, 5),
    std::make_tuple(6, 2, 15),
    std::make_tuple(6, 3, 20),
    std::make_tuple(6, 4, 15),
    std::make_tuple(24, 13, 2496144),
    std::make_tuple(37, 31, 2324784),
    std::make_tuple(38, 19, 35345263800),
    std::make_tuple(50, 24, 121548660036300)
};

class SetupPascalTriangle : public testing::TestWithParam<std::tuple<int, int, long long>>
{
};

INSTANTIATE_TEST_SUITE_P(BinomialCoefficients_Test, SetupPascalTriangle, ::testing::ValuesIn(pascal_triangle));

TEST_P(SetupPascalTriangle, compute_binomial_coefficient)
{
    const auto row = std::get<0>(GetParam());
    const auto column = std::get<1>(GetParam());
    const auto expected_value = std::get<2>(GetParam());
    EXPECT_EQ(expected_value, compute_binomial_coefficient(row, column));
}

TEST_P(SetupPascalTriangle, compute_binomial_coefficient_compile_time)
{
    const auto row = std::get<0>(GetParam());
    const auto column = std::get<1>(GetParam());
    const auto expected_value = std::get<2>(GetParam());
    EXPECT_EQ(expected_value, binomial_coefficients()[row][column]);
}
