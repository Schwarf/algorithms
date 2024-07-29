//
// Created by andreas on 29.07.24.
//

#include "../count_number_of_valid_triples.h"
#include "gtest/gtest.h"

TEST(CountNumberOfValidTriplesBruteForce, simple1) {
    std::vector<int> input{2, 5, 3, 4, 1};
    constexpr int expected_result{3};
    EXPECT_EQ(expected_result, valid_triple(input));
}

TEST(CountNumberOfValidTriplesBruteForce, simple2) {
    std::vector<int> input{2, 1, 3};
    constexpr int expected_result{};
    EXPECT_EQ(expected_result, valid_triple(input));
}

TEST(CountNumberOfValidTriplesBruteForce, simple3) {
    std::vector<int> input{1, 2, 3, 4};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, valid_triple(input));
}

TEST(CountNumberOfValidTriplesBruteForce, medium1) {
    std::vector<int> input{89, 61, 13, 36, 37, 39, 97, 76, 84, 18, 12, 24, 71, 33, 44, 85, 70, 82, 15, 74, 35, 66, 59,
                           8, 3, 96, 30, 16, 41, 7, 10, 68, 92, 83, 95, 77, 9, 14, 81, 88, 38};
    constexpr int expected_result{3514};
    EXPECT_EQ(expected_result, valid_triple(input));
}

TEST(CountNumberOfValidTriplesBruteForce, medium2) {
    std::vector<int> input{192, 271, 138, 126, 211, 201, 284, 295, 82, 75, 299, 155, 170, 300, 107, 96, 280, 115, 225,
                           67, 112, 188, 171, 275, 33, 278, 260, 210, 253, 109, 26, 285, 162, 48, 173, 220, 281, 41,
                           150, 163, 68, 147, 30, 268, 50, 16, 168, 86, 256, 177, 198, 129, 35, 139, 207};
    constexpr int expected_result{8291};
    EXPECT_EQ(expected_result, valid_triple(input));
}


TEST(CountNumberOfValidTriplesBruteForce, complex1) {
    std::vector<int> input{240, 17, 912, 1274, 2049, 1102, 990, 1883, 536, 274, 2822, 1063, 2763, 1420, 1008, 306, 1167,
                           417, 2259, 1898, 1799, 1919, 643, 507, 2841, 1380, 122, 2037, 1379, 2300, 2842, 597, 1681,
                           1572, 37, 546, 1918, 1871, 1016, 2097, 2086, 1275, 1733, 412, 434, 292, 358, 2512, 474, 896,
                           1803, 543, 2013, 2264, 2596, 2394, 678, 1027, 542, 182, 1117, 1315, 765, 2191, 1185, 2047,
                           884, 985, 2477, 2706, 2155, 905, 2526, 2892, 1473, 1649, 722, 841, 2392, 2245, 101, 52, 1826,
                           2312, 1176, 1682, 500, 1015, 824, 1652, 1707, 1371, 1716, 1204, 1903, 1401, 930, 1368, 1902,
                           1212, 2095, 2743, 891, 661, 2729, 1507, 1847, 1268, 532, 506, 501, 2756, 2075, 1005, 1280,
                           2004, 2617, 1026, 2127, 920, 1995, 2064, 278, 483, 1283, 1370, 2079, 1677, 544, 724, 2637,
                           1891, 1152, 73, 68, 911, 992, 1630, 2130, 1475, 2453, 2429, 1479, 1861, 1079, 2280, 263,
                           2590, 372, 1211, 2328, 254, 1765, 2627, 367, 1541, 329, 1197, 825, 1256, 22, 782, 1933, 792,
                           491, 1613, 405, 2832, 1141, 269, 2271, 1780, 940, 756, 647, 419, 2682, 589, 1581, 2891, 1174,
                           2957, 2750, 565, 2950, 2716, 1402, 277, 1075, 872, 2740, 193, 1458, 1459, 636, 1937, 2639,
                           1436, 909, 197, 2261, 238, 611, 1669, 1725, 1448, 2746, 482, 2154, 1732, 2255, 1590, 1292,
                           800, 1703, 2033, 1591, 1855, 2249, 1217, 1046, 1650, 1997, 493, 1489, 2108, 610, 2110, 209,
                           2864, 1635, 1583, 2397, 653, 1290, 778, 440, 860, 476, 815};
    constexpr int expected_result{759166};
    EXPECT_EQ(expected_result, valid_triple(input));
}


