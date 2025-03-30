//
// Created by andreas on 15.05.23.
//

#ifndef SWAPPING_NODES_H
#define SWAPPING_NODES_H
#include <algorithm>
#include "node.h"

// Given the head of a linked list, and an integer k.
// Return the head of the linked list after swapping the values of the kth node from the beginning and
// the kth node from the end (the list is 1-indexed).
// k <= size of the list
template <typename T>
Node<T>* swapping_nodes(Node<T>* head, int k)
{
    if (!head)
        return head;
    auto right = head;
    for (int i{0}; i < k - 1; ++i)
        right = right->next;
    auto first = right;
    auto left = head;
    while (right->next)
    {
        left = left->next;
        right = right->next;
    }
    std::swap(left->value, first->value);
    return head;
}
#endif //SWAPPING_NODES_H
