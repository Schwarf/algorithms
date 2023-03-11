//
// Created by andreas on 04.03.23.
//

#ifndef USED_CONCEPTS_H
#define USED_CONCEPTS_H
#include <concepts>

template <typename Container>
concept IndexedContainer = requires(Container c)
{
	{ c[0] } -> std::same_as<typename Container::value_type&>;
	{ c.size() } -> std::integral;
};

template <typename Element>
concept NoPointerElement = !std::is_pointer_v<Element>;

#endif //USED_CONCEPTS_H
