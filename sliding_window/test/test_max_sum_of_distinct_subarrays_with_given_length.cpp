//
// Created by andreas on 21.11.24.
//

#include "max_sum_of_distinct_subarrays_with_given_length.h"
#include "gtest/gtest.h"

TEST(MaxSumOfSubarray, simple1)
{
    constexpr int subarray_length{3};
    std::vector<int> input{1,5,4,2,9,9,9};
    constexpr int expected_result{15};
    EXPECT_EQ(expected_result, max_subarray_sum(input, subarray_length));
}

TEST(MaxSumOfSubarray, simple2)
{
    constexpr int subarray_length{2};
    std::vector<int> input{3,3};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, max_subarray_sum(input, subarray_length));
}

TEST(MaxSumOfSubarray, simple3)
{
    constexpr int subarray_length{1};
    std::vector<int> input{3};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, max_subarray_sum(input, subarray_length));
}


TEST(MaxSumOfSubarray, simple4)
{
    constexpr int subarray_length{2};
    std::vector<int> input{1,2,3,9,7,9,7,2,3,1};
    constexpr int expected_result{16};
    EXPECT_EQ(expected_result, max_subarray_sum(input, subarray_length));
}

TEST(MaxSumOfSubarray, simple5)
{
    constexpr int subarray_length{2};
    std::vector<int> input{1,2,3,9,9,9,9,2,3,1};
    constexpr int expected_result{12};
    EXPECT_EQ(expected_result, max_subarray_sum(input, subarray_length));
}

TEST(MaxSumOfSubarray, simple6)
{
    constexpr int subarray_length{3};
    std::vector<int> input{1,3,3,3,3,2,1,3,1,1,2};
    constexpr int expected_result{6};
    EXPECT_EQ(expected_result, max_subarray_sum(input, subarray_length));
}


TEST(MaxSumOfSubarray, complex1)
{
    constexpr int subarray_length{309};
    std::vector<int> input{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309};
    constexpr int expected_result{309*310/2};
    EXPECT_EQ(expected_result, max_subarray_sum(input, subarray_length));
}