//
// Created by andreas on 03.11.26.
//

#include "palindrome_generation.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <string>
#include <unordered_set>
#include <vector>

namespace
{
void expect_palindromes_equal(std::vector<std::string> actual,
                              std::vector<std::string> expected)
{
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(expected, actual);
}
} // namespace

TEST(PalindromeGeneration, ReturnsNoPalindromesWhenMaximumLengthIsZero)
{
    EXPECT_TRUE(palindromes("abc", 0).empty());
}

TEST(PalindromeGeneration, ReturnsNoPalindromesForAnEmptyAlphabet)
{
    EXPECT_TRUE(palindromes("", 4).empty());
}

TEST(PalindromeGeneration, ReusesTheOnlyAvailableCharacter)
{
    expect_palindromes_equal(palindromes("x", 5),
                             {"x", "xx", "xxx", "xxxx", "xxxxx"});
}

TEST(PalindromeGeneration, GeneratesTheDocumentedExample)
{
    expect_palindromes_equal(palindromes("ab", 2),
                             {"a", "b", "aa", "bb"});
}

TEST(PalindromeGeneration, GeneratesAllOddAndEvenLengthPalindromes)
{
    expect_palindromes_equal(palindromes("ab", 4),
                             {
                                 "a",
                                 "b",
                                 "aa",
                                 "bb",
                                 "aaa",
                                 "aba",
                                 "bab",
                                 "bbb",
                                 "aaaa",
                                 "abba",
                                 "baab",
                                 "bbbb",
                             });
}

TEST(PalindromeGeneration, ProducesEveryPalindromeExactlyOnce)
{
    constexpr int maximum_length{5};
    const std::string alphabet{"abc"};
    const auto result = palindromes(alphabet, maximum_length);
    const std::array<std::size_t, maximum_length + 1> expected_by_length{
        0, 3, 3, 9, 9, 27};
    std::array<std::size_t, maximum_length + 1> actual_by_length{};
    std::unordered_set<std::string> unique_palindromes;

    for (const auto& palindrome : result)
    {
        ASSERT_FALSE(palindrome.empty());
        ASSERT_LE(palindrome.size(), static_cast<std::size_t>(maximum_length));
        EXPECT_TRUE(std::equal(palindrome.begin(),
                               palindrome.end(),
                               palindrome.rbegin()))
            << palindrome;
        EXPECT_TRUE(std::all_of(palindrome.begin(),
                                palindrome.end(),
                                [&alphabet](const char character)
                                {
                                    return alphabet.find(character) != std::string::npos;
                                }))
            << palindrome;

        ++actual_by_length[palindrome.size()];
        EXPECT_TRUE(unique_palindromes.insert(palindrome).second)
            << "duplicate palindrome: " << palindrome;
    }

    EXPECT_EQ(expected_by_length, actual_by_length);
    EXPECT_EQ(51U, result.size());
}
