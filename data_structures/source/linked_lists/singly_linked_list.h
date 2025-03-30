//
// Created by andreas on 23.01.22.
//

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "i_linked_list.h"

template <typename T>
class SinglyLinkedList : ILinkedList<T>
{
    struct Node
    {
        T value;
        Node* next;
    };

    bool is_index_valid_(size_t index)
    {
        return index < length_;
    }

public:
    SinglyLinkedList()
    {
        head_ = nullptr;
    }

    ~SinglyLinkedList()
    {
        std::cout << "Call to destructor singly linked list " << std::endl;
        if (head_ == nullptr)
            return;
        auto next = head_->next;
        while (next != nullptr)
        {
            delete head_;
            head_ = next;
            next = next->next;
        }
    }

    size_t size() const final
    {
        return length_;
    }

    bool is_empty() const final
    {
        return head_ == nullptr;
    }

    T pop_front() final
    {
        if (is_empty())
            throw std::out_of_range("Singly linked list is empty (pop_front).");

        auto value = head_->value;
        auto help = head_->next;
        delete head_;
        head_ = help;
        length_--;
        return value;
    }

    T pop_back() final
    {
        if (is_empty())
            throw std::out_of_range("Singly linked list is empty (pop_back).");
        if (head_->next == nullptr)
        {
            T value = head_->value;
            head_ = nullptr;
            length_--;
            return value;
        }
        auto current = head_;

        while (current->next->next != nullptr)
            current = current->next;
        T value = current->next->value;
        delete current->next;
        current->next = nullptr;
        length_--;
        return value;
    }

    T pop_at(size_t index) final
    {
        if (is_empty())
            throw std::out_of_range("Singly linked list is empty (pop_at).");
        if (!is_index_valid_(index))
            throw std::out_of_range("The index in singly linked list is out of range in method 'pop_at'");
        T value;
        if (index == 0)
        {
            return pop_front();
        }
        if (index == length_ - 1)
        {
            return pop_back();
        }
        size_t counter = 1;
        auto previous = head_;
        auto current = head_->next;
        while (counter < index)
        {
            previous = current;
            current = current->next;
            counter++;
        }
        value = current->value;
        previous->next = current->next;
        length_--;
        delete current;
        return value;
    }

    void push_front(const T& value) final
    {
        auto new_head = new Node();
        new_head->value = value;
        if (head_ == nullptr)
        {
            new_head->next = nullptr;
            head_ = new_head;
            length_ = 1;
            return;
        }
        new_head->next = head_;
        head_ = new_head;
        length_++;
    }

    void push_back(const T& value) final
    {
        auto new_tail = new Node();
        new_tail->value = value;
        new_tail->next = nullptr;
        if (head_ == nullptr)
        {
            head_ = new_tail;
            new_tail->next = nullptr;
            length_ = 1;
            return;
        }
        auto current = head_;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_tail;
        length_++;
    }

    T get(size_t index)
    {
        if (!is_index_valid_(index))
            throw std::out_of_range("The index in singly linked list is out of range in method 'get'");
        auto current = head_;
        size_t count{};
        while (current != nullptr)
        {
            if (index == count)
            {
                return current->value;
            }
            current = current->next;
            count++;
        }
        return T{};
    }

    bool push_at(size_t index, const T& value) final
    {
        if (!is_index_valid_(index))
            return false;
        if (index == length_ - 1)
        {
            push_back(value);
            return true;
        }
        if (index == 0)
        {
            push_front(value);
            return true;
        }

        auto new_node = new Node();
        new_node->value = value;
        auto current = head_;
        Node* previous = nullptr;
        size_t count = 0;
        while (current != nullptr)
        {
            if (count == index)
            {
                previous->next = new_node;
                new_node->next = current;
                length_++;
                return true;
            }
            previous = current;
            current = current->next;
            count++;
        }
        return false;
    }

private:
    Node* head_;
    size_t length_{};
};

#endif //SINGLY_LINKED_LIST_H
