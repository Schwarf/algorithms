//
// Created by andreas on 06.10.24.
//
#include "gtest/gtest.h"
#include "./../sentence_similarity.h"

TEST(TestSentenceSimilarity, simple1)
{
    std::string sentence1 {"My name is Schwarf"};
    std::string sentence2 {"My name"};
    EXPECT_TRUE(are_sentences_similar(sentence1, sentence2));
}

TEST(TestSentenceSimilarity, simple2)
{
    std::string sentence1 {"My name is Schwarf"};
    std::string sentence2 {"My name is Gander"};
    EXPECT_FALSE(are_sentences_similar(sentence1, sentence2));
}

TEST(TestSentenceSimilarity, simple3)
{
    std::string sentence1 {"My name is Schwarf"};
    std::string sentence2 {"name is"};
    EXPECT_FALSE(are_sentences_similar(sentence1, sentence2));
}

TEST(TestSentenceSimilarity, simple4)
{
    std::string sentence1 {"My name is Schwarf Toll"};
    std::string sentence2 {"My Toll"};
    EXPECT_TRUE(are_sentences_similar(sentence1, sentence2));
}

TEST(TestSentenceSimilarity, simple5)
{
    std::string sentence1 {"My name is Schwarf Toll"};
    std::string sentence2 {"Toll"};
    EXPECT_TRUE(are_sentences_similar(sentence1, sentence2));
}
