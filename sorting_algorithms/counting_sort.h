//
// Created by andreas on 01.03.23.
//

#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <type_traits>
#include <vector>

template<typename T>
struct is_any_integer {
    static constexpr bool value =
            std::is_integral_v<T> && !std::is_same_v<T, bool> && !std::is_same_v<T, char> &&
            !std::is_same_v<T, wchar_t>;
};

template<typename Container, typename Element, typename = std::void_t<decltype(std::declval<Container>()[0]),
        decltype(std::declval<Container>().size())>,
        typename std::enable_if_t<is_any_integer<Element>::value, int> = 0>
void counting_sort(Container &container, const Element max_value, const Element min_value) {
    auto element_counts = std::vector<Element>((max_value - min_value + 1), 0);
    for (const auto &element: container)
        element_counts[element - min_value]++;

    for (size_t index = 1; index < element_counts.size(); ++index)
        element_counts[index] += element_counts[index - 1];

    Container result(container.size(), {});
    for (size_t index = container.size(); index--;) {
        auto i = element_counts[container[index] - min_value] - 1;
        result[i] = container[index];
        element_counts[container[index] - min_value] -= 1;
    }
    container = result;
}


#endif //COUNTING_SORT_H
