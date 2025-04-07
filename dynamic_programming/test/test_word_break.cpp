//
// Created by andreas on 07.04.25.
//
#include "./../word_break.h"
#include "gtest/gtest.h"

TEST(TestWordBreak, simple1)
{
      std::string input {"badcode"};
      std::vector<std::string> words{"code", "bad"};
      EXPECT_TRUE(word_break(input, words));
}

TEST(TestWordBreak, simple2)
{
      std::string input {"baddcode"};
      std::vector<std::string> words{"code", "bad"};
      EXPECT_FALSE(word_break(input, words));
}

TEST(TestWordBreak, simple3)
{
      std::string input {"bacode"};
      std::vector<std::string> words{"code", "bad"};
      EXPECT_FALSE(word_break(input, words));
}

TEST(TestWordBreak, simple4)
{
      std::string input {"badcodeisbad"};
      std::vector<std::string> words{"code", "bad", "isbad"};
      EXPECT_TRUE(word_break(input, words));
}
