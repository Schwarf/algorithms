//
// Created by andreas on 02.10.26.
//

#include "../../digit-DP/rotated_digits.h"
#include "gtest/gtest.h"

#include <array>
#include <tuple>

namespace
{
bool is_good_after_rotation(int value)
{
    int rotated_value{};
    int multiplier{1};
    int remaining{value};

    while (remaining > 0)
    {
        const auto digit = remaining % 10;
        switch (digit)
        {
        case 0:
        case 1:
        case 8:
            rotated_value += digit * multiplier;
            break;
        case 2:
            rotated_value += 5 * multiplier;
            break;
        case 5:
            rotated_value += 2 * multiplier;
            break;
        case 6:
            rotated_value += 9 * multiplier;
            break;
        case 9:
            rotated_value += 6 * multiplier;
            break;
        default:
            return false;
        }

        multiplier *= 10;
        remaining /= 10;
    }

    return rotated_value != value;
}

int brute_force_rotated_digits(int n)
{
    int count{};
    for (int value{1}; value <= n; ++value)
    {
        if (is_good_after_rotation(value))
            ++count;
    }
    return count;
}
}

class SetupRotatedDigitsTest : public testing::TestWithParam<std::tuple<int, int>>
{
};

constexpr std::array<std::tuple<int, int>, 13> rotated_digits_examples{
    std::make_tuple(0, 0),
    std::make_tuple(1, 0),
    std::make_tuple(2, 1),
    std::make_tuple(9, 4),
    std::make_tuple(10, 4),
    std::make_tuple(20, 9),
    std::make_tuple(25, 12),
    std::make_tuple(50, 16),
    std::make_tuple(88, 32),
    std::make_tuple(99, 40),
    std::make_tuple(100, 40),
    std::make_tuple(857, 247),
    std::make_tuple(1000, 316),
};

INSTANTIATE_TEST_SUITE_P(RotatedDigitsKnownValues, SetupRotatedDigitsTest, ::testing::ValuesIn(rotated_digits_examples));

TEST_P(SetupRotatedDigitsTest, returns_number_of_good_integers)
{
    const auto n = std::get<0>(GetParam());
    const auto expected_count = std::get<1>(GetParam());

    EXPECT_EQ(expected_count, rotated_digits(n));
}

TEST(RotatedDigitsTest, matches_brute_force_for_small_inputs)
{
    for (int n{}; n <= 250; ++n)
    {
        EXPECT_EQ(brute_force_rotated_digits(n), rotated_digits(n)) << "n = " << n;
    }
}

TEST(RotatedDigitsTest, counts_good_numbers_across_digit_boundaries)
{
    for (const auto n : {999, 1000, 10000})
    {
        EXPECT_EQ(brute_force_rotated_digits(n), rotated_digits(n)) << "n = " << n;
    }
}
