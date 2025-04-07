//
// Created by andreas on 07.04.25.
//
#include "../search_in_rotated_sorted_array.h"
#include "gtest/gtest.h"

TEST(TestSearchInRotatedSortedArray, simple1)
{
    std::vector<int> input{4, 5, 6, 7, 0, 1, 2};
    constexpr int target{0};
    constexpr int expected_result{4};
    EXPECT_EQ(search(input, target), expected_result);
}

TEST(TestSearchInRotatedSortedArray, simple2)
{
    std::vector<int> input{4, 5, 6, 7, 0, 1, 2};
    constexpr int target{3};
    constexpr int expected_result{-1};
    EXPECT_EQ(search(input, target), expected_result);
}

TEST(TestSearchInRotatedSortedArray, simple3)
{
    std::vector<int> input{4, 5, 6, 7, 0, 1, 2};
    constexpr int target{6};
    constexpr int expected_result{2};
    EXPECT_EQ(search(input, target), expected_result);
}

TEST(TestSearchInRotatedSortedArray, complex1)
{
    std::vector<int> input{
        284, 287, 289, 293, 295, 298, 0, 3, 8, 9, 10, 11, 12, 15, 17, 19, 20, 22, 26, 29, 30, 31, 35, 36, 37, 38, 42,
        43, 45, 50, 51, 54, 56, 58, 59, 60, 62, 63, 68, 70, 73, 74, 81, 83, 84, 87, 92, 95, 99, 101, 102, 105, 108, 109,
        112, 114, 115, 116, 122, 125, 126, 127, 129, 132, 134, 136, 137, 138, 139, 147, 149, 152, 153, 154, 155, 159,
        160, 161, 163, 164, 165, 166, 168, 169, 171, 172, 174, 176, 177, 180, 187, 188, 190, 191, 192, 198, 200, 203,
        204, 206, 207, 209, 210, 212, 214, 216, 221, 224, 227, 228, 229, 230, 233, 235, 237, 241, 242, 243, 244, 246,
        248, 252, 253, 255, 257, 259, 260, 261, 262, 265, 266, 268, 269, 270, 271, 272, 273, 277, 279, 281
    };
    constexpr int target{235};
    constexpr int expected_result{113};
    EXPECT_EQ(search(input, target), expected_result);
}
