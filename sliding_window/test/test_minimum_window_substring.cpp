//
// Created by andreas on 22.06.25.
//
#include "./../minimum_window_substring.h"
#include "gtest/gtest.h"

TEST(TestMinimumWindowSubstring, simple1)
{
  std::string s{"ADOBECODEBANC"};
  std::string t{"ABC"};
  const std::string expected_result{"BANC"};
  EXPECT_EQ(minimum_window_substring(s, t), expected_result);
}

TEST(TestMinimumWindowSubstring, simple2)
{
  std::string s{"a"};
  std::string t{"a"};
  const std::string expected_result{"a"};
  EXPECT_EQ(minimum_window_substring(s, t), expected_result);
}

TEST(TestMinimumWindowSubstring, simple3)
{
  std::string s{"bb"};
  std::string t{"a"};
  const std::string expected_result;
  EXPECT_EQ(minimum_window_substring(s, t), expected_result);
}
