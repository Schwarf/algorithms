//
// Created by andreas on 07.05.24.
//

#ifndef SOURCE_ADD_TWO_NUMBERS_NORMAL_FROM_H
#define SOURCE_ADD_TWO_NUMBERS_NORMAL_FROM_H
#include "node.h"
#include <concepts>
#include <stack>

template<typename T>
requires std::is_signed<T>
Node<T>* double_number_stack(Node<T>* head)
{
    std::stack<int> s;
    auto node = head;
    while(node)
    {
        s.push(node->val);
        node = node->next;
    }
    int carry{};
    ListNode * new_head = nullptr;
    node = nullptr;
    while(!s.empty())
    {
        int val = (carry+ s.top()*2) % 10;
        carry = (carry+ s.top()*2) / 10;
        s.pop();
        new_head = new ListNode(val);
        if(node)
            new_head->next = node;
        node = new_head;
    }
    if(carry){
        new_head = new ListNode(carry);
        new_head->next = node;
    }
    return new_head;

}

#endif //SOURCE_ADD_TWO_NUMBERS_NORMAL_FROM_H
