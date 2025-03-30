//
// Created by andreas on 24.03.24.
//

#ifndef USED_CONCEPTS_H
#define USED_CONCEPTS_H
#include <functional>
#include <optional>

// Define a concept to check if a type is hashable.
template <typename T>
concept is_hashable = requires(T t)
{
    { std::hash<T>{}(t) } -> std::convertible_to<size_t>;
};

template <typename T>
concept is_optional_type = std::same_as<T, std::optional<typename T::value_type>>;


#endif //USED_CONCEPTS_H
