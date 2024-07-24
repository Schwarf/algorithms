//
// Created by andreas on 25.03.24.
//

#include "gtest/gtest.h"
#include "./../find_all_duplicates_in_array.h"

TEST(TestFindAllDuplicatesInArray, simple1) {
    std::vector<int> input{4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> expected_output{2, 3};
    EXPECT_EQ(expected_output, find_all_duplicates_in_array(input));
}

TEST(TestFindAllDuplicatesInArray, simple2) {
    std::vector<int> input{1, 1, 2};
    std::vector<int> expected_output{1};
    EXPECT_EQ(expected_output, find_all_duplicates_in_array(input));
}

TEST(TestFindAllDuplicatesInArray, simple3) {
    std::vector<int> input{1, 2};
    std::vector<int> expected_output{};
    EXPECT_EQ(expected_output, find_all_duplicates_in_array(input));
}

TEST(TestFindAllDuplicatesInArray, simple4) {
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6};
    std::vector<int> expected_output{8, 7, 6};
    EXPECT_EQ(expected_output, find_all_duplicates_in_array(input));
}
