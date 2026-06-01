//
// Created by andreas on 24.01.22.
//

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "i_linked_list.h"

// Use cases
// LRU cache
// linked hash maps
// deque-like structures
// browser history
// undo/redo lists
// scheduler queues
template <typename T>
class DoublyLinkedList : ILinkedList<T>
{
    struct Node
    {
        T value;
        Node* next = nullptr;
        Node* previous = nullptr;

        explicit Node(const T& val) : value(val)
        {
        }
    };

    Node* head_;
    Node* tail_;
    size_t length_{};

    bool is_index_valid_(size_t index) const
    {
        return index <= length_;
    }

public:
    DoublyLinkedList()
    {
        head_ = nullptr;
        tail_ = nullptr;
    }

    ~DoublyLinkedList()
    {
        std::cout << "Call to destructor doubly linked list " << std::endl;
        if (head_ == nullptr)
            return;
        while (head_ != nullptr)
        {
            Node* next = head_->next;
            delete head_;
            head_ = next;
        }

        tail_ = nullptr;
        length_ = 0;
    }

    bool is_empty() const final
    {
        return head_ == nullptr;
    }

    size_t size() const final
    {
        return length_;
    }

    bool push_at(size_t index, const T& value) final
    {
        if (index == 0)
        {
            push_front(value);
            return true;
        }
        if (!is_index_valid_(index))
            return false;
        if (index == length_)
        {
            push_back(value);
            return true;
        }

        auto new_node = new Node(value);
        auto current = head_->next;
        size_t index_counter = 1;
        while (index_counter < index)
        {
            index_counter++;
            current = current->next;
        }
        new_node->next = current;
        new_node->previous = current->previous;
        current->previous->next = new_node;
        current->previous = new_node;
        length_++;
        return true;
    }

    void push_front(const T& value) final
    {
        auto new_node = new Node(value);
        if (is_empty())
        {
            tail_ = new_node;
            head_ = tail_;
            length_++;
            return;
        }
        auto help = head_;
        help->previous = new_node;
        new_node->previous = nullptr;
        new_node->next = help;
        head_ = new_node;
        length_++;
    }

    void push_back(const T& value) final
    {
        auto new_node = new Node(value);
        new_node->next = nullptr;
        if (is_empty())
        {
            head_ = new_node;
            tail_ = head_;
            length_++;
            return;
        }
        auto help = tail_;
        help->next = new_node;
        new_node->previous = help;
        new_node->next = nullptr;
        tail_ = new_node;
        length_++;
    }

    T pop_back() final
    {
        if (is_empty())
            throw std::out_of_range("Doubly linked list is empty (pop_back).");
        auto old_tail = tail_;
        T value = old_tail->value;
        if (tail_ == head_)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        else
        {
            tail_ = tail_->previous;
            tail_->next = nullptr;
        }
        delete old_tail;
        length_--;
        return value;
    }

    T pop_front() final
    {
        if (is_empty())
            throw std::out_of_range("Doubly linked list is empty (pop_front).");
        auto old_head = head_;
        T value = head_->value;
        if (tail_ == head_)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        else
        {
            head_ = head_->next;
            head_->previous = nullptr;
        }
        delete old_head;
        length_--;
        return value;
    }

    T pop_at(size_t index) final
    {
        if (is_empty())
            throw std::out_of_range("Doubly linked list is empty (pop_at).");
        if (!is_index_valid_(index))
            throw std::out_of_range("The index in doubly linked list is out of range in method 'pop_at'");
        if (index == 0)
            return pop_front();
        if (index == length_ - 1)
            return pop_back();

        size_t index_counter = 1;
        auto current = head_->next;
        auto previous = head_;
        while (index_counter < index)
        {
            index_counter++;
            previous = current;
            current = current->next;
        }
        auto value = current->value;
        previous->next = current->next;
        current->next->previous = previous;
        delete current;
        length_--;
        return value;
    }

    T get(size_t index) const
    {
        if (is_empty())
            throw std::out_of_range("Doubly linked list is empty (get).");
        if (!is_index_valid_(index))
            throw std::out_of_range("The index in doubly linked list is out of range in method 'get'");
        size_t index_counter = 0;
        auto current = head_;
        while (index_counter < index)
        {
            current = current->next;
            index_counter++;
        }
        return current->value;
    }

    T get_from_back(size_t index) const
    {
        if (is_empty())
            throw std::out_of_range("Doubly linked list is empty (get).");
        if (!is_index_valid_(index))
            throw std::out_of_range("The index in doubly linked list is out of range in method 'get'");
        int index_counter = length_ - 1;
        auto current = tail_;
        while (index_counter > index)
        {
            current = current->previous;
            index_counter--;
        }
        return current->value;
    }
};

#endif //DOUBLE_LINKED_LIST_H
