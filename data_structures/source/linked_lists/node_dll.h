//
// Created by andreas on 15.03.23.
//

#ifndef NODE_DLL_H
#define NODE_DLL_H

// Node for double linked list
template <typename T>
struct NodeDLL
{
    explicit NodeDLL(T val)
        :
        value(val)
    {
    }

    T value;
    NodeDLL<T>* next{nullptr};
    NodeDLL<T>* previous{nullptr};
};

#endif //NODE_DLL_H
