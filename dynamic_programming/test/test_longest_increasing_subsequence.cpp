//
// Created by andreas on 08.08.22.
//
#include <vector>
#include "gtest/gtest.h"
#include "longest_increasing_subsequence.h"

class SetupLongestIncreasingSubsequence : public testing::Test
{
protected:
    std::vector<int> input1{10, 9, 2, 5, 3, 7, 101, 18};
    int result1{4};
    std::vector<int> input2{0, 1, 0, 3, 2, 3};
    int result2{4};
    std::vector<int> input3{1, 12, 419, 181, 17, 19, 0, 71, 26, 1, 2, 3, 4, 5, 6, 7};
    int result3{8};
    std::vector<int> input4{2, 1, 4, 3, 5, 6};
    int result4{4};
    std::vector<int> input5{10, 9, 18, 22, 78, 1, 4, 3, 5, 6, 10, 11, 12};
    int result5{7};
    std::vector<int> input6
    {
        -813, 82, -728, -82, -432, 887, -551, 324, -315, 306, -164, -499, -873, -613, 932, 177, 61, 52, 1000, -710,
        372, -306, -584, -332, -500, 407, 399, -648, 290, -866, 222, 562, 993, -338, -590, 303, -16, -134, 226,
        -648,
        909, 582, 177, 899, -343, 55, 629, 248, 333, 1, -921, 143, 629, 981, -435, 681, 844, 349, 613, 457, 797,
        695,
        485, 15, 710, -450, -775, 961, -445, -905, 466, 942, 995, -289, -397, 434, -14, 34, -903, 314, 862, -441,
        507,
        -966, 525, 624, -706, 39, 152, 536, 874, -364, 747, -35, 446, -608, -554, -411, 987, -354, -700, -34, 395,
        -977, 544, -330, 596, 335, -612, 28, 586, 228, -664, -841, -999, -100, -620, 718, 489, 346, 450, 772, 941,
        952,
        -560, 58, 999, -879, 396, -101, 897, -1000, -566, -296, -555, 938, 941, 475, -260, -52, 193, 379, 866, 226,
        -611, -177, 507, 910, -594, -856, 156, 71, -946, -660, -716, -295, -927, 148, 620, 201, 706, 570, -659,
        174,
        637, -293, 736, -735, 377, -687, -962, 768, 430, 576, 160, 577, -329, 175, 51, 699, -113, 950, -364, 383,
        5,
        748, -250, -644, -576, -227, 603, 832, -483, -237, 235, 893, -336, 452, -526, 372, -418, 356, 325, -180,
        134,
        -698
    };
    int result6{25};
};


TEST_F(SetupLongestIncreasingSubsequence, bottom_up_scenario1)
{
    auto output1 = size_of_longest_increasing_subsequence_bottom_up(input1);
    EXPECT_EQ(result1, output1);
}

TEST_F(SetupLongestIncreasingSubsequence, bottom_up_scenario2)
{
    auto output2 = size_of_longest_increasing_subsequence_bottom_up(input2);
    EXPECT_EQ(result2, output2);
}

TEST_F(SetupLongestIncreasingSubsequence, bottom_up_scenario3)
{
    auto output3 = size_of_longest_increasing_subsequence_bottom_up(input3);
    EXPECT_EQ(result3, output3);
}

TEST_F(SetupLongestIncreasingSubsequence, bottom_up_scenario4)
{
    auto output4 = size_of_longest_increasing_subsequence_bottom_up(input4);
    EXPECT_EQ(result4, output4);
}

TEST_F(SetupLongestIncreasingSubsequence, bottom_up_scenario5)
{
    auto output5 = size_of_longest_increasing_subsequence_bottom_up(input5);
    EXPECT_EQ(result5, output5);
}

TEST_F(SetupLongestIncreasingSubsequence, bottom_up_scenario6)
{
    auto output6 = size_of_longest_increasing_subsequence_bottom_up(input6);
    EXPECT_EQ(result6, output6);
}


