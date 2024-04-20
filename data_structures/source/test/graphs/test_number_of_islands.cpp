//
// Created by andreas on 20.04.24.
//
#include "gtest/gtest.h"
#include "graphs/number_of_islands.h"

TEST(TestNumberOfIslands, simple1) {
    std::vector<std::vector<char>> input{{'1', '1', '1', '1', '0'},
                                         {'1', '1', '0', '1', '0'},
                                         {'1', '1', '0', '0', '0'},
                                         {'0', '0', '0', '0', '0'}};

    constexpr int expected_result{1};
    EXPECT_EQ(number_of_islands(input), expected_result);
}

TEST(TestNumberOfIslands, simple2) {
    std::vector<std::vector<char>> input{{'1', '0', '1', '1', '0'},
                                         {'1', '0', '0', '1', '0'},
                                         {'1', '1', '0', '0', '0'},
                                         {'0', '0', '0', '0', '0'}};

    constexpr int expected_result{2};
    EXPECT_EQ(number_of_islands(input), expected_result);
}

TEST(TestNumberOfIslands, simple3) {
    std::vector<std::vector<char>> input{{'1', '0', '1', '1', '0'},
                                         {'0', '0', '0', '1', '0'},
                                         {'1', '1', '0', '0', '0'},
                                         {'0', '0', '0', '1', '0'}};

    constexpr int expected_result{4};
    EXPECT_EQ(number_of_islands(input), expected_result);
}

TEST(TestNumberOfIslands, simple4) {
    std::vector<std::vector<char>> input{{'0'}};

    constexpr int expected_result{};
    EXPECT_EQ(number_of_islands(input), expected_result);
}

TEST(TestNumberOfIslands, simple5) {
    std::vector<std::vector<char>> input{{'1'}};
    constexpr int expected_result{1};
    EXPECT_EQ(number_of_islands(input), expected_result);
}
