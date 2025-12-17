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
    BinarySearchTree<T>* left = nullptr;
    BinarySearchTree<T>* right = nullptr;

    T getMibValue()
    {
        const BinarySearchTree<T>* current = this;
        while (current->left)
            current = current->left;
        return current->value;
    }

    BinarySearchTree<T>* remove(T val, BinarySearchTree<T>* parent)
    {
        auto current = this;
        while (current && current->value != val)
        {
            parent = current;
            if (val < current->value)
                current = current->left;
            else
                current = current->right;
        }

        if (!current)
            return *this;

        if (current->left && current->right) // case with two children
        {
            current->value = current->right->getMibValue();
            current->right->remove(val, current);
        }
        BinarySearchTree<T>* child = current->left? current->left : current->right;

        if (!parent) // root node with only one child removal
        {
            if(child)
            {
                current->value = child->value;
                current->right = child->right;
                current->left = child->left;
                child->left = nullptr;
                child->right = nullptr;
                delete child;
            }
        }
        else
        {
            if (parent->left == current)
                parent->left = child;
            else
                parent->right = child;
            current->left = nullptr;
            current->right = nullptr;
            delete current;
        }
        return *this;
    }

public:
    BinarySearchTree(T val) : value(val)
    {
    }

    ~BinarySearchTree() {
        delete left;
        delete right;
        left = nullptr;
        right = nullptr;
    }


    BinarySearchTree& insert(T val)
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
        return *this;
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

    BinarySearchTree& remove(T val)
    {
        return remove(val, nullptr);
    }
};
#endif //ALGORITHMS_BINARY_SEARCH_TREE_H
