//
// Created by andreas on 02.06.23.
//
#include "gtest/gtest.h"
#include "graphs/maximum_marked_circles.h"

TEST(maximum_marked_circles, simple1_bfs) {
    std::vector<std::vector<int>> input{{2, 1, 3},
                                        {6, 1, 4}};
    int expected_result{2};
    auto result = maximum_marked_circles<int, true>(input);
    EXPECT_EQ(expected_result, result);
}

TEST(maximum_marked_circles, simple1_dfs) {
    std::vector<std::vector<int>> input{{2, 1, 3},
                                        {6, 1, 4}};
    int expected_result{2};
    auto result = maximum_marked_circles<int, false>(input);
    EXPECT_EQ(expected_result, result);
}


TEST(maximum_marked_circles, simple2_bfs) {
    std::vector<std::vector<int>> input{{1, 2, 3},
                                        {2, 3, 1},
                                        {3, 4, 2},
                                        {4, 5, 3},
                                        {5, 6, 4}};
    int expected_result{5};
    auto result = maximum_marked_circles<int, true>(input);
    EXPECT_EQ(expected_result, result);
}

TEST(maximum_marked_circles, simple2_dfs) {
    std::vector<std::vector<int>> input{{1, 2, 3},
                                        {2, 3, 1},
                                        {3, 4, 2},
                                        {4, 5, 3},
                                        {5, 6, 4}};
    int expected_result{5};
    auto result = maximum_marked_circles<int, false>(input);
    EXPECT_EQ(expected_result, result);
}


TEST(maximum_marked_circles, medium_bfs) {
    std::vector<std::vector<int>> input
            {{1721, 8266, 6320},
             {6368, 2445, 2028},
             {589,  7017, 6917},
             {9674, 9538, 6721},
             {4645, 2421, 8860},
             {9381, 1252, 807},
             {1414, 8224, 6718},
             {6500, 1216, 9081},
             {4691, 7541, 4112},
             {3595, 2277, 3577},
             {9028, 7476, 3671},
             {2789, 6916, 554},
             {3435, 2225, 9486},
             {2651, 1495, 5253},
             {7209, 4628, 5618}};
    int expected_result{15};
    auto result = maximum_marked_circles<int, true>(input);
    EXPECT_EQ(expected_result, result);
}

TEST(maximum_marked_circles, medium_dfs) {
    std::vector<std::vector<int>> input
            {{1721, 8266, 6320},
             {6368, 2445, 2028},
             {589,  7017, 6917},
             {9674, 9538, 6721},
             {4645, 2421, 8860},
             {9381, 1252, 807},
             {1414, 8224, 6718},
             {6500, 1216, 9081},
             {4691, 7541, 4112},
             {3595, 2277, 3577},
             {9028, 7476, 3671},
             {2789, 6916, 554},
             {3435, 2225, 9486},
             {2651, 1495, 5253},
             {7209, 4628, 5618}};
    int expected_result{15};
    auto result = maximum_marked_circles<int, false>(input);
    EXPECT_EQ(expected_result, result);
}