//
// Created by andreas on 23.07.24.
//

#ifndef SORT_SORT_ARRAY_BY_INCREASING_FREQUENCY_H
#define SORT_SORT_ARRAY_BY_INCREASING_FREQUENCY_H
#include <map>
#include <vector>
#include "used_concepts.h"
// Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
// If multiple values have the same frequency, sort them in decreasing order.
// Return the sorted array.

template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type> && Sortable<typename Container::value_type>
void sort_by_increasing_frequency(Container & input)
{
    using element_type = typename Container::value_type;
    std::map<typename Container::value_type, int> frequencies;
    for(const auto element: input)
    {
        frequencies[element]++;
    }
    std::vector<std::pair<element_type, int>> pairs;
    for(const auto & [value, frequency]: frequencies)
    {
        pairs.emplace_back(value, frequency);
    }

    auto comparator = [](std::pair<element_type, int> & element1, std::pair<element_type, int> & element2) -> bool{
        if(element1.second == element2.second)
            return element1.first > element2.first;
        return element1.second < element2.second;
    };
    std::sort(pairs.begin(), pairs.end(), comparator);


    int index{};
    for(const auto & pair: pairs)
    {
        for(int i{}; i < pair.second; ++i)
        {
            input[index++] = pair.second;
        }
    }
 }

#endif //SORT_SORT_ARRAY_BY_INCREASING_FREQUENCY_H
