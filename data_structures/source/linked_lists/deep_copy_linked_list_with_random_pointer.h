//
// Created by andreas on 11.09.23.
//

#ifndef DEEP_COPY_LINKED_LIST_WITH_RANDOM_POINTER_H
#define DEEP_COPY_LINKED_LIST_WITH_RANDOM_POINTER_H
#include "node.h"
#include <unordered_map>
// A linked list of length n is given such that each node contains an additional random pointer,
// which could point to any node in the list, or null.
// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes,
// where each new node has its value set to the value of its corresponding original node.
// Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the
// pointers in the original list and copied list represent the same list state.
// None of the pointers in the new list should point to nodes in the original list.
// For example, if there are two nodes X and Y in the original list, where X.random --> Y,
// then for the corresponding two nodes x and y in the copied list, x.random --> y.
// Return the head of the copied linked list.
// The linked list is represented in the input/output as a list of n nodes.
// Each node is represented as a pair of [val, random_index] where:
//  - val: an integer representing Node.val
//	- random_index: the index of the node (range from 0 to n-1) that the random pointer points to,
//    or null if it does not point to any node.

template <typename T>
NodePlusRP<T>* deep_copy_linked_list_with_random_pointer(NodePlusRP<T>* head)
{
    if (!head)
        return nullptr;
    std::unordered_map<NodePlusRP<T>*, NodePlusRP<T>*> old_to_new;
    auto current = head;
    while (current)
    {
        old_to_new[current] = new NodePlusRP<T>(current->value);
        current = current->next;
    }
    current = head;
    while (current)
    {
        // Establish 'next' connection
        old_to_new[current]->next = old_to_new[current->next];
        // Establish 'random' connection
        old_to_new[current]->random = old_to_new[current->random];
        current = current->next;
    }
    return old_to_new[head];
}

#endif //DEEP_COPY_LINKED_LIST_WITH_RANDOM_POINTER_H
