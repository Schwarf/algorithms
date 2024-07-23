//
// Created by andreas on 01.03.23.
//

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "used_concepts.h"

template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type>
void heapify(Container &container, int n, int index) {

    int index_largest_element = index; // index is root element and shall be largest of 3 (root, left, right child)
    int index_left_child = 2 * index + 1;
    int index_right_child = 2 * index + 2;

    if (index_left_child < n && container[index_left_child] > container[index_largest_element])
        index_largest_element = index_left_child;

    if (index_right_child < n && container[index_right_child] > container[index_largest_element])
        index_largest_element = index_right_child;

    if (index_largest_element != index) {
        std::swap(container[index], container[index_largest_element]);
        heapify<Container>(container, n, index_largest_element);
    }

}

// heapify for container with pointers
template<typename Container>
requires IndexedContainer<Container> && (!NoPointerElement<typename Container::value_type>)
void heapify(Container &container, int n, int index) {

    int index_largest_element = index; // index is root element and shall be largest of 3 (root, left, right child)
    int index_left_child = 2 * index + 1;
    int index_right_child = 2 * index + 2;

    if (index_left_child < n && *container[index_left_child] > *container[index_largest_element])
        index_largest_element = index_left_child;

    if (index_right_child < n && *container[index_right_child] > *container[index_largest_element])
        index_largest_element = index_right_child;

    if (index_largest_element != index) {
        std::swap(*container[index], *container[index_largest_element]);
        heapify<Container>(container, n, index_largest_element);
    }

}


template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type>
void heap_sort(Container &container) {
    if (!container.size())
        return;
    int n = container.size();
    // First we heapify the array, that means we have find the maximum element in the array and propagate it to index 0
    // We do that starting from index= n/2-1 (with children at 2*index+1 and 2*index+2) and go all the way down to 0.
    for (int index = n / 2 - 1; index >= 0; --index)
        heapify(container, n, index);

    for (int index = n - 1; index > 0; --index) {
        // we swap the current maximum to the end
        std::swap(container[0], container[index]);
        // we heapify the remaining array
        heapify<Container>(container, index, 0);
    }
}

// heap sort for container with pointers
template<typename Container>
requires IndexedContainer<Container> && (!NoPointerElement<typename Container::value_type>)
void heap_sort(Container &container) {
    if (!container.size())
        return;
    int n = container.size();
    // First we heapify the array, that means we have find the maximum element in the array and propagate it to index 0
    // We do that starting from index= n/2-1 (with children at 2*index+1 and 2*index+2) and go all the way down to 0.
    for (int index = n / 2 - 1; index >= 0; --index)
        heapify(container, n, index);

    for (int index = n - 1; index > 0; --index) {
        // we swap the current maximum to the end
        std::swap(container[0], container[index]);
        // we heapify the remaining array
        heapify<Container>(container, index, 0);
    }
}

#endif //HEAP_SORT_H
