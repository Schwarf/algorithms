//
// Created by andreas on 28.03.23.
//

#ifndef CHECK_IF_LINKED_LIST_IS_PALINDROME_H
#define CHECK_IF_LINKED_LIST_IS_PALINDROME_H

#include "node.h"
#include <stack>

template<typename T>
Node<T> *revert_and_clone(Node<T> *head) {
    Node<T> *new_head = nullptr;
    while (head) {
        auto node = new Node<T>(head->value);
        node->next = new_head;
        new_head = node;
        head = head->next;
    }
    return new_head;
}


template<typename T>
bool is_palindrome(Node<T> *head) {
    if (!head)
        return true;
    auto new_head = revert_and_clone(head);
    while (head) {
        if (new_head->value != head->value)
            return false;
        head = head->next;
        new_head = new_head->next;
    }
    return true;
}

template<typename T>
bool is_palindrome_with_stack(Node<T> *head) {
    if (!head)
        return true;
    auto slow = head;
    auto fast = head;
    std::stack<T> s;
    while (fast && fast->next) {
        s.push(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast)
        slow = slow->next;
    while (slow) {
        if (slow->value != s.top())
            return false;
        slow = slow->next;
        s.pop();
    }
    return true;
}


#endif //CHECK_IF_LINKED_LIST_IS_PALINDROME_H
