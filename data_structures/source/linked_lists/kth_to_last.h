//
// Created by andreas on 17.03.23.
//

#ifndef KTH_TO_LAST_H
#define KTH_TO_LAST_H
// find kth to last element of a linked list

#include "node.h"

template<typename T>
Node<T> *kth_to_last_element(Node<T> *head, int k) {
    if (!head || k == 0)
        return head;
    int steps{k};
    auto front = head;
    while (front && steps) {
        front = front->next;
        steps--;
    }
    if (!front)
        return head;
    auto tail = head;
    while (front) {
        front = front->next;
        tail = tail->next;
    }
    return tail;
}

#endif //KTH_TO_LAST_H
