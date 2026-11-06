//
// Created by andreas on 03.11.26.
//

#include "binary_string_without_consecutive_ones.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

namespace
{
void expect_binary_strings_equal(std::vector<std::string> actual,
                                 std::vector<std::string> expected)
{
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(expected, actual);
}
} // namespace

TEST(BinaryStringsWithoutConsecutiveOnes, ReturnsTheEmptyStringForLengthZero)
{
    expect_binary_strings_equal(binary_strings(0), {""});
}

TEST(BinaryStringsWithoutConsecutiveOnes, GeneratesAllStringsOfLengthOne)
{
    expect_binary_strings_equal(binary_strings(1), {"0", "1"});
}

TEST(BinaryStringsWithoutConsecutiveOnes, ExcludesConsecutiveOnesAtLengthTwo)
{
    expect_binary_strings_equal(binary_strings(2), {"00", "01", "10"});
}

TEST(BinaryStringsWithoutConsecutiveOnes, GeneratesAllValidStringsOfLengthFour)
{
    expect_binary_strings_equal(binary_strings(4),
                                {
                                    "0000",
                                    "0001",
                                    "0010",
                                    "0100",
                                    "0101",
                                    "1000",
                                    "1001",
                                    "1010",
                                });
}

TEST(BinaryStringsWithoutConsecutiveOnes, ProducesEveryValidStringExactlyOnce)
{
    constexpr int length{8};
    const auto result = binary_strings(length);
    std::unordered_set<std::string> unique_strings;

    EXPECT_EQ(55U, result.size());

    for (const auto& binary_string : result)
    {
        EXPECT_EQ(static_cast<std::size_t>(length), binary_string.size());
        EXPECT_EQ(std::string::npos, binary_string.find("11")) << binary_string;
        EXPECT_TRUE(std::all_of(binary_string.begin(),
                                binary_string.end(),
                                [](const char character)
                                {
                                    return character == '0' || character == '1';
                                }))
            << binary_string;
        EXPECT_TRUE(unique_strings.insert(binary_string).second)
            << "duplicate binary string: " << binary_string;
    }
}
