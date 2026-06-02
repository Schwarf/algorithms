//
// Created by andreas on 10.08.24.
//

#ifndef DATA_STRUCTURES_REMOVE_KTH_TO_LAST_NODE_H
#define DATA_STRUCTURES_REMOVE_KTH_TO_LAST_NODE_H

#include "node.h"

// Remove Kth Node From End
// Write a function that removes the k-th node from the end of a singly linked list and returns the possibly updated head of the list.

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
