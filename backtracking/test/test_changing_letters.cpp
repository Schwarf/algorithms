//
// Created by andreas on 03.11.26.
//

#include "changing_letters.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

namespace
{
void expect_letter_variations_equal(std::vector<std::string> actual,
                                    std::vector<std::string> expected)
{
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(expected, actual);
}
} // namespace

TEST(ChangingLetters, ReturnsTheEmptyStringForEmptyInput)
{
    std::string input;

    expect_letter_variations_equal(changing_letters(input), {""});
}

TEST(ChangingLetters, LeavesDigitsUnchanged)
{
    std::string input{"12345"};

    expect_letter_variations_equal(changing_letters(input), {"12345"});
}

TEST(ChangingLetters, GeneratesTheDocumentedExample)
{
    std::string input{"a1b2"};

    expect_letter_variations_equal(changing_letters(input),
                                   {"a1b2", "a1B2", "A1b2", "A1B2"});
}

TEST(ChangingLetters, HandlesInitiallyUppercaseAndLowercaseLetters)
{
    std::string input{"aB3"};

    expect_letter_variations_equal(changing_letters(input),
                                   {"ab3", "aB3", "Ab3", "AB3"});
}

TEST(ChangingLetters, ChangesRepeatedLettersIndependentlyWithoutDuplicates)
{
    std::string input{"aa"};

    expect_letter_variations_equal(changing_letters(input),
                                   {"aa", "aA", "Aa", "AA"});
}

TEST(ChangingLetters, DoesNotModifyTheInputString)
{
    std::string input{"a1B2c"};
    const auto original_input = input;

    const auto result = changing_letters(input);

    EXPECT_EQ(original_input, input);
    EXPECT_EQ(8U, result.size());
}
