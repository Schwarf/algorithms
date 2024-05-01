//
// Created by andreas on 23.04.24.
//

#ifndef DATA_STRUCTURES_FIBONACCI_HEAP_H
#define DATA_STRUCTURES_FIBONACCI_HEAP_H

#include <concepts>
#include <compare>
#include <numbers>
#include <cmath>

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
        _insert(node);
        return node;
    }

    int size() {
        return _number_of_nodes;
    }

    ~FibonacciHeap() {
        if (!is_empty())
            _delete_root_list(_minimum_node);
    }


    ValueType pop_min() {
        auto min_node = _extract_min();
        auto value = min_node->value;
        delete min_node;
        return value;
    }

    void decrease_key(Node<KeyType, ValueType> *node, KeyType new_key) {
        _decrease_key(node, new_key);
    }


    [[nodiscard]] bool is_empty() const {
        return _minimum_node == nullptr;
    }

    [[nodiscard]] bool check_heap_property() {
        if (!_minimum_node)
            return true;
        auto current = _minimum_node;
        do {
            if (!_check_node(_minimum_node, std::numeric_limits<KeyType>::min()))
                return false;
        } while (current != _minimum_node);
        return true;
    }

    ValueType get_min() const {
        if (is_empty())
            throw std::underflow_error("Fibonacci Heap is empty. No min-element can be retrieved!");
        return _minimum_node->value;
    }

    void merge(FibonacciHeap<KeyType, ValueType> &other) {
        _minimum_node = _merge_into_list(_minimum_node, other._minimum_node);
        _number_of_nodes += other._number_of_nodes;
        other._minimum_node = nullptr;
        other._number_of_nodes = 0;
    }

private:

    bool _check_node(Node<KeyType, ValueType> *node, KeyType minimum_key) {
        if (!node)
            return true;
        if (node->key < minimum_key)
            return false;
        // Check the children
        if (node->child) {
            auto child = node->child;
            do {
                if (!_check_node(child, node->key)) {
                    return false;
                }
                child = child->next;
            } while (child != node->child);
        }
        return true;
    }

    Node<KeyType, ValueType> *_extract_min() {
        if (!_minimum_node)
            return nullptr;
        auto return_node = _minimum_node;
        _remove_parent_from_all_children(return_node->child);
        _merge_into_list(return_node, return_node->child);
        if (return_node == return_node->next)
            _minimum_node = nullptr;
        else
            _minimum_node = _minimum_node->next;
        _remove_node_from_list(return_node);
        if (_minimum_node)
            _restore_heap();
        _number_of_nodes--;
        return return_node;
    }

    void _remove_parent_from_all_children(Node<KeyType, ValueType> *initial_child) {
        if (!initial_child)
            return;
        auto start = initial_child;
        do {
            initial_child->parent = nullptr;
            initial_child = initial_child->next;
        } while (initial_child != start);
    }

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

    Node<KeyType, ValueType> *_merge_into_list(Node<KeyType, ValueType> *node1, Node<KeyType, ValueType> *node2) {
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

    void _add_child(Node<KeyType, ValueType> *child, Node<KeyType, ValueType> *parent) {
        child->parent = parent;
        parent->child = _merge_into_list(parent->child, child);
        parent->number_of_children++;
        child->is_marked = false;
    }

    void _restore_heap() {
        int max_degree = static_cast<int>(log2(_number_of_nodes) / log2_of_golden_ratio);
        std::vector<Node<KeyType, ValueType> *> track_nodes_by_degree(max_degree + 1, nullptr);
        std::vector<Node<KeyType, ValueType> *> root_nodes{};
        auto node = _minimum_node;
        do {
            root_nodes.emplace_back(node);
            node = node->next;
        } while (node != _minimum_node);

        for (auto &root: root_nodes) {
            auto degree = root->number_of_children;
            _remove_node_from_list(root);
            while (track_nodes_by_degree[degree]) {
                auto tmp = track_nodes_by_degree[degree];
                if (root->key > tmp->key)
                    std::swap(root, tmp);
                _add_child(tmp, root);
                track_nodes_by_degree[degree] = nullptr;
                degree++;

            }
            track_nodes_by_degree[degree] = root;
        }

        _minimum_node = nullptr;
        for (auto &node: track_nodes_by_degree) {
            if (!node)
                continue;
            if (_minimum_node == nullptr) {
                _minimum_node = node;
                node->prev = node->next = node; // Initialize the node's neighbors to itself
            } else {
                _merge_into_list(_minimum_node, node);
                if (node->key < _minimum_node->key) {
                    _minimum_node = node;
                }
            }
        }
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
    const double log2_of_golden_ratio = log2(std::numbers::phi_v<double>);
    Node<KeyType, ValueType> *_minimum_node = nullptr; // Important note: _minimum_node is the most next node.

};

#endif //DATA_STRUCTURES_FIBONACCI_HEAP_H
