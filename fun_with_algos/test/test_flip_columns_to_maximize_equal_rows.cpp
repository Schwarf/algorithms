//
// Created by andreas on 25.11.24.
//

#include "flip_columns_to_maximize_equal_rows.h"
#include "gtest/gtest.h"


TEST(TestFlipColumnsToMaximizeRows, simple1)
{
    std::vector<std::vector<int>> matrix{{0, 1}, {1, 1}};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, maximize_equal_rows(matrix));
}

TEST(TestFlipColumnsToMaximizeRows, simple2)
{
    std::vector<std::vector<int>> matrix{{0, 1}, {1, 0}};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, maximize_equal_rows(matrix));
}


TEST(TestFlipColumnsToMaximizeRows, simple3)
{
    std::vector<std::vector<int>> matrix{{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, maximize_equal_rows(matrix));
}
