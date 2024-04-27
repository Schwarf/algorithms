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

    ~FibonacciHeap() {
        if (!is_empty())
            _delete_root_list(_minimum_node);
    }

    bool is_empty() const {
        return _minimum_node == nullptr;
    }

private:

    void _delete_root_list(Node<KeyType, ValueType> *node) {
        auto next_left = node->left;
        do {
            auto current_node = next_left;
            next_left = next_left->left;
            if (current_node->child)
                _delete_root_list(current_node->child);
            if (current_node != node)
                delete current_node;

        } while (next_left != node);
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
        // Remember original right and left nodes
        auto node1_right = node1->right;
        auto node2_left = node2->left;
        node1->right = node2;
        node2->left = node1;

        node1_right->left = node2_left;
        node2_left->right = node1_right;
        return node1;
    }

    void _remove_node_from_list(Node<KeyType, ValueType> *node) {
        // NOde is already removed from list;
        if (node->right == node)
            return;

        auto left = node->left;
        auto right = node->right;
        // Attach left and right nodes to each other
        left->right = right;
        right->left = left;
        // Self assign node left and right pointers
        node->left = node;
        node->right = node;
    }

    void _promote_child_to_root(Node<KeyType, ValueType> *child, Node<KeyType, ValueType> *parent) {
        parent->child = (child = child->right ? nullptr : child->right);
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

    int _number_of_nodes{};
    Node<KeyType, ValueType> *_minimum_node = nullptr; // Important note: _minimum_node is the most right node.

};

#endif //DATA_STRUCTURES_FIBONACCI_HEAP_H
