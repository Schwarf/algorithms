//
// Created by andreas on 27.07.26.
//
#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>

#include "radix_sort.h"
#include "test_setup.h"

TEST_F(SetupSortingTests, radix_sort_empty_vector)
{
    std::vector<std::uint32_t> result{};
    const auto expected_result = result;

    radix_sort(result);

    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, radix_sort_single_value)
{
    std::vector<std::uint32_t> result{42};
    const auto expected_result = result;

    radix_sort(result);

    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, radix_sort_unsigned_int_vector)
{
    std::vector<std::uint32_t> result{
        329, 457, 657, 839, 436, 720, 355, 0, 12, 12, 1, 255, 256, 1024
    };
    auto expected_result = result;
    std::sort(expected_result.begin(), expected_result.end());

    radix_sort(result);

    EXPECT_EQ(result, expected_result);
}

TEST_F(SetupSortingTests, radix_sort_handles_all_uint32_byte_positions)
{
    std::vector<std::uint32_t> result{
        std::numeric_limits<std::uint32_t>::max(),
        0x00000001u,
        0x00000100u,
        0x00010000u,
        0x01000000u,
        0x000000FFu,
        0x0000FF00u,
        0x00FF0000u,
        0xFF000000u,
        0x7FFFFFFFu,
        0x80000000u,
        0u
    };
    auto expected_result = result;
    std::sort(expected_result.begin(), expected_result.end());

    radix_sort(result);

    EXPECT_EQ(result, expected_result);
}
