//
// Created by andreas on 26.07.26.
//

#ifndef ALGORITHMS_RADIX_SORT_H
#define ALGORITHMS_RADIX_SORT_H

#include <vector>
#include <utility>
#include <cstdint>
#include <array>

void radix_sort(std::vector<std::uint32_t>& array)
{
    if (array.size() < 2)
        return;

    constexpr std::size_t radix = 256;
    constexpr int bits_per_pass = 8;
    constexpr int passes = 32 / bits_per_pass;

    std::vector<std::uint32_t> sorted_array(array.size());
    for (int pass = 0; pass < passes; ++pass)
    {
        std::array<int, radix> counts{};
        const int bit_shift = pass * bits_per_pass;

        // Count occurences of each byte value
        for (std::uint32_t value : array)
        {
            const std::uint32_t digit = (value >> bit_shift) & 0xFFu;
            ++counts[digit];
        }

        // Convert counts into starting positions
        std::array<int, radix> positions{};
        for (int i{}; i < radix; ++i)
        {
            positions[i] = positions[i - 1] + counts[i - 1];
        }

    }


}

#endif // ALGORITHMS_RADIX_SORT_H
