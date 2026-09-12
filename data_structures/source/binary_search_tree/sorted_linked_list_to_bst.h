//
// Created by andreas on 12.09.26.
//

#ifndef ALGORITHMS_SORTED_LINKED_LIST_TO_BST_H
#define ALGORITHMS_SORTED_LINKED_LIST_TO_BST_H
#include "./../trees/binary_trees/tree_node.h"
// Given the head of a singly linked list where elements are sorted in ascending order,
// convert it to a height-balanced binary search tree.

template <typename T>
struct ListNode {
    T val;
    ListNode* next;
};

template <typename T>
TreeNode<T>* build_tree(ListNode<T>* head)
{
    if (!head)
        return nullptr;

    auto slow = head;
    auto fast = head;
    ListNode<T>* prev = nullptr;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev)
        prev->next = nullptr;
    auto right_head = slow->next;
    auto root = new TreeNode<T>(slow->val);
    if (slow != head)
        root->left = build_tree(head);
    root->right = build_tree(right_head);
    return root;
}



#endif // ALGORITHMS_SORTED_LINKED_LIST_TO_BST_H
