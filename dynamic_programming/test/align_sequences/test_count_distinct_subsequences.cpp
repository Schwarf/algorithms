//
// Created by andreas on 12.07.26.
//

#include "gtest/gtest.h"
#include "../../align_subsequences/count_distinct_subsequences.h"

TEST(TestCountDistinctSubsequences, canonicalExamples)
{
    EXPECT_EQ(3, count_distinct_subsequences("rabbbit", "rabbit"));
    EXPECT_EQ(5, count_distinct_subsequences("babgbag", "bag"));
}

TEST(TestCountDistinctSubsequences, emptyTarget)
{
    EXPECT_EQ(1, count_distinct_subsequences("", ""));
    EXPECT_EQ(1, count_distinct_subsequences("abc", ""));
}

TEST(TestCountDistinctSubsequences, emptySourceWithNonEmptyTarget)
{
    EXPECT_EQ(0, count_distinct_subsequences("", "a"));
}

TEST(TestCountDistinctSubsequences, targetLongerThanSource)
{
    EXPECT_EQ(0, count_distinct_subsequences("abc", "abcd"));
}

TEST(TestCountDistinctSubsequences, noMatchingSubsequence)
{
    EXPECT_EQ(0, count_distinct_subsequences("abc", "d"));
    EXPECT_EQ(0, count_distinct_subsequences("abc", "acb"));
}

TEST(TestCountDistinctSubsequences, repeatedCharactersCountCombinations)
{
    EXPECT_EQ(10, count_distinct_subsequences("aaaaa", "aaa"));
    EXPECT_EQ(6, count_distinct_subsequences("aaaa", "aa"));
}

TEST(TestCountDistinctSubsequences, exactMatch)
{
    EXPECT_EQ(1, count_distinct_subsequences("algorithm", "algorithm"));
}

TEST(TestCountDistinctSubsequences, caseSensitiveMatching)
{
    EXPECT_EQ(1, count_distinct_subsequences("aA", "A"));
    EXPECT_EQ(0, count_distinct_subsequences("a", "A"));
}
