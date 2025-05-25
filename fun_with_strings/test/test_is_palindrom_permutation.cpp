//
// Created by andreas on 25.05.25.
//
#include "gtest/gtest.h"
#include "./../is_palindrom_permutation.h"


TEST(TestIsPalindromePermutationCaseSensitive, simple1) {
    std::string s = "";
    EXPECT_TRUE(is_palindrome_permutation_case_sensitive(s));
}

TEST(TestIsPalindromePermutationCaseSensitive, simple2) {
    std::string s = "x";
    EXPECT_TRUE(is_palindrome_permutation_case_sensitive(s));
}

TEST(TestIsPalindromePermutationCaseSensitive, simple3) {
    std::string s = "aab";
    EXPECT_TRUE(is_palindrome_permutation_case_sensitive(s));
}

TEST(TestIsPalindromePermutationCaseSensitive, simple4) {
    std::string s = "abc";
    EXPECT_FALSE(is_palindrome_permutation_case_sensitive(s));
}

TEST(TestIsPalindromePermutationCaseSensitive, simple5) {
    std::string s = "Aa";
    EXPECT_FALSE(is_palindrome_permutation_case_sensitive(s));
}

TEST(TestIsPalindromePermutationCaseSensitive, simple6) {
    std::string s = "AA1!!aa?";
    EXPECT_FALSE(is_palindrome_permutation_case_sensitive(s));
}

TEST(TestIsPalindromePermutationCaseSensitive, simple7) {
    std::string s = "AA1!!aa";
    EXPECT_TRUE(is_palindrome_permutation_case_sensitive(s));
}
