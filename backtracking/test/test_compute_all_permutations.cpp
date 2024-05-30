//
// Created by andreas on 02.08.23.
//

#include "gtest/gtest.h"
#include "compute_all_permutations.h"

TEST(ComputeAllPermutations, simple1) {
    const std::vector<int> input{1, 2, 3};
    const std::vector<std::vector<int>>
            expected_result{{1, 2, 3},
                            {1, 3, 2},
                            {2, 1, 3},
                            {2, 3, 1},
                            {3, 1, 2},
                            {3, 2, 1}};
    EXPECT_EQ(expected_result, compute_all_permutations(input));
}


TEST(ComputeAllPermutations, simple2) {
    const std::vector<char> input{0, 1};
    const std::vector<std::vector<char>>
            expected_result{{0, 1},
                            {1, 0}};
    EXPECT_EQ(expected_result, compute_all_permutations(input));
}

TEST(ComputeAllPermutations, simple3) {
    const std::vector<std::string> input{"s"};
    const std::vector<std::vector<std::string>>
            expected_result{{"s"}};
    EXPECT_EQ(expected_result, compute_all_permutations(input));
}


TEST(ComputeAllPermutations, medium1) {
    const std::vector<int> input{5, 4, 6, 2};
    const std::vector<std::vector<int>>
            expected_result{{5, 4, 6, 2},
                            {5, 4, 2, 6},
                            {5, 6, 4, 2},
                            {5, 6, 2, 4},
                            {5, 2, 4, 6},
                            {5, 2, 6, 4},
                            {4, 5, 6, 2},
                            {4, 5, 2, 6},
                            {4, 6, 5, 2},
                            {4, 6, 2, 5},
                            {4, 2, 5, 6},
                            {4, 2, 6, 5},
                            {6, 5, 4, 2},
                            {6, 5, 2, 4},
                            {6, 4, 5, 2},
                            {6, 4, 2, 5},
                            {6, 2, 5, 4},
                            {6, 2, 4, 5},
                            {2, 5, 4, 6},
                            {2, 5, 6, 4},
                            {2, 4, 5, 6},
                            {2, 4, 6, 5},
                            {2, 6, 5, 4},
                            {2, 6, 4, 5}};
    EXPECT_EQ(expected_result, compute_all_permutations(input));
}
