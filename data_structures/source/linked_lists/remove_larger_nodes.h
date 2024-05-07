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
Node<T> * remove_larger_nodes(Node<T>* head)
{
    std::stack<Node<T>*> stack;
    Node<T>* current = head;

    // Add nodes to the stack
    while (current != nullptr) {
        stack.push(current);
        current = current->next;
    }

    current = stack.top();
    stack.pop();
    T maximum = current->value;
    auto result_list = new Node<T>(maximum);

    // Remove nodes from the stack and add to result
    while (!stack.empty()) {
        current = stack.top();
        stack.pop();
        // Add new node with current's value to front of the result if node value greater-equal current value
        if (current->value >= maximum){
            auto newNode = new Node<T>(current->value);
            newNode->next = result_list;
            result_list = newNode;
            maximum = current->value;
        }
    }

    return result_list;
}


#endif //DATA_STRUCTURES_REMOVE_LARGER_NODES_H
