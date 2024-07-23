//
// Created by andreas on 12.03.23.
//

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <cstddef>
#include "used_concepts.h"

template<typename Container>
requires IndexedContainer<Container> && NoPointerElement<typename Container::value_type>
void selection_sort(Container &container) {
    auto size = container.size();
    for (size_t index = 0; index < size; ++index) {
        auto minimum_index = index;
        for (size_t index2 = index + 1; index2 < size; ++index2) {
            if (container[index2] < container[minimum_index]) {
                minimum_index = index2;
            }
        }
        std::swap(container[index], container[minimum_index]);
    }

}

#endif //SELECTION_SORT_H
