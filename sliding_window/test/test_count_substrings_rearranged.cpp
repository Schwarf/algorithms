#include "./../count_substrings_rearranged.h"
#include "gtest/gtest.h"

TEST(TestCountSubstringsRearranged, countsSampleWithOverlappingValidSubstrings)
{
    const std::string word1{"bcca"};
    const std::string word2{"abc"};

    EXPECT_EQ(1, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, countsAllSubstringsThatContainRequiredCharacters)
{
    const std::string word1{"abcabc"};
    const std::string word2{"abc"};

    EXPECT_EQ(10, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, handlesRepeatedCharactersInPrefix)
{
    const std::string word1{"aaab"};
    const std::string word2{"aa"};

    EXPECT_EQ(5, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, ignoresExtraCharactersNotInPrefix)
{
    const std::string word1{"zzazbz"};
    const std::string word2{"ab"};

    EXPECT_EQ(6, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, returnsZeroWhenPrefixIsLongerThanInput)
{
    const std::string word1{"ab"};
    const std::string word2{"abc"};

    EXPECT_EQ(0, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, returnsZeroWhenRequiredCharactersAreMissing)
{
    const std::string word1{"aaaa"};
    const std::string word2{"ab"};

    EXPECT_EQ(0, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, emptyInputWithNonEmptyPrefix)
{
    const std::string word1;
    const std::string word2{"a"};

    EXPECT_EQ(0, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, exactLengthPermutationIsValid)
{
    const std::string word1{"bca"};
    const std::string word2{"abc"};

    EXPECT_EQ(1, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, exactLengthButMissingRequiredCountIsInvalid)
{
    const std::string word1{"abb"};
    const std::string word2{"abc"};

    EXPECT_EQ(0, count_substrings_rearranged(word1, word2));
}

TEST(TestCountSubstringsRearranged, singleCharacterPrefixCountsAllContainingSubstrings)
{
    const std::string word1{"aaaa"};
    const std::string word2{"a"};

    EXPECT_EQ(10, count_substrings_rearranged(word1, word2));
}
