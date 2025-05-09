//
// Created by andreas on 25.03.23.
//

#ifndef MAXIMUM_SUBARRAY_KADANE_ALGORITHM_H
#define MAXIMUM_SUBARRAY_KADANE_ALGORITHM_H

#include <algorithm>
#include "used_concepts.h"

template<typename Container>
requires IndexedContainer<Container> && std::is_arithmetic_v<typename Container::value_type>
Container::value_type maximum_subarray_kadane_algorithm(const Container &container) {
    if (container.size() < 0)
        return std::numeric_limits<typename Container::value_type>::min();
    typename Container::value_type maximum_so_far{std::numeric_limits<typename Container::value_type>::min()};
    typename Container::value_type maximum_ending_here{};
    for (int i{}; i < container.size(); ++i) {
        maximum_ending_here = std::max(maximum_ending_here + container[i], container[i]);
        maximum_so_far = std::max(maximum_so_far, maximum_ending_here);
    }
    return maximum_so_far;
}

#endif //MAXIMUM_SUBARRAY_KADANE_ALGORITHM_H
