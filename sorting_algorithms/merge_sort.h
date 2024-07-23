//
// Created by andreas on 07.03.23.
//

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "used_concepts.h"

// When we merge we have in the beginning two elements
template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type> &&
         Sortable<typename Container::value_type>
void merge(Container &container, int left, int mid, int right) {
    auto help = container;
    int first_half_index = left;
    int second_half_index = mid + 1;
    for (int index = left; index <= right; ++index) {
        if (first_half_index > mid)
            container[index] = help[second_half_index++];
        else if (second_half_index > right)
            container[index] = help[first_half_index++];
        else if (help[second_half_index] < help[first_half_index])
            container[index] = help[second_half_index++];
        else
            container[index] = help[first_half_index++];
    }
}

// We recursively look at smaller ranges of the container until only one element is left (that is always sorted).
// Then we merge.
template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type>
void recursive(Container &container, int left, int right) {
    if (right <= left)
        return;
    int mid = (right + left) / 2;
    recursive(container, left, mid);
    recursive(container, mid + 1, right);
    merge(container, left, mid, right);
}

template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type>
void merge_sort(Container &container) {
    if (!container.size())
        return;
    int n = container.size();
    recursive(container, 0, n - 1);
}


#endif //MERGE_SORT_H
