//
// Created by andreas on 11.03.23.
//

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <cstddef>
#include "used_concepts.h"

template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type>
void insertion_sort(Container &container) {
    auto size = container.size();
    for (size_t index1 = 0; index1 < size; ++index1) {
        for (size_t index2 = index1; index2 > 0; --index2) {
            if (container[index2] < container[index2 - 1]) {
                std::swap(container[index2], container[index2 - 1]);
            }
        }
    }
}

#endif //INSERTION_SORT_H
