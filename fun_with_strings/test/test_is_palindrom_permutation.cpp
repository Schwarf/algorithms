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
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

TEST(TestIsPalindromePermutationCaseInsensitive, simple1) {
    std::string s = "";
    EXPECT_TRUE(is_palindrome_permutation_ignore_case(s));
}

TEST(TestIsPalindromePermutationCaseInsensitive, simple2) {
    std::string s = "Tact Coa";
    EXPECT_TRUE(is_palindrome_permutation_ignore_case(s));
}

TEST(TestIsPalindromePermutationCaseInsensitive, simple3) {
    std::string s = "A man, a plan, a canal, Panama!";
    EXPECT_TRUE(is_palindrome_permutation_ignore_case(s));
}

TEST(TestIsPalindromePermutationCaseInsensitive, simple4) {
    std::string s = "Not a Palindrome";
    EXPECT_FALSE(is_palindrome_permutation_ignore_case(s));
}

TEST(TestIsPalindromePermutationCaseInsensitive, simple5) {
    std::string s = "Z";
    EXPECT_TRUE(is_palindrome_permutation_ignore_case(s));
}

TEST(TestIsPalindromePermutationCaseInsensitive, simple6) {
    std::string s = "AA1!!aa?";
    EXPECT_TRUE(is_palindrome_permutation_ignore_case(s));
}

TEST(TestIsPalindromePermutationCaseInsensitive, simple7) {
    std::string s = "AA1!!aa";
    EXPECT_TRUE(is_palindrome_permutation_ignore_case(s));
}
