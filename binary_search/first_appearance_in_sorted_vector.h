//
// Created by andreas on 09.06.22.
//

#ifndef FIRST_APPEARANCE_IN_SORTED_VECTOR_H
#define FIRST_APPEARANCE_IN_SORTED_VECTOR_H
#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename T>
int first_appearance_index(const std::vector<T>& input, T target)
{
    int left = 0;
    int right = static_cast<int>(input.size()) - 1;
    int index = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (input[mid] >= target)
        {
            if (input[mid] == target)
                index = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return index;
}

#endif // FIRST_APPEARANCE_IN_SORTED_VECTOR_H