TEST_F(SetupLongestIncreasingSubsequence, tail_list_scenario1)
{
    auto output1 = size_of_longest_increasing_subsequence_tail_list(input1);
    EXPECT_EQ(result1, output1);
}

TEST_F(SetupLongestIncreasingSubsequence, tail_list_scenario2)
{
    auto output2 = size_of_longest_increasing_subsequence_tail_list(input2);
    EXPECT_EQ(result2, output2);
}

TEST_F(SetupLongestIncreasingSubsequence, tail_list_scenario3)
{
    auto output3 = size_of_longest_increasing_subsequence_tail_list(input3);
    EXPECT_EQ(result3, output3);
}

TEST_F(SetupLongestIncreasingSubsequence, tail_list_scenario4)
{
    auto output4 = size_of_longest_increasing_subsequence_tail_list(input4);
    EXPECT_EQ(result4, output4);
}

TEST_F(SetupLongestIncreasingSubsequence, tail_list_scenario5)
{
    auto output5 = size_of_longest_increasing_subsequence_tail_list(input5);
    EXPECT_EQ(result5, output5);
}

TEST_F(SetupLongestIncreasingSubsequence, tail_list_scenario6)
{
    auto output6 = size_of_longest_increasing_subsequence_tail_list(input6);
    EXPECT_EQ(result6, output6);
}


TEST_F(SetupLongestIncreasingSubsequence, recursive_implementation_scenario1)
{
    auto output1 = size_of_longest_increasing_subsequence_recursive(input1);
    EXPECT_EQ(result1, output1);
}

TEST_F(SetupLongestIncreasingSubsequence, recursive_implementation_scenario2)
{
    auto output2 = size_of_longest_increasing_subsequence_recursive(input2);
    EXPECT_EQ(result2, output2);
}

TEST_F(SetupLongestIncreasingSubsequence, recursive_implementation_scenario3)
{
    auto output3 = size_of_longest_increasing_subsequence_recursive(input3);
    EXPECT_EQ(result3, output3);
}

TEST_F(SetupLongestIncreasingSubsequence, recursive_implementation_scenario4)
{
    auto output4 = size_of_longest_increasing_subsequence_recursive(input4);
    EXPECT_EQ(result4, output4);
}

TEST_F(SetupLongestIncreasingSubsequence, recursive_implementation_scenario5)
{
    auto output5 = size_of_longest_increasing_subsequence_recursive(input5);
    EXPECT_EQ(result5, output5);
}

// Takes to long
//TEST_F(SetupLongestIncreasingSubsequence, recursive_implementation_scenario6)
//{
//	auto output6 = size_of_longest_increasing_subsequence_recursive(input6);
//	EXPECT_EQ(result6, output6);
//}


TEST_F(SetupLongestIncreasingSubsequence, top_down_implementation_scenario1)
{
    auto output1 = size_of_longest_increasing_subsequence_top_down(input1);
    EXPECT_EQ(result1, output1);
}

TEST_F(SetupLongestIncreasingSubsequence, top_down_implementation_scenario2)
{
    auto output2 = size_of_longest_increasing_subsequence_top_down(input2);
    EXPECT_EQ(result2, output2);
}

TEST_F(SetupLongestIncreasingSubsequence, top_down_implementation_scenario3)
{
    auto output3 = size_of_longest_increasing_subsequence_top_down(input3);
    EXPECT_EQ(result3, output3);
}

TEST_F(SetupLongestIncreasingSubsequence, top_down_implementation_scenario4)
{
    auto output4 = size_of_longest_increasing_subsequence_top_down(input4);
    EXPECT_EQ(result4, output4);
}

TEST_F(SetupLongestIncreasingSubsequence, top_down_implementation_scenario5)
{
    auto output5 = size_of_longest_increasing_subsequence_top_down(input5);
    EXPECT_EQ(result5, output5);
}

TEST_F(SetupLongestIncreasingSubsequence, top_down_implementation_scenario6)
{
    auto output6 = size_of_longest_increasing_subsequence_top_down(input6);
    EXPECT_EQ(result6, output6);
}
