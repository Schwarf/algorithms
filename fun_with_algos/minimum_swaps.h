#ifndef MINIMUM_SWAPS_H
#define MINIMUM_SWAPS_H
// Given an integer array we need to swap the largest number to the back and the smallest one to the front.
// Return the minimum number of swaps.
#include <vector>
#include <limits>

int minimum_swaps(const std::vector<int>& input)
{
    int min_index{};
    int max_index{};
    int min = ::std::numeric_limits<int>::max();
    int max = ::std::numeric_limits<int>::min();
    for (int i{}; i < input.size(); ++i)
    {
        if (input[i] < min)
        {
            min = input[i];
            min_index = i;
        }
        if (input[i] > max)
        {
            max = input[i];
            max_index = i;
        }
    }
    int swaps = min_index;
    swaps += input.size() - 1 - max_index;
    if (max_index < min_index)
    {
        swaps--;
    }
    return swaps;
}
#endif //MINIMUM_SWAPS_H
