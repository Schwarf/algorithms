//
// Created by andreas on 11.03.23.
//

#ifndef USED_CONCEPTS_H
#define USED_CONCEPTS_H
#include <concepts>

template<typename Container>
concept IndexedContainerWithUnsignedIntegralElements = requires(Container c)
{
	{ c[0] } -> std::same_as<typename Container::value_type &>;
	{ c.size() } -> std::same_as<std::size_t>;
	requires std::unsigned_integral<typename Container::value_type>;
};

template <typename T>
concept UnsignedInteger64Bit = std::is_unsigned_v<T> && (sizeof(T) * 8 >= 64);

template <typename Element>
concept NoPointerElement = !std::is_pointer_v<Element>;

#endif //USED_CONCEPTS_H
