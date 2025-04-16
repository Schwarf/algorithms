//
// Created by andreas on 16.04.25.
//
#include <fun_with_algos/minimum_swaps.h>

#include "stacks_and_queues/sum_of_subarray_ranges.h"
#include "gtest/gtest.h"

TEST(TestSumOfSubarrayRangesBruteForce, simple1)
{
    std::vector<int> input = {1, 2, 3};
    constexpr int expected_result{4};
    EXPECT_EQ(sum_of_subarray_ranges_brute_force(input), expected_result);
}

TEST(TestSumOfSubarrayRangesBruteForce, simple2)
{
    std::vector<int> input = {4, -2, -3, 4, 1};
    constexpr int expected_result{59};
    EXPECT_EQ(sum_of_subarray_ranges_brute_force(input), expected_result);
}

TEST(TestSumOfSubarrayRangesBruteForce, medium1)
{
    std::vector<int> input = {-561, 644, -637, 786, -32, 771, -22, 419, -837, 947, -359, -874, 489, 195};
    constexpr int expected_result{139349};
    EXPECT_EQ(sum_of_subarray_ranges_brute_force(input), expected_result);
}

TEST(TestSumOfSubarrayRangesBruteForce, complex1)
{
    std::vector<int> input = {
        -37988, -14446, -34454, -85916, 44628, -63469, 2405, 76071, 43291, 499, -43933, -10950, 22587, 45756, 36078,
        49794, 81866, -70327, 80649, 19025, 82130, -53646, 99394, 63520, 20667, 41291, 80388, -82451, -17666, 52744,
        -84498, 30104, 41847, 67932, -89959, -42134, -79079, 80796, -27089, 9691, -26248, -31934, -20681, 33506, 16422,
        -98706, -16321, 847, 55516, -85834, -3479, -58562, 77791, 62111, -15830, 33478, 79046, -47470, -54997, -56231,
        11301, 3998, 73631, 47168, 66983, 98655, -31405, -11411, 50967, -15908, 37346, 73429, -95644, 83331, 74868,
        -23201, 70451, 73304, 38820, -32124, 80413, -23607, 65237, 88536, 29905, -35443, -36683, 64419, -25056, 73050,
        17960, 16070, 54748, 76597, 74972, -73098, 74704, 55261, -38420, -42739, 15098, -8078, 82487, -34954, -38895,
        39994, 35077, -36851, 87932, 7216, -87758, -27817, 66742, 77803, -16270, 41596, -14558, 28610, 4151, -2590,
        -73414, 56156, 93465, 31128, -19581, -44840, -87553, -79674, -2016, 3190, 62008
    };
    constexpr int expected_result{1537100894};
    EXPECT_EQ(sum_of_subarray_ranges_brute_force(input), expected_result);
}
