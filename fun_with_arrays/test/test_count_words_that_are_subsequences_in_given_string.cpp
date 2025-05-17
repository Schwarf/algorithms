//
// Created by andreas on 17.05.25.
//

#include "./../count_words_that_are_subsequences_in_given_string.h"
#include "gtest/gtest.h"

TEST(TestCountWordsThatAreSubsequencesInGivenString, simple1)
{
    std::vector<std::string> words = {"a", "bb", "acd", "ace"};
    std::string s{"abcde"};
    constexpr int expected_result{3};
    EXPECT_EQ(count_words_that_are_subsequences_in_given_string(s, words), expected_result);
}

TEST(TestCountWordsThatAreSubsequencesInGivenString, simple2)
{
    std::vector<std::string> words = {"a", "ab", "abc", "abcd"};
    std::string s{"abcde"};
    constexpr int expected_result{4};
    EXPECT_EQ(count_words_that_are_subsequences_in_given_string(s, words), expected_result);
}

TEST(CountSubsequencesTest, simple3) {
    // Note subsequences count too
    std::vector<std::string> words = {"ace", "aec", "bd", "ad", "aeb"};
    std::string s{"abcde"};
    constexpr int expected_result{3};
    EXPECT_EQ(count_words_that_are_subsequences_in_given_string(s, words), expected_result);
}

TEST(CountSubsequencesTest, simple4) {
    // Note subsequences count too
    std::vector<std::string> words = {"", "", "a"};
    std::string s{"a"};
    constexpr int expected_result{3};
    EXPECT_EQ(count_words_that_are_subsequences_in_given_string(s, words), expected_result);
}

TEST(CountSubsequencesTest, simple5) {
    // Note subsequences count too
    std::vector<std::string> words = {"a", "bc", "edf"};
    std::string s{"xyz"};
    constexpr int expected_result{0};
    EXPECT_EQ(count_words_that_are_subsequences_in_given_string(s, words), expected_result);
}
