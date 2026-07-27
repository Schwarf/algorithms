//
// Created by andreas on 26.07.26.
//

#ifndef ALGORITHMS_RADIX_SORT_H
#define ALGORITHMS_RADIX_SORT_H

#include <vector>
#include <utility>
#include <cstdint>
#include <array>

template <std::unsigned_integral T>
void radix_sort(std::vector<T>& array)
{
    if (array.size() < 2)
        return;

    constexpr std::size_t radix = 256;
    constexpr int bits_per_pass = 8;
    constexpr int passes = std::numeric_limits<T>::digits / bits_per_pass;

    std::vector<std::uint32_t> buffer(array.size());
    for (int pass = 0; pass < passes; ++pass)
    {
        std::array<int, radix> counts{};
        const int bit_shift = pass * bits_per_pass;

        // Count occurrences of each byte value
        for (const auto value : array)
        {
            const T digit = (value >> bit_shift) & T{0xFFu};
            ++counts[digit];
        }

        // Convert counts into starting positions
        std::array<int, radix> positions{};
        for (int i = 1; i < radix; ++i)
        {
            positions[i] = positions[i - 1] + counts[i - 1];
        }

        for (const auto value: array)
        {
            const auto digit = (value >> bit_shift) & T{0xFFu};
            buffer[positions[digit]] = value;
            ++positions[digit];
        }
        array.swap(buffer);
    }

}

#endif // ALGORITHMS_RADIX_SORT_H
