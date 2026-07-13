//
// Created by andreas on 17.05.25.
//

#include "../../align_subsequences/longest_common_substring.h"
#include "gtest/gtest.h"

TEST(LongestCommonSubstringTest, simple1)
{
    std::string s1{"abcde"};
    std::string s2{"abfde"};
    constexpr int expected_result{2};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, simple2)
{
    std::string s1{"abcde"};
    std::string s2{""};
    constexpr int expected_result{0};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, simple3)
{
    std::string s1{"abcde"};
    std::string s2{"fbcde"};
    constexpr int expected_result{4};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}


TEST(LongestCommonSubstringTest, simple4)
{
    std::string s1{"123abcdezzklmn"};
    std::string s2{"456fbcdezzopq"};
    constexpr int expected_result{6};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, both_empty)
{
    std::string s1{""};
    std::string s2{""};
    constexpr int expected_result{0};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, first_empty)
{
    std::string s1{""};
    std::string s2{"abcde"};
    constexpr int expected_result{0};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, no_common_characters)
{
    std::string s1{"abc"};
    std::string s2{"DEF"};
    constexpr int expected_result{0};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, identical_strings)
{
    std::string s1{"dynamic"};
    std::string s2{"dynamic"};
    constexpr int expected_result{7};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, common_subsequence_is_not_enough)
{
    std::string s1{"abcde"};
    std::string s2{"ace"};
    constexpr int expected_result{1};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, repeated_characters)
{
    std::string s1{"aaaaab"};
    std::string s2{"baaaaac"};
    constexpr int expected_result{5};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, case_sensitive)
{
    std::string s1{"ABCdef"};
    std::string s2{"abcDEF"};
    constexpr int expected_result{0};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, longest_match_in_middle)
{
    std::string s1{"xxalgorithmzz"};
    std::string s2{"yyalgorithmqq"};
    constexpr int expected_result{9};
    EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}
