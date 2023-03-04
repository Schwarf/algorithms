//
// Created by andreas on 04.03.23.
//

#ifndef SORT_CONCEPTS_H
#define SORT_CONCEPTS_H
#include <concepts>

template <typename Container>
concept IndexedContainer = requires(Container c)
{
	{ c[0] } -> std::same_as<typename Container::value_type&>;
	{ c.size() } -> std::integral;
};

template <typename Element>
concept NoPointerElement = !std::is_pointer_v<Element>;

template <typename Container>
concept ElementContainer = requires(Container c)
{
	{ std::is_same_v<decltype(c[0]), typename Container::value_type> };
};
#endif //SORT_CONCEPTS_H
