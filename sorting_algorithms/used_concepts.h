//
// Created by andreas on 04.03.23.
//

#ifndef USED_CONCEPTS_H
#define USED_CONCEPTS_H
#include <concepts>
#include <bit>

template <typename Container>
concept IndexedContainer = requires(Container c)
{
	{ c[0] } -> std::same_as<typename Container::value_type&>;
	{ c.size() } -> std::integral;
};

template <std::size_t N >
concept PowerOfTwo = (N > 0) && (std::has_single_bit(N));

template <typename Element>
concept NoPointerElement = !std::is_pointer_v<Element>;

#endif //USED_CONCEPTS_H
