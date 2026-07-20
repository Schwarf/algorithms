//
// Created by andreas on 09.06.22.
//

#ifndef LAST_APPEARANCE_IN_SORTED_VECTOR_H
#define LAST_APPEARANCE_IN_SORTED_VECTOR_H
#include <stdexcept>
#include <type_traits>
#include <vector>


template <typename T>
int last_appearance_index(std::vector<T>& input, T target)
{
    int left = 0;
    int right = static_cast<int>(input.size()) - 1;
    int index = -1;

    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (input[mid] <= target)
        {
            if (input[mid] == target)
                index = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return index;
}

#endif // LAST_APPEARANCE_IN_SORTED_VECTOR_H
