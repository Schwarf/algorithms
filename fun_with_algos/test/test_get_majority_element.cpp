//
// Created by andreas on 26.03.23.
//
#include "gtest/gtest.h"
#include "get_majority_element.h"

TEST(TestGetMajorityElement, majority_element_hashmap1) {
    std::vector<std::string> input{"c", "a", "ab", "c", "c", "d", "ahsak", "c", "l", "j", "c", "c", "c"};
    std::string expected_result{"c"};
    auto result = get_majority_element_hashmap(input);
    EXPECT_EQ(result, expected_result);
}

TEST(TestGetMajorityElement, majority_element_boyer_moore1) {
    std::vector<std::string> input{"c", "a", "ab", "c", "c", "d", "ahsak", "c", "l", "j", "c", "c", "c"};
    std::string expected_result{"c"};
    std::string initial_candidate;
    auto result = get_majority_element_boyer_moore(input, initial_candidate);
    EXPECT_EQ(result, expected_result);
}


TEST(TestGetMajorityElement, majority_element_hashmap2) {
    std::vector<short> input{1, 2, 3, 4, 5, 6, 2, 2, 2, 2, 2, 1, 18, 2, 2};
    short expected_result{2};
    auto result = get_majority_element_hashmap(input);
    EXPECT_EQ(result, expected_result);
}

TEST(TestGetMajorityElement, majority_element_boyer_moore2) {
    std::vector<short> input{1, 2, 3, 4, 5, 6, 2, 2, 2, 2, 2, 1, 18, 2, 2};
    short expected_result{2};
    short initial_candidate{};
    auto result = get_majority_element_boyer_moore(input, initial_candidate);
    EXPECT_EQ(result, expected_result);
}

TEST(TestGetMajorityElement, majority_element_bitmanipulation1) {
    std::vector<short> input{1, 2, 3, 4, 5, 6, 2, 2, 2, 2, 2, 1, 18, 2, 2};
    short expected_result{2};
    auto result = get_majority_element_bit_manipulation(input);
    EXPECT_EQ(result, expected_result);
}
