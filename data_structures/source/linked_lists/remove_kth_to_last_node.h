//
// Created by andreas on 10.08.24.
//

#ifndef DATA_STRUCTURES_REMOVE_KTH_TO_LAST_NODE_H
#define DATA_STRUCTURES_REMOVE_KTH_TO_LAST_NODE_H

#include "node.h"

// Remove Kth Node From End
// Write a function that removes the k-th node from the end of a singly linked list and returns the possibly updated
// head of the list.

template <typename T>
Node<T>* remove_kth_to_last_node(int k, Node<T>* head)
{
    auto fast = head;
    auto slow = head;
    while (k--)
    {
        fast = fast->next;
    }

    if (!fast)
    {
        auto result = head->next;
        delete head;
        return result;
    }

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    auto node_to_remove = slow->next;
    slow->next = slow->next->next;
    delete node_to_remove;
    return head;
}

// Write a function that removes the k-th node from the end of a singly linked list.
// The function receives the head of the linked list and an integer k.
// The removal must be done in place. The function does not return a new head pointer.
template <typename T>
void remove_kth_to_last_node(Node<T>* head, int k)
{
    auto first = head;
    auto second = head;

    // move k steps with first
    while (k > 0)
    {
        first = first->next;
        k--;
    }
    // If first is nullptr, then k was the length of the list.
    // So the head has to be "removed" by mutating it.
    if (first == nullptr)
    {
        // we have to keep the original head node because if not the access gets lost --> memory leak
        auto node_to_remove = head->next;
        // update head-variables
        head->value = head->next->value;
        head->next = head->next->next;
        delete node_to_remove;
        return;
    }

    while (first->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }
    // we always need access to the node before the 'to-be-deleted-node'.
    auto node_to_remove = second->next;
    second->next = second->next->next;
    delete node_to_remove;
}


#endif // DATA_STRUCTURES_REMOVE_KTH_TO_LAST_NODE_H
