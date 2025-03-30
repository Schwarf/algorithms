//
// Created by andreas on 30.08.23.
//

#include "gtest/gtest.h"
#include "graphs/max_rank_of_city_network.h"

TEST(MaxRankOfCityNetwork, simple1)
{
    const std::vector<std::vector<unsigned int>> roads{{0, 1}, {0, 3}, {1, 2}, {1, 3}};
    constexpr int number_of_cities{4};
    constexpr int expected_result{4};
    EXPECT_EQ(expected_result, compute_network_rank(number_of_cities, roads));
}

TEST(MaxRankOfCityNetwork, simple2)
{
    const std::vector<std::vector<unsigned int>> roads{{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
    constexpr int number_of_cities{5};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, compute_network_rank(number_of_cities, roads));
}

TEST(MaxRankOfCityNetwork, simple3)
{
    const std::vector<std::vector<unsigned int>> roads{{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}};
    constexpr int number_of_cities{8};
    constexpr int expected_result{5};
    EXPECT_EQ(expected_result, compute_network_rank(number_of_cities, roads));
}

TEST(MaxRankOfCityNetwork, simple4)
{
    const std::vector<std::vector<unsigned int>> roads{};
    constexpr int number_of_cities{100};
    constexpr int expected_result{0};
    EXPECT_EQ(expected_result, compute_network_rank(number_of_cities, roads));
}

TEST(MaxRankOfCityNetwork, complex)
{
    const std::vector<std::vector<unsigned int>> roads
    {
        {
            {14, 11}, {4, 17}, {15, 16}, {4, 20}, {20, 7}, {15, 2}, {8, 2}, {13, 19}, {13, 8}, {0, 13}, {10, 7},
            {3, 11},
            {3, 5}, {15, 3}, {13, 6}, {3, 8}, {10, 1}, {20, 19}, {15, 5}, {8, 4}, {19, 7}, {19, 15}, {1, 2}, {11, 0},
            {7, 12}, {8, 14}, {1, 0}, {15, 0}, {6, 2}, {13, 4}, {1, 4}, {8, 0}, {12, 6}, {11, 15}, {12, 8}, {8, 11},
            {7, 17}, {16, 4}, {11, 19}, {8, 20}, {10, 20}, {14, 16}, {16, 13}, {19, 10}, {12, 9}, {20, 14}, {16, 6},
            {18, 9}, {7, 9}, {9, 2}, {20, 11}, {3, 4}, {18, 12}, {1, 19}, {20, 9}, {0, 7}, {1, 5}, {13, 3}, {12, 4},
            {7, 16}, {16, 10}, {1, 17}, {17, 16}, {5, 20}, {4, 6}, {16, 1}, {2, 17}, {9, 17}, {10, 2}, {13, 18},
            {19, 8},
            {14, 12}, {9, 10}, {16, 0}, {14, 19}, {17, 11}, {4, 19}, {9, 3}, {11, 18}, {11, 2}, {6, 10}, {8, 10},
            {9, 16},
            {11, 7}, {5, 9}, {6, 5}, {5, 8}, {11, 12}, {14, 1}, {13, 17}, {11, 1}, {18, 16}, {17, 3}, {10, 17}, {6, 15},
            {4, 10}, {1, 18}, {13, 15}, {12, 0}, {5, 7}, {1, 20}, {11, 16}, {17, 20}, {9, 4}, {19, 2}, {5, 13}, {3, 6},
            {3, 0}, {4, 11}, {17, 0}, {6, 17}, {8, 7}, {15, 12}, {15, 10}, {8, 1}, {1, 3}, {2, 3}, {6, 18}, {16, 8},
            {1, 13}, {3, 19}, {14, 13}, {13, 12}, {9, 11}, {10, 0}, {10, 13}, {16, 12}, {18, 20}
        }
    };
    constexpr int number_of_cities{21};
    constexpr int expected_result{31};
    EXPECT_EQ(expected_result, compute_network_rank(number_of_cities, roads));
}
