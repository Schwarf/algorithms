//
// Created by andreas on 15.03.24.
//
#include "gtest/gtest.h"
#include "./../product_of_array_but_current_index_value.h"

TEST(TestProductOfArrayButCurrentIndexValue, simple1)
{
    const std::vector<float> input{1.f, 2.f, 3.f, 4.f};
    const std::vector<float> expected_result{24.f, 12.f, 8.f, 6.f};
    EXPECT_EQ(expected_result, product_of_array_but_current_index_value(input));
}

TEST(TestProductOfArrayButCurrentIndexValue, simple2)
{
    const std::vector<int> input{1, 1, 0, 4, 5};
    const std::vector<int> expected_result{0, 0, 20, 0, 0};
    EXPECT_EQ(expected_result, product_of_array_but_current_index_value(input));
}

TEST(TestProductOfArrayButCurrentIndexValue, simple3)
{
    const std::vector<int>
        input{2, 4, -2, 1, 2, -1, 4, 1, 3, -3, -1, 2, 1, 2, 1, -3, 1, -1, 1, 3, 3, -2, -2, 3, -3, -1, 1, -2, -4, -2};
    const std::vector<int> expected_result
    {
        -35831808, -17915904, 35831808, -71663616, -35831808, 71663616, -17915904, -71663616, -23887872, 23887872,
        71663616, -35831808, -71663616, -35831808, -71663616, 23887872, -71663616, 71663616, -71663616, -23887872,
        -23887872, 35831808, 35831808, -23887872, 23887872, 71663616, -71663616, 35831808, 17915904, 35831808
    };
    EXPECT_EQ(expected_result, product_of_array_but_current_index_value(input));
}
