#ifndef MINIMUM_SWAPS_H
#define MINIMUM_SWAPS_H
// Given an integer array we need to swap the largest number to the back and the smallest one to the front.
// Return the minimum number of swaps.
// LC 2340
#include <algorithm>
#include <vector>
#include <limits>

int minimum_swaps(const std::vector<int>& input)
{
    int n = input.size();
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
    }
    for (int i{n - 1}; i > -1; --i)
    {
        if (input[i] > max)
        {
            max = input[i];
            max_index = i;
        }
    }
    int swaps = min_index;
    swaps += n - 1 - max_index;
    if (max_index < min_index)
    {
        swaps--;
    }
    return swaps;
}

int minimum_swaps_concise(std::vector<int>& nums)
{
    auto it_min = std::min_element(nums.begin(), nums.end());
    auto it = std::find(nums.rbegin(), nums.rend(), *std::max_element(nums.begin(), nums.end()));
    // Convert reverse iterator to normal iterator
    auto it_max = std::prev(it.base());
    auto result = static_cast<int>(std::distance(nums.begin(), it_min)) + static_cast<int>(std::distance(
        it_max, nums.end())) - 1;

    if (std::distance(nums.begin(), it_min) > std::distance(nums.begin(), it_max))
    {
        return result - 1;
    }
    return result;
}
#endif //MINIMUM_SWAPS_H
