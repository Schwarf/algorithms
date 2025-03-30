//
// Created by andreas on 29.03.23.
//

#ifndef DOES_LINKED_LIST_HAVE_LOOP_H
#define DOES_LINKED_LIST_HAVE_LOOP_H

#include "node.h"

template <typename T>
Node<T>* does_linked_list_have_loop(Node<T>* head)
{
    if (!head)
        return nullptr;
    auto fast = head;
    auto slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (!fast || !fast->next)
        return nullptr;
    fast = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    auto node = fast;
    return node;
}

#endif //DOES_LINKED_LIST_HAVE_LOOP_H
