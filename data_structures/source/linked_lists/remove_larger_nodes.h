//
// Created by andreas on 07.05.24.
//

#ifndef DATA_STRUCTURES_REMOVE_LARGER_NODES_H
#define DATA_STRUCTURES_REMOVE_LARGER_NODES_H

// You are given the head of a linked list.
// Remove every node which has a node with a greater value anywhere to the right side of it.
// Return the head of the modified linked list.
#include <stack>
#include "node.h"

template <typename T>
    requires std::is_arithmetic_v<T>
Node<T>* remove_larger_nodes(Node<T>* head)
{
    std::stack<Node<T>*> stack;
    Node<T>* current = head;

    // Add nodes to the stack
    while (current != nullptr)
    {
        stack.push(current);
        current = current->next;
    }

    current = stack.top();
    stack.pop();
    T maximum = current->value;
    auto result_list = new Node<T>(maximum);

    // Remove nodes from the stack and add to result
    while (!stack.empty())
    {
        current = stack.top();
        stack.pop();
        // Add new node with current's value to front of the result if node value greater-equal current value
        if (current->value >= maximum)
        {
            auto newNode = new Node<T>(current->value);
            newNode->next = result_list;
            result_list = newNode;
            maximum = current->value;
        }
    }

    return result_list;
}

template <typename T>
    requires std::is_arithmetic_v<T>
Node<T>* revert_list(Node<T>* head)
{
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
    auto node = head;
    while (node)
    {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}

template <typename T>
    requires std::is_arithmetic_v<T>
Node<T>* remove_larger_nodes_double_reverse(Node<T>* head)
{
    head = revert_list(head);
    int max{};
    auto current = head;
    Node<T>* prev = nullptr;
    while (current != nullptr)
    {
        max = std::max(max, current->value);

        // Delete nodes that are smaller than maximum
        if (current->value < max)
        {
            // Delete current by skipping
            prev->next = current->next;
            auto deleted = current;
            current = current->next;
            deleted->next = nullptr;
        }

        // Current does not need to be deleted
        else
        {
            prev = current;
            current = current->next;
        }
    }

    // Reverse and return the modified linked list
    return revert_list(head);
}

#endif //DATA_STRUCTURES_REMOVE_LARGER_NODES_H
