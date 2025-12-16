//
// Created by andreas on 16.12.25.
//

#ifndef ALGORITHMS_BINARY_SEARCH_TREE_H
#define ALGORITHMS_BINARY_SEARCH_TREE_H
#include <concepts>

template <typename T>
requires std::totally_ordered<T>
class BinarySearchTree
{
    T value{};
    BinarySearchTree<T> *left= nullptr;
    BinarySearchTree<T> *right = nullptr;
    public:
    BinarySearchTree(T val) : value(val) {}

    BinarySearchTree & insert(T val)
    {
        if (val < value)
        {
            if (left)
                left->insert(val);
            else
                left = new BinarySearchTree(val);
        }
        else
        {
            if (right)
                right->insert(val);
            else
                right = new BinarySearchTree(val);
        }
    }
    bool contains(T val)
    {
        if (val == value)
            return true;
        if (val < value)
        {
            if (left)
                left->contains(val);
        }
        else
        {
            if (right)
                right->contains(val);
        }
        return false;
    }

};
#endif //ALGORITHMS_BINARY_SEARCH_TREE_H