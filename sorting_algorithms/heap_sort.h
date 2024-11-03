//
// Created by andreas on 01.03.23.
//

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "used_concepts.h"

#include <concepts>
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>


// Heap-sort works similar like the heap-data structure. Depending on the sorting (ascending or descending)
// we heapify the entire array. Then we swap the extremum-value to the last position.
// We reduce the size of the heap (not the array) and repeat the above procedure until the whole array is sorted.

// Assuming IndexedContainer and NoPointerElement concepts are defined elsewhere
// IndexedContainer checks if the container is indexable, and NoPointerElement checks if elements are not pointers

template<typename Container, typename Comparator>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type> && Sortable<typename Container::value_type>
void heapify(Container &container, int n, int index, Comparator comparator) {
    int index_largest_element = index; // index is root element and shall be largest of 3 (root, left child, right child)
    int index_left_child = 2 * index + 1;
    int index_right_child = 2 * index + 2;

    if (index_left_child < n && comparator(container[index_largest_element], container[index_left_child]))
        index_largest_element = index_left_child;

    if (index_right_child < n && comparator(container[index_largest_element], container[index_right_child]))
        index_largest_element = index_right_child;

    if (index_largest_element != index) {
        std::swap(container[index], container[index_largest_element]);
        heapify(container, n, index_largest_element, comparator);
    }
}

// heapify function with comparator for pointer elements
template<typename Container, typename Comparator>
requires IndexedContainer<Container> && (!NoPointerElement<typename Container::value_type>)
void heapify(Container &container, int n, int index, Comparator comparator) {
    int index_largest_element = index; // index is root element and shall be largest of 3 (root, left, right child)
    int index_left_child = 2 * index + 1;
    int index_right_child = 2 * index + 2;

    if (index_left_child < n && comparator(*container[index_largest_element], *container[index_left_child]))
        index_largest_element = index_left_child;

    if (index_right_child < n && comparator(*container[index_largest_element], *container[index_right_child]))
        index_largest_element = index_right_child;

    if (index_largest_element != index) {
        std::swap(*container[index], *container[index_largest_element]);
        heapify(container, n, index_largest_element, comparator);
    }
}

// heap_sort function with comparator for general elements
template<typename Container, typename Comparator = std::less<>>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type>
void heap_sort(Container &container, Comparator comparator = Comparator()) {
    if (!container.size())
        return;
    int n = container.size();
    // Ignore all leaves since they are considered in heapify
    // We ensure that each subtree rooted at the non-leaf nodes (starting at n/2 -1) becomes a valid heap.
    // The extremum-element (max or min) is put at index=0.
    for (int index = n / 2 - 1; index >= 0; --index)
        heapify(container, n, index, comparator);

    // Now we have know the extremum element and we put in the last position.
    // Then we heapify the remaining container for [0, n-1)
    for (int index = n - 1; index > 0; --index) {
        std::swap(container[0], container[index]);
        heapify(container, index, 0, comparator);
    }
}

// heap_sort function with comparator for pointer elements
template<typename Container, typename Comparator = std::less<>>
requires IndexedContainer<Container> && (!NoPointerElement<typename Container::value_type>)
void heap_sort(Container &container, Comparator comparator = Comparator()) {
    if (!container.size())
        return;
    int n = container.size();
    // Ignore all leaves since they are considered in heapify
    // We ensure that each subtree rooted at the non-leaf nodes (starting at n/2 -1) becomes a valid heap.
    // The extremum-element (max or min) is put at index=0.
    for (int index = n / 2 - 1; index >= 0; --index)
        heapify(container, n, index, comparator);

    // Now we have know the extremum element and we put in the last position.
    // Then we heapify the remaining container for [0, n-1)
    for (int index = n - 1; index > 0; --index) {
        std::swap(*container[0], *container[index]);
        heapify(container, index, 0, comparator);
    }
}

#endif //HEAP_SORT_H
