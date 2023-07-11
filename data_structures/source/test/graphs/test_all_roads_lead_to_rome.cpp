//
// Created by andreas on 27.03.23.
//
#include "gtest/gtest.h"
#include "graphs/all_roads_lead_to_rome.h"

TEST(AllRoadsLeadToRome, simple1) {
    const std::vector<std::vector<unsigned int>> input{{0, 1},
                                                       {1, 3},
                                                       {2, 3},
                                                       {4, 0},
                                                       {4, 5}};
    constexpr int expected_result{3};
    constexpr unsigned int number_of_cities{6};
    const auto result = all_roads_lead_to_rome<unsigned int, true>(number_of_cities, input);
    EXPECT_EQ(result, expected_result);
}


TEST(AllRoadsLeadToRome, simple2) {
    const std::vector<std::vector<unsigned int>> input{{1, 0},
                                                       {1, 2},
                                                       {3, 2},
                                                       {3, 4}};
    constexpr int expected_result{2};
    constexpr unsigned int number_of_cities{5};
    const auto result = all_roads_lead_to_rome<unsigned int, true>(number_of_cities, input);
    EXPECT_EQ(result, expected_result);
}


TEST(AllRoadsLeadToRome, simple_zero) {
    const std::vector<std::vector<unsigned int>> input{{1, 0},
                                                       {2, 0}};
    constexpr int expected_result{0};
    constexpr unsigned int number_of_cities{3};
    const auto result = all_roads_lead_to_rome<unsigned int, true>(number_of_cities, input);
    EXPECT_EQ(result, expected_result);
}


TEST(AllRoadsLeadToRome, simple_bfs1) {
    const std::vector<std::vector<unsigned int>> input{{0, 1},
                                                       {1, 3},
                                                       {2, 3},
                                                       {4, 0},
                                                       {4, 5}};
    constexpr int expected_result{3};
    constexpr unsigned int number_of_cities{6};
    const auto result = all_roads_lead_to_rome<unsigned int, false>(number_of_cities, input);
    EXPECT_EQ(result, expected_result);
}


TEST(AllRoadsLeadToRome, simple_bfs2) {
    const std::vector<std::vector<unsigned int>> input{{1, 0},
                                                       {1, 2},
                                                       {3, 2},
                                                       {3, 4}};
    constexpr int expected_result{2};
    constexpr unsigned int number_of_cities{5};
    const auto result = all_roads_lead_to_rome<unsigned int, false>(number_of_cities, input);
    EXPECT_EQ(result, expected_result);
}


TEST(AllRoadsLeadToRome, simple_bfs_zero) {
    const std::vector<std::vector<unsigned int>> input{{1, 0},
                                                       {2, 0}};
    constexpr int expected_result{0};
    constexpr unsigned int number_of_cities{3};
    const auto result = all_roads_lead_to_rome<unsigned int, false>(number_of_cities, input);
    EXPECT_EQ(result, expected_result);
}
