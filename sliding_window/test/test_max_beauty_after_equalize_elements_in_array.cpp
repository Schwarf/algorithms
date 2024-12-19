//
// Created by andreas on 19.12.24.
//
#include "max_beauty_after_equalize_elements_in_array.h"
#include "gtest/gtest.h"

TEST(TestMaxBeautyAfterEqualizeElementsInArray, simple1)
{
    std::vector<int> input{4, 6, 1, 2};
    constexpr int k{2};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, max_beauty(input, k));
}

TEST(TestMaxBeautyAfterEqualizeElementsInArray, simple2)
{
    std::vector<int> input{1, 1, 1, 1};
    constexpr int k{10};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, max_beauty(input, k));
}

TEST(TestMaxBeautyAfterEqualizeElementsInArray, simple3)
{
    std::vector<int> input{5, 65, 9, 36, 96, 44, 24, 50, 20, 46, 29};
    constexpr int k{18};
    constexpr int expected_result{7};
    EXPECT_EQ(expected_result, max_beauty(input, k));
}


TEST(TestMaxBeautyAfterEqualizeElementsInArray, complex1)
{
    std::vector<int> input{
        123, 993, 494, 252, 183, 223, 264, 18, 737, 521, 30, 512, 726, 486, 920, 330, 412, 108, 185, 476, 76, 636, 369,
        757, 182, 296, 235, 754, 284, 286, 348, 457, 673, 304, 825, 501, 345, 35, 238, 387, 126, 21, 342, 515, 349, 659,
        887, 717, 26, 588, 746, 663, 871, 618, 493, 177, 430, 718, 485, 291, 669, 424, 424, 161, 659, 160, 511, 792,
        989, 699, 232, 975, 47, 430, 367, 811, 540, 172, 968, 214, 96, 509, 530, 188, 647, 662, 384, 619, 293, 824, 113,
        970, 107, 445, 255, 496, 103, 989, 655, 321, 489, 533, 873, 809, 940, 727, 972, 56, 322, 277, 468, 238, 972,
        538, 250, 528, 113, 854, 557, 967, 441, 323, 795, 481, 626, 42, 888, 748, 849, 109, 940, 209, 729, 779, 986,
        597, 969, 346, 721
    };
    constexpr int k{6};
    constexpr int expected_result{7};
    EXPECT_EQ(expected_result, max_beauty(input, k));
}
