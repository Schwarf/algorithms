#include "graphs/topological_sort/alien_alphabet.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <utility>

namespace {

// Check membership and explicit constraints without requiring a particular
// tie-breaking order for characters whose relative order is unknown.
void expect_valid_alphabet(const std::vector<std::string>& words,
                           std::string characters,
                           const std::vector<std::pair<char, char>>& constraints = {})
{
    const auto alphabet = get_alphabet(words);
    auto sorted_alphabet = alphabet;
    std::sort(sorted_alphabet.begin(), sorted_alphabet.end());
    std::sort(characters.begin(), characters.end());
    ASSERT_EQ(sorted_alphabet, characters);
    for (const auto& [before, after] : constraints) {
        EXPECT_LT(alphabet.find(before), alphabet.find(after))
            << before << " must precede " << after << " in " << alphabet;
    }
}

} // namespace

TEST(GetAlphabet, ClassicDictionary)
{
    EXPECT_EQ(get_alphabet({"wrt", "wrf", "er", "ett", "rftt"}), "wertf");
}

TEST(GetAlphabet, AnotherUniqueOrdering)
{
    EXPECT_EQ(get_alphabet({"hrn", "hrf", "er", "enn", "rfnn"}), "hernf");
}

TEST(GetAlphabet, TwoCharactersInReverseConventionalOrder)
{
    EXPECT_EQ(get_alphabet({"z", "a"}), "za");
}

TEST(GetAlphabet, EmptyDictionary)
{
    EXPECT_EQ(get_alphabet({}), "");
}

TEST(GetAlphabet, OnlyEmptyWords)
{
    EXPECT_EQ(get_alphabet({""}), "");
    EXPECT_EQ(get_alphabet({"", "", ""}), "");
}

TEST(GetAlphabet, SingleRepeatedCharacter)
{
    EXPECT_EQ(get_alphabet({"aaaa"}), "a");
}

TEST(GetAlphabet, SingleWordIncludesEveryDistinctCharacter)
{
    expect_valid_alphabet({"banana"}, "abn");
}

TEST(GetAlphabet, IdenticalWordsDoNotAddConstraints)
{
    expect_valid_alphabet({"cab", "cab", "cab"}, "abc");
}

TEST(GetAlphabet, IncreasingPrefixesAreValid)
{
    expect_valid_alphabet({"", "a", "ab", "abc"}, "abc");
}

TEST(GetAlphabet, LongerWordBeforeItsPrefixIsInvalid)
{
    EXPECT_EQ(get_alphabet({"abc", "ab"}), "");
    EXPECT_EQ(get_alphabet({"ab", "ab", "a"}), "");
}

TEST(GetAlphabet, NonemptyWordBeforeEmptyWordIsInvalid)
{
    EXPECT_EQ(get_alphabet({"a", ""}), "");
}

TEST(GetAlphabet, OnlyFirstDifferingCharacterAddsConstraint)
{
    // The suffixes must not introduce b -> a and a -> b constraints.
    expect_valid_alphabet({"zba", "yab"}, "abyz", {{'z', 'y'}});
}

TEST(GetAlphabet, RepeatedDependenciesAreHandled)
{
    expect_valid_alphabet({"za", "zb", "ca", "cb"}, "abcz",
                          {{'a', 'b'}, {'z', 'c'}});
}

TEST(GetAlphabet, DisconnectedCharactersAreIncluded)
{
    expect_valid_alphabet({"ax", "ay", "bz"}, "abxyz",
                          {{'x', 'y'}, {'a', 'b'}});
}

TEST(GetAlphabet, MultipleDependenciesConvergeOnOneCharacter)
{
    expect_valid_alphabet({"ax", "az", "bx", "bz", "cz"}, "abcxz",
                          {{'x', 'z'}, {'a', 'b'}, {'b', 'c'}});
}

TEST(GetAlphabet, TwoCharacterCycleIsInvalid)
{
    EXPECT_EQ(get_alphabet({"z", "x", "z"}), "");
}

TEST(GetAlphabet, LongerCycleIsInvalidEvenWithIndependentCharacter)
{
    EXPECT_EQ(get_alphabet({"ax", "bx", "cx", "ax"}), "");
}

TEST(GetAlphabet, AllTwentySixCharacters)
{
    const std::string alphabet = "zyxwvutsrqponmlkjihgfedcba";
    std::vector<std::string> words;
    for (char character : alphabet) {
        words.emplace_back(1, character);
    }
    EXPECT_EQ(get_alphabet(words), alphabet);
}
