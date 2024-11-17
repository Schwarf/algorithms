//
// Created by andreas on 17.11.24.
//
#include "gtest/gtest.h"
#include "shortest_subarray_with_sum.h"

TEST(TestSmallestSubarrayWithSum, simple1)
{
    std::vector<int> input{2, 3, 1, 2, 4, 3};
    constexpr int target_sum{7};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum(input, target_sum));
}

TEST(TestSmallestSubarrayWithSum, simple2)
{
    std::vector<int> input{1, 4, 4};
    constexpr int target_sum{4};
    constexpr int expected_result{1};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum(input, target_sum));
}

TEST(TestSmallestSubarrayWithSum, simple3)
{
    std::vector<int> input{1, 4, 4};
    constexpr int target_sum{5};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum(input, target_sum));
}

TEST(TestSmallestSubarrayWithSum, simple4)
{
    std::vector<int> input{1, 4, 4};
    constexpr int target_sum{9};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum(input, target_sum));
}

TEST(TestSmallestSubarrayWithSum, simple5)
{
    std::vector<int> input{1, 4, 4};
    constexpr int target_sum{10};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum(input, target_sum));
}


TEST(TestSmallestSubarrayWithSum, medium1)
{
    std::vector<int> input{12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
    constexpr int target_sum{213};
    constexpr int expected_result{8};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum(input, target_sum));
}


TEST(TestSmallestSubarrayWithSum, complex1)
{
    std::vector<int> input{
        5334, 6299, 4199, 9663, 8945, 3566, 9509, 3124, 6026, 6250, 7475, 5420, 9201, 9501, 38, 5897, 4411, 6638, 9845,
        161, 9563, 8854, 3731, 5564, 5331, 4294, 3275, 1972, 1521, 2377, 3701, 6462, 6778, 187, 9778, 758, 550, 7510,
        6225, 8691, 3666, 4622, 9722, 8011, 7247, 575, 5431, 4777, 4032, 8682, 5888, 8047, 3562, 9462, 6501, 7855, 505,
        4675, 6973, 493, 1374, 3227, 1244, 7364, 2298, 3244, 8627, 5102, 6375, 8653, 1820, 3857, 7195, 7830, 4461, 7821,
        5037, 2918, 4279, 2791, 1500, 9858, 6915, 5156, 970, 1471, 5296, 1688, 578, 7266, 4182, 1430, 4985, 5730, 7941,
        3880, 607, 8776, 1348, 2974, 1094, 6733, 5177, 4975, 5421, 8190, 8255, 9112, 8651, 2797, 335, 8677, 3754, 893,
        1818, 8479, 5875, 1695, 8295, 7993, 7037, 8546, 7906, 4102, 7279, 1407, 2462, 4425, 2148, 2925, 3903, 5447,
        5893, 3534, 3663, 8307, 8679, 8474, 1202, 3474, 2961, 1149, 7451, 4279, 7875, 5692, 6186, 8109, 7763, 7798,
        2250, 2969, 7974, 9781, 7741, 4914, 5446, 1861, 8914, 2544, 5683, 8952, 6745, 4870, 1848, 7887, 6448, 7873, 128,
        3281, 794, 1965, 7036, 8094, 1211, 9450, 6981, 4244, 2418, 8610, 8681, 2402, 2904, 7712, 3252, 5029, 3004, 5526,
        6965, 8866, 2764, 600, 631, 9075, 2631, 3411, 2737, 2328, 652, 494, 6556, 9391, 4517, 8934, 8892, 4561, 9331,
        1386, 4636, 9627, 5435, 9272, 110, 413, 9706, 5470, 5008, 1706, 7045, 9648, 7505, 6968, 7509, 3120, 7869, 6776,
        6434, 7994, 5441, 288, 492, 1617, 3274, 7019, 5575, 6664, 6056, 7069, 1996, 9581, 3103, 9266, 2554, 7471, 4251,
        4320, 4749, 649, 2617, 3018, 4332, 415, 2243, 1924, 69, 5902, 3602, 2925, 6542, 345, 4657, 9034, 8977, 6799,
        8397, 1187, 3678, 4921, 6518, 851, 6941, 6920, 259, 4503, 2637, 7438, 3893, 5042, 8552, 6661, 5043, 9555, 9095,
        4123, 142, 1446, 8047, 6234, 1199, 8848, 5656, 1910, 3430, 2843, 8043, 9156, 7838, 2332, 9634, 2410, 2958, 3431,
        4270, 1420, 4227, 7712, 6648, 1607, 1575, 3741, 1493, 7770, 3018, 5398, 6215, 8601, 6244, 7551, 2587, 2254,
        3607, 1147, 5184, 9173, 8680, 8610, 1597, 1763, 7914, 3441, 7006, 1318, 7044, 7267, 8206, 9684, 4814, 9748,
        4497, 2239
    };
    constexpr int target_sum{697439};
    constexpr int expected_result{132};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum(input, target_sum));
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(TestSmallestSubarrayWithSumAndNegativeInputs, simple1)
{
    std::vector<int> input{2, -3, 1, 2, 4, -1};
    constexpr int target_sum{7};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum_with_negatives(input, target_sum));
}

