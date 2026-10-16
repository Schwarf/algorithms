//
// Created by andreas on 16.10.26.
//

#ifndef ALGORITHMS_WEAK_AVL_TREE_H
#define ALGORITHMS_WEAK_AVL_TREE_H
#include "../../../../../../../../usr/include/c++/11/bits/valarray_after.h"

template <typename T>
class weakAVL
{
public:
    weakAVL() = default;
    ~weakAVL() { destroy(root); }

    weakAVL(const weakAVL&) = delete;
    weakAVL(weakAVL&&) = delete;
    weakAVL operator=(const weakAVL&) = delete;
    weakAVL operator=(weakAVL&&) = delete;

    bool contains(const T& key) const
    {
        auto node = root;
        while (node)
        {
            if (key < node->key)
                node = node->left;
            else if (node->key < key)
                node = node->right;
            else
                return true;
        }
        return false;
    }

    bool insert(const T& key)
    {
        auto node = root;
        Node* parent = nullptr;
        while (node)
        {
            parent = node;
            if (key < node->key)
                node = node->left;
            else if (node->key < key)
                node = node->right;
            else
                return false;
        }
        Node* inserted = new Node(key);
        inserted->parent = inserted;

        if (!parent)
            root = inserted;
        else if (key < parent->key)
            parent->left = inserted;
        else
            parent->right = inserted;
        return true;
    }

    static bool validate_bst(const Node* node, const T* upper, const T* lower, const Node* expected_parent)
    {
        if (!node)
            return true;

        if (node->parent != expected_parent)
            return false;

        if (lower &&  node->key < lower)
            return false;

        if (upper && upper < node->key)
            return false;
        return validate_bst(node->left, node->key, lower, node) &&
            validate_bst(node->right, upper, node->key, node);
    }

    static bool validate_wavl(const Node * node)
    {
        if (!node)
            return true;

        int left_diff = rank_difference(node, node->left);
        int right_diff = rank_difference(node, node->right);
        if (left_diff != 1 && left_diff != 2)
            return false;
        if (right_diff != 1 && right_diff != 2)
            return false;
        return validate_wavl(node->left) && validate_wavl(node->right);
    }

private:
    struct Node
    {
        explicit Node(const T& value) : key(value) {}
        int rank{};
        T key;
        Node* parent{};
        Node* left{};
        Node* right{};
    };
    Node* root;

    static void destroy(Node* node) noexcept
    {
        if (!node)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    static int rank(const Node* node) noexcept { return node ? node->rank : -1; }

    static int rank_difference(const Node* parent, const Node* node) { return rank(parent) - rank(node); }
};

#endif // ALGORITHMS_WEAK_AVL_TREE_H
