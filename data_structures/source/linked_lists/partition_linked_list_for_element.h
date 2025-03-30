//
// Created by andreas on 18.03.23.
//

#ifndef PARTITION_LINKED_LIST_FOR_ELEMENT_H
#define PARTITION_LINKED_LIST_FOR_ELEMENT_H

#include "node.h"

template <typename T>
Node<T>* partition_linked_list_for_element(Node<T>* head, const T& element)
{
    if (!head)
        return head;

    Node<T>* new_head = head;
    Node<T>* new_tail = head;
    while (head)
    {
        auto next = head->next;
        if (head->value < element)
        {
            head->next = new_head;
            new_head = head;
        }
        else
        {
            new_tail->next = head;
            new_tail = head;
        }
        head = next;
    }
    new_tail->next = nullptr;
    return new_head;
}

// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes
// greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.
template <typename T>
Node<T>* partition_linked_list_for_element_and_keep_order(Node<T>* head, const T& element)
{
    if (!head)
        return nullptr;
    auto first_greater_than_element = head;
    Node<T>* prev_first = nullptr;
    while (first_greater_than_element)
    {
        if (first_greater_than_element->value >= element)
            break;
        prev_first = first_greater_than_element;
        first_greater_than_element = first_greater_than_element->next;
    }

    if (!first_greater_than_element)
        return head;
    auto node = first_greater_than_element;
    auto prev_node = prev_first;
    while (node)
    {
        if (node->value < element)
        {
            prev_node->next = node->next;
            if (prev_first)
                prev_first->next = node;
            else
                head = node;

            node->next = first_greater_than_element;
            prev_first = node;
            node = prev_node->next;
        }
        else
        {
            prev_node = node;
            node = node->next;
        }
    }
    return head;
}


#endif //PARTITION_LINKED_LIST_FOR_ELEMENT_H
