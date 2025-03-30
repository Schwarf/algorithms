//
// Created by andreas on 10.08.24.
//

#ifndef DATA_STRUCTURES_REMOVE_KTH_TO_LAST_NODE_H
#define DATA_STRUCTURES_REMOVE_KTH_TO_LAST_NODE_H

#include "node.h"

// We have a number where each digit [0-9] is provided by a node in a linked list. The least significant digit
// is provided by head and the most significant digit is provided the last node. Given two numbers compute the
// sum of those two numbers.
template <typename T>
Node<T>* remove_kth_to_last_node(Node<T>* head, int k)
{
    auto fast = head;
    auto slow = head;
    while (k--)
    {
        fast = fast->next;
    }

    if (!fast)
        return head->next;

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
}

#endif //DATA_STRUCTURES_REMOVE_KTH_TO_LAST_NODE_H
