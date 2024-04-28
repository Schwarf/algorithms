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
    Node *prev{this};
    Node *next{this};
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

    ~FibonacciHeap() {
        if (!is_empty())
            _delete_root_list(_minimum_node);
    }

    bool is_empty() const {
        return _minimum_node == nullptr;
    }

private:

    void _delete_root_list(Node<KeyType, ValueType> *node) {
        auto node_prev = node->prev;
        do {
            auto current_node = node_prev;
            node_prev = node_prev->prev;
            if (current_node->child)
                _delete_root_list(current_node->child);
            if (current_node != node)
                delete current_node;

        } while (node_prev != node);
        delete node;
    }

    void _insert(Node<KeyType, ValueType> *node) {
        // Add node to the list of roots
        _minimum_node = _merge_into_list(_minimum_node, node);
        _number_of_nodes++;
    }

    void _merge_into_list(Node<KeyType, ValueType> *node1, Node<KeyType, ValueType> *node2) {
        if (!node1)
            return node2;
        if (!node2)
            return node1;
        // HERE STD::GREATER
        if (node1->key > node2->key)
            std::swap(node1, node2);

        // Inserting node1 before node2
        // Remember original next and prev nodes
        auto node1_next = node1->next;
        auto node2_prev = node2->prev;
        node1->next = node2;
        node2->prev = node1;

        node1_next->prev = node2_prev;
        node2_prev->next = node1_next;
        return node1;
    }

    void _remove_node_from_list(Node<KeyType, ValueType> *node) {
        // NOde is already removed from list;
        if (node->next == node)
            return;

        auto prev = node->prev;
        auto next = node->next;
        // Attach prev and next nodes to each other
        prev->next = next;
        next->prev = prev;
        // Self assign node prev and next pointers
        node->prev = node;
        node->next = node;
    }

    // Remove child from child-list of parent, decrement parents number of children
    //
    void _promote_child_to_root(Node<KeyType, ValueType> *child, Node<KeyType, ValueType> *parent) {
        parent->child = (child = child->next ? nullptr : child->next);
        _remove_node_from_list(child);
        parent->number_of_children--;
        _merge(_minimum_node, child);
        child->parent = nullptr;
        child->is_marked = false;
    }

    void _add_child(Node<KeyType, ValueType> *parent, Node<KeyType, ValueType> *child) {
        child->parent = parent;
        parent->child = _merge_into_list(parent->child, child);
        parent->number_of_children++;
        child->is_marked = false;
    }

    void _consolidate() {

    }

    void _decrease_key(Node<KeyType, ValueType> *node, KeyType new_key) {
        node->key = new_key;
        auto parent = node->parent;
        if (parent != nullptr && node->key < parent->key) {
            _promote_child_to_root(node, parent);

        }
        if (node->key < _minimum_node->key)
            _minimum_node = node;
    }

    void _propagate_promotion_to_root(Node<KeyType, ValueType> *node) {
        auto parent = node->parent;
        if (parent != nullptr) {
            if (node->is_marked == false)
                node->is_marked = true;
            else {
                _promote_child_to_root(node, parent);
                _propagate_promotion_to_root(parent);
            }
        }
    }

    int _number_of_nodes{};
    Node<KeyType, ValueType> *_minimum_node = nullptr; // Important note: _minimum_node is the most next node.

};

#endif //DATA_STRUCTURES_FIBONACCI_HEAP_H
