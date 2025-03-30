//
// Created by andreas on 22.01.22.
//

#ifndef AVL_NODE_H
#define AVL_NODE_H

template <typename T>
struct AVLNode
{
public:
    explicit AVLNode(const T& val)
    {
        value = val;
    }

    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    int height{1};
    T value{};
};

#endif //AVL_NODE_H
