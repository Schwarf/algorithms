//
// Created by andreas on 23.04.24.
//

#ifndef DATA_STRUCTURES_FIBONACCI_HEAP_H
#define DATA_STRUCTURES_FIBONACCI_HEAP_H

#include <concepts>
#include <compare>

template<typename T>
concept strong_ordered = requires(T a, T b) {
    { a <=> b } -> std::same_as<std::strong_ordering>;
};

template<typename KeyType, typename ValueType> requires strong_ordered<KeyType>
struct Node {
    KeyType key;
    ValueType value;
    Node *child{nullptr};
    Node *parent{nullptr};
    Node *left{this};
    Node *right{this};
    bool is_marked{};
    int number_of_children{};

    Node(KeyType key, ValueType value) : key(key), value(value) {}
};


#endif //DATA_STRUCTURES_FIBONACCI_HEAP_H
