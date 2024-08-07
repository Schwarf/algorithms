//
// Created by andreas on 01.03.23.
//

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <type_traits>

template<typename Container, typename = std::void_t<decltype(std::declval<Container>()[0]),
        decltype(std::declval<Container>().size())>>
int partition(Container &container, int low_index, int high_index) {
    auto pivot = container[high_index];
    int index = low_index - 1;
    for (int j = low_index; j < high_index; j++) {
        if (container[j] < pivot) {
            index++;
            std::swap(container[index], container[j]);
        }
    }
    std::swap(container[index + 1], container[high_index]);
    return index + 1;
}

template<typename Container, typename = std::void_t<decltype(std::declval<Container>()[0]),
        decltype(std::declval<Container>().size())>>
void quick_sort_(Container &container, int low_index, int high_index) {
    if (low_index < high_index) {
        int pivot_index = partition(container, low_index, high_index);
        quick_sort_(container, low_index, pivot_index - 1);
        quick_sort_(container, pivot_index + 1, high_index);
    }
}

// C++17 void_t-trick (SFINAE): std::void_t takes arbitrary number of different template arguments and maps
// them all to void e.g. void_t<int, double> is equivalent to void. So we specify a template specialisation
// if and only if the Container type has an index-operator and has the "size" method.
template<typename Container, typename = std::void_t<decltype(std::declval<Container>()[0]),
        decltype(std::declval<Container>().size())>>
void quick_sort(Container &container) {
    if (!container.size())
        return;
    int low_index{};
    int high_index = container.size() - 1;
    quick_sort_(container, low_index, high_index);
}

#endif //QUICK_SORT_H
