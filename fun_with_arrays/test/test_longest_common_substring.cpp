//
// Created by andreas on 17.05.25.
//

#include "gtest/gtest.h"
#include "./../longest_common_substring.h"

TEST(LongestCommonSubstringTest, simple1) {
      std::string s1{"abcde"};
      std::string s2{"abfde"};
      constexpr int expected_result{2};
      EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, simple2) {
      std::string s1{"abcde"};
      std::string s2{""};
      constexpr int expected_result{0};
      EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}

TEST(LongestCommonSubstringTest, simple3) {
      std::string s1{"abcde"};
      std::string s2{"fbcde"};
      constexpr int expected_result{4};
      EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}


TEST(LongestCommonSubstringTest, simple4) {
      std::string s1{"123abcdezzklmn"};
      std::string s2{"456fbcdezzopq"};
      constexpr int expected_result{6};
      EXPECT_EQ(longest_common_substring(s1, s2), expected_result);
}
