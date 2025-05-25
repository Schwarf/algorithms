//
// Created by andreas on 25.05.25.
//
#include "./../longest_palindrome_from_two_letter_words.h"
#include "gtest/gtest.h"

TEST(TestLongestPalindromicString, simple1)
{
    std::vector<std::string> words{"lc", "cl", "gg"};
    constexpr int expected_result{6};
    EXPECT_EQ(longest_palindromic_string(words), expected_result);
}

TEST(TestLongestPalindromicString, simple2)
{
    std::vector<std::string> words{"ab", "ty", "yt", "lc", "cl", "ab"};
    constexpr int expected_result{8};
    EXPECT_EQ(longest_palindromic_string(words), expected_result);
}

TEST(TestLongestPalindromicString, simple3)
{
    std::vector<std::string> words{"cc", "ll", "xx"};
    constexpr int expected_result{2};
    EXPECT_EQ(longest_palindromic_string(words), expected_result);
}

TEST(TestLongestPalindromicString, complex1)
{
    std::vector<std::string> words{
        "oo", "vv", "uu", "gg", "pp", "ff", "ss", "yy", "vv", "cc", "rr", "ig", "jj", "uu", "ig", "gb", "zz", "xx",
        "ff", "bb", "ii", "dd", "ii", "ee", "mm", "qq", "ig", "ww", "ss", "tt", "vv", "oo", "ww", "ss", "bi", "ff",
        "gg", "bi", "jj", "ee", "gb", "qq", "bg", "nn", "vv", "oo", "bb", "pp", "ww", "qq", "mm", "ee", "tt", "hh",
        "ss", "tt", "ee", "gi", "ig", "uu", "ff", "zz", "ii", "ff", "ss", "gi", "yy", "gb", "mm", "pp", "uu", "kk",
        "jj", "ee"
    };
    constexpr int expected_result{102};
    EXPECT_EQ(longest_palindromic_string(words), expected_result);
}
