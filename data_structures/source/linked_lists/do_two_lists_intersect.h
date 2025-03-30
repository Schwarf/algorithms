//
// Created by andreas on 10.08.24.
//

#ifndef DATA_STRUCTURES_DO_TWO_LISTS_INTERSECT_H
#define DATA_STRUCTURES_DO_TWO_LISTS_INTERSECT_H
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.

#include "node.h"

template <typename T>
Node<T>* do_lists_intersect(Node<T>* head1, Node<T>* head2)
{
    auto node1 = head1;
    auto node2 = head2;
    int size1{};
    int size2{};
    while (node1->next)
    {
        size1++;
        node1 = node1->next;
    }
    while (node2->next)
    {
        size2++;
        node2 = node2->next;
    }
    if (node1 != node2)
        return nullptr;

    while (size1 > size2)
    {
        head1 = head1->next;
        size1--;
    }
    while (size2 > size1)
    {
        head2 = head2->next;
        size2--;
    }
    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;
}


#endif //DATA_STRUCTURES_DO_TWO_LISTS_INTERSECT_H
