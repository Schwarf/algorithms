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


template<typename KeyType, typename ValueType> requires strong_ordered<KeyType>
class FibonacciHeap {

public:
    Node<KeyType, ValueType> *insert(const KeyType key, const ValueType &value) {
        auto node = new Node<KeyType, ValueType>(key, value);

        return node;
    }

private:
    void _insert(Node<KeyType, ValueType> *node) {
        _minimum_node = _merge(_minimum_node, node);
        _number_of_nodes++;

    }

    void _merge(Node<KeyType, ValueType> *node1, Node<KeyType, ValueType> *node2) {
        if (!node1)
            return node2;
        if (!node2)
            return node1;

        if (node1->key > node2->key)
            std::swap(node1, node2);
        

    }

    int _number_of_nodes{};
    Node<KeyType, ValueType> *_minimum_node = nullptr;

};

#endif //DATA_STRUCTURES_FIBONACCI_HEAP_H
