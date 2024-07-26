//
// Created by andreas on 26.07.24.
//

#ifndef DATA_STRUCTURES_TEST_CITY_WITH_SMALLEST_NUMBER_OF_NEIGHBORS_IN_DISTANCE_H
#define DATA_STRUCTURES_TEST_CITY_WITH_SMALLEST_NUMBER_OF_NEIGHBORS_IN_DISTANCE_H

#include "graphs/city_with_smallest_number_of_neighbors_in_distance.h"
#include "gtest/gtest.h"

TEST(FindCityWithSmallestNumberOfNeigborsInDistanceTest, simple1) {
    constexpr int n{4};
    std::vector<std::vector<int>> input_edges{{0, 1, 3},
                                              {1, 2, 1},
                                              {1, 3, 4},
                                              {2, 3, 1}};
    constexpr int max_allowed_distance{4};
    constexpr int expected_result{3};
    EXPECT_EQ(city_with_smallest_number_of_neighbors_dijkstra(n, input_edges, max_allowed_distance), expected_result);
}

#endif //DATA_STRUCTURES_TEST_CITY_WITH_SMALLEST_NUMBER_OF_NEIGHBORS_IN_DISTANCE_H
