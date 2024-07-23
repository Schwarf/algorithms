//
// Created by andreas on 04.03.23.
//

#ifndef USED_CONCEPTS_H
#define USED_CONCEPTS_H

#include <concepts>
#include <bit>

template<typename Container>
concept IndexedContainer = requires(Container c)
{
    { c[0] } -> std::same_as<typename Container::value_type &>;
    { c.size() } -> std::integral;
};

template<std::size_t N>
concept PowerOfTwo = ((N > 0) && (std::has_single_bit(N))) || (N == 0);

template <typename T>
concept Sortable = requires(T a, T b) {
    { std::declval<T&>() = std::declval<T&>() } -> std::same_as<T&>;
    { std::declval<T&>() = std::declval<T>() } -> std::same_as<T&>;
    { std::declval<const T&>() < std::declval<const T&>() } -> std::convertible_to<bool>;
};

template<typename Element>
concept NoPointerElement = !std::is_pointer_v<Element>;

template<typename SequenceFunction>
concept SequenceFunctionTemplate = requires(SequenceFunction function, std::size_t container_size)
{
    { function(container_size) } -> std::same_as<std::vector<std::size_t>>;
};


#endif //USED_CONCEPTS_H
