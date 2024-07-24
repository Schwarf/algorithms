//
// Created by andreas on 24.07.24.
//

#ifndef SORT_SORT_JUMBLED_NUMBERS_H
#define SORT_SORT_JUMBLED_NUMBERS_H
// You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system.
// mapping[i] = j means digit i should be mapped to digit j in this system.
// The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the
// integer with mapping[i] for all 0 <= i <= 9.
// You are also given another integer array nums. Return the array nums sorted in non-decreasing order
// based on the mapped values of its elements.
// Elements with the same mapped values should appear in the same relative order as in the input.
// The elements of nums should only be sorted based on their mapped values and not be replaced by them.

#include <vector>
#include <unordered_map>
#include <concepts>

template <typename T>
requires std::is_integral_v<T> && std::is_unsigned_v<T>
std::vector<T> sort_jumbled_numbers(std::vector<T> & mapping, std::vector<T> & values)
{
    std::vector<T> mapped_values;
    for(auto value : values)
    {
        auto current = value;
        if(current == 0)
            mapped_values.push_back(mapping[0]);
        else {
            int place{1};
            T mapped_value{};
            while (current) {
                mapped_value += place * mapping[current % 10];
                current /= 10;
                place *= 10;
            }
            mapped_values.push_back(mapped_value);
        }
    }

    auto comparator = [&](const T & v1, const T & v2) -> bool
    {
        return mapped_values[v1] < mapped_values[v2];
    };

    std::sort(values.begin(), values.end(), comparator);
    return values;
}

#endif //SORT_SORT_JUMBLED_NUMBERS_H
