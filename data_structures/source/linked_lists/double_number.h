//
// Created by andreas on 07.05.24.
//

#ifndef SOURCE_ADD_TWO_NUMBERS_NORMAL_FROM_H
#define SOURCE_ADD_TWO_NUMBERS_NORMAL_FROM_H
#include "node.h"
#include <concepts>
#include <stack>

template <typename T>
    requires std::is_signed_v<T>
Node<T>* double_number_stack(Node<T>* head)
{
    std::stack<int> s;
    auto node = head;
    while (node)
    {
        s.push(node->value);
        node = node->next;
    }
    int val{};
    Node<T>* new_head = nullptr;
    node = nullptr;
    while (!s.empty() || val)
    {
        if (!s.empty())
        {
            val += s.top() * 2;
            s.pop();
        }
        new_head = new Node<T>(val % 10);
        if (node)
            new_head->next = node;
        node = new_head;
        val /= 10;
    }

    return new_head;
}

template <typename T>
    requires std::is_signed_v<T>
Node<T>* double_number(Node<T>* head)
{
    if (head->value > 4)
    {
        auto new_head = new Node<T>(0);
        new_head->next = head;
        head = new_head;
    }
    for (auto node = head; node != nullptr; node = node->next)
    {
        node->value = (node->value * 2) % 10;
        if (node->next != nullptr && node->next->value > 4)
        {
            node->value++;
        }
    }
    return head;
}

#endif //SOURCE_ADD_TWO_NUMBERS_NORMAL_FROM_H