TEST(TestSmallestSubarrayWithSumAndNegativeInputs, simple2)
{
    std::vector<int> input{6, -3, -1, 5, -4, 4, -1};;
    constexpr int target_sum{7};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum_with_negatives(input, target_sum));
}

TEST(TestSmallestSubarrayWithSumAndNegativeInputs, simple3)
{
    std::vector<int> input{2, -1, 2};
    constexpr int target_sum{3};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum_with_negatives(input, target_sum));
}

TEST(TestSmallestSubarrayWithSumAndNegativeInputs, simple4)
{
    std::vector<int> input{-34, 37, 51, 3, -12, -50, 51, 100, -47, 99, 34, 14, -13, 89, 31, -14, -44, 23, -38, 6};
    constexpr int target_sum{151};
    constexpr int expected_result{2};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum_with_negatives(input, target_sum));
}

TEST(TestSmallestSubarrayWithSumAndNegativeInputs, simple5)
{
    std::vector<int> input{
        86396, 74204, 24861, 72405, 30809, 40710, 47892, -48882, -9084, 59464, 29389, 1510, 16521, 38996, 98830, 15183,
        38241, 90465, -10717, 81061, -40387, -23424, 74146, -24051, 56847, 44278, 41403, -763, 50836, 6482, 44225,
        16178, -48529, -36193, 28857, -16654, 48188, 54971, -29822, 25959, 90144, -23182, -9464, 65609, 99248, -26248,
        47993, -20085, 75072, 70400
    };
    constexpr int target_sum{209110};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum_with_negatives(input, target_sum));
}


TEST(TestSmallestSubarrayWithSumAndNegativeInputs, medium1)
{
    std::vector<int> input{
        -42201, 71157, 26557, -24408, 26307, -26661, 58647, 67669, 40541, -39836, -2520, -17366, -27651, 95839, -47100,
        48805, -49114, 64401, 42793, 61633, 30144, 93404, 55467, 15112, -4614, 31258, 99687, -17890, 14363, 94268,
        47280, 66124, -13359, 52612, -17260, -42528, 59410, 98561, 28176, 92321, -2331, 77145, -38483, 34936, 12304,
        81106, 9850, 41959, 72544, 41951, 20162, -21336, 92774, 76921, -46603, 34074, 54808, -28939, 12033, -22235,
        -27160, -42446, -14538, 5204, 32755, -12786, 98529, -28035, 41108, 80164, -44518, 77585, 82680, 13616, 45536,
        41451, 47294, -6968, 35688, 97067, 15130, -47423, 72539, 15659, 84288, 79572, 74526, -41671, -45226, -47688,
        10161, 9690, 69743, -4965, 94123, 11632, 41395, 7072, 44623, 91117
    };
    constexpr int target_sum{801950};
    constexpr int expected_result{19};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum_with_negatives(input, target_sum));
}

TEST(TestSmallestSubarrayWithSumAndNegativeInputs, complex1)
{
    std::vector<int> input{
        -18338, 17739, 47813, 21671, 64681, 64338, -23111, 52701, -15097, 58845, 59358, -13891, 72750, -13744, 35568,
        68604, 51169, -28812, 82372, -30137, 55467, -25625, 86090, 33986, 25491, -34182, 9113, 77840, -7721, -32486,
        70725, 34721, 75193, -30997, -6987, -30920, -25434, 56105, 28119, -178, 25360, -23780, 15172, 17731, -33131,
        59852, 67088, 52703, 4528, -7393, -11530, -34648, 6520, 79814, 75184, -473, 39467, 26174, 57264, -1589, 57875,
        -6757, 53162, 81992, 62533, -20482, 54284, -19740, 29394, 53699, -47515, -6250, 2887, -48041, 2355, 27264,
        28998, 84166, 10841, 9307, -26574, 22893, -21639, 57031, -30105, 79335, -9655, -649, 92631, -779, 44806, 45121,
        51123, 13538, 65974, 67179, -48269, -30777, -48867, 83453, 31487, 69443, -21595, 88664, 70036, 52595, 43335,
        53460, 74407, 99442, -41322, -34520, 58447, -5051, 84619, 85286, -17594, 14020, 94160, 79126, -15774, -5592,
        -30251, 99291, 12619, 36844, -5162, -48827, -13489, 89443, 36359, -33618, 62951, 90645, -12137, 95477, 25217,
        36685, -44650, 19092, -47364, 65675, 97346, 56877, 59766, 34438, 70404, 40497, 29105, 4601, -38595, 52485,
        -15048, 53766, 39102, 47988, 58585, 16059, 57556, 87449, 41895, 48027, -43658, 45409, 11053, -13231, -11630,
        64017, 66850, 58489, -6487, 60887, 12909, 17966, 16309, 86741, -5054, -12464, 85014, 94307, -38541, -28960,
        24516, -8774, 26894, -42780, 98043, 85029, 9886, 82623, 96917, 83098, 63165, -44440, -49657, 30718, 24433,
        -8887, 61936, 33892
    };
    constexpr int target_sum{1596374};
    constexpr int expected_result{46};
    EXPECT_EQ(expected_result, shortest_subarray_with_sum_with_negatives(input, target_sum));
}
