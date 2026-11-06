#include "palindrome_partitioning.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

namespace
{
using Partitions = std::vector<std::vector<std::string>>;

void expect_partitions_equal(Partitions actual, Partitions expected)
{
    // Partition order is unspecified; substring order within each partition matters.
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(expected, actual);
}
} // namespace

TEST(PalindromePartitioning, EmptyInputHasOneEmptyPartition)
{
    expect_partitions_equal(palindrome_partitioning(""), {{}});
}

TEST(PalindromePartitioning, SingleCharacterHasOnePartition)
{
    expect_partitions_equal(palindrome_partitioning("x"), {{"x"}});
}

TEST(PalindromePartitioning, TwoDistinctCharactersMustBeSeparated)
{
    expect_partitions_equal(palindrome_partitioning("ab"), {{"a", "b"}});
}

TEST(PalindromePartitioning, TwoEqualCharactersCanBeJoinedOrSeparated)
{
    expect_partitions_equal(palindrome_partitioning("aa"), {{"a", "a"}, {"aa"}});
}

TEST(PalindromePartitioning, FindsAllPartitionsForMixedInput)
{
    expect_partitions_equal(palindrome_partitioning("aab"),
                            {{"a", "a", "b"}, {"aa", "b"}});
}

TEST(PalindromePartitioning, DistinctCharactersHaveOnlySingletonPartition)
{
    expect_partitions_equal(palindrome_partitioning("abcd"), {{"a", "b", "c", "d"}});
}

TEST(PalindromePartitioning, IncludesWholeOddLengthPalindrome)
{
    expect_partitions_equal(palindrome_partitioning("aba"), {{"a", "b", "a"}, {"aba"}});
}

TEST(PalindromePartitioning, IncludesNestedEvenLengthPalindromes)
{
    expect_partitions_equal(palindrome_partitioning("abba"),
                            {{"a", "b", "b", "a"}, {"a", "bb", "a"}, {"abba"}});
}

TEST(PalindromePartitioning, FindsPalindromesAfterNonPalindromicPrefixes)
{
    expect_partitions_equal(palindrome_partitioning("abcbd"),
                            {{"a", "b", "c", "b", "d"}, {"a", "bcb", "d"}});
}

TEST(PalindromePartitioning, FindsIndependentChoicesInMultipleParts)
{
    expect_partitions_equal(palindrome_partitioning("aabb"),
                            {{"a", "a", "b", "b"}, {"aa", "b", "b"},
                             {"a", "a", "bb"}, {"aa", "bb"}});
}

TEST(PalindromePartitioning, RepeatedCharactersProduceEveryPartitionExactlyOnce)
{
    expect_partitions_equal(palindrome_partitioning("aaaa"),
                            {{"a", "a", "a", "a"}, {"aa", "a", "a"},
                             {"a", "aa", "a"}, {"a", "a", "aa"},
                             {"aa", "aa"}, {"aaa", "a"}, {"a", "aaa"}, {"aaaa"}});
}

TEST(PalindromePartitioning, CharacterComparisonIsCaseSensitive)
{
    expect_partitions_equal(palindrome_partitioning("Aa"), {{"A", "a"}});
}

TEST(PalindromePartitioning, PreservesWhitespaceAndPunctuation)
{
    expect_partitions_equal(palindrome_partitioning("! !"), {{"!", " ", "!"}, {"! !"}});
}

TEST(PalindromePartitioning, PreservesEmbeddedNullCharacters)
{
    const std::string input("a\0a", 3);
    expect_partitions_equal(palindrome_partitioning(input),
                            {{"a", std::string(1, '\0'), "a"}, {input}});
}

TEST(PalindromePartitioning, RepeatedCallsHaveIndependentResults)
{
    expect_partitions_equal(palindrome_partitioning("aa"), {{"a", "a"}, {"aa"}});
    expect_partitions_equal(palindrome_partitioning("b"), {{"b"}});
    expect_partitions_equal(palindrome_partitioning(""), {{}});
}
