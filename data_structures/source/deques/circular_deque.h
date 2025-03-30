//
// Created by andreas on 29.09.24.
//

#ifndef DATA_STRUCTURES_CIRCULAR_DEQUE_H
#define DATA_STRUCTURES_CIRCULAR_DEQUE_H

#include "linked_lists/node_dll.h"
#include <optional>
// Design your implementation of the circular double-ended queue (deque).
// Implement the circular_deque class:
//
// circular_deque(int k) Initializes the deque with a maximum size of k.
// boolean insert_front() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean insert_last() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
// boolean delete_front() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean delete_last() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
// int get_front() Returns the front item from the Deque via std::optional.
// int get_back() Returns the last item from Deque via std::optional.
// boolean is_empty() Returns true if the deque is empty, or false otherwise.
// boolean is_full() Returns true if the deque is full, or false otherwise.


template <typename T>
class CircularDeque
{
    int capacity{};
    int size{};
    NodeDLL<T>* head{nullptr};
    NodeDLL<T>* tail{nullptr};

public:
    explicit CircularDeque(int k) : capacity{k}
    {
    }

    bool insert_front(T value)
    {
        if (size == capacity)
            return false;
        if (!head)
        {
            head = new NodeDLL<T>(value);
            tail = head;
            size++;
            return true;
        }

        auto old_head = head;
        head = new NodeDLL<T>(value);
        head->next = old_head;
        old_head->previous = head;
        size++;
        return true;
    }

    bool insert_back(T value)
    {
        if (size == capacity)
            return false;
        if (!tail)
        {
            tail = new NodeDLL<T>(value);
            head = tail;
            size++;
            return true;
        }

        auto old_tail = tail;
        tail = new NodeDLL<T>(value);
        tail->previous = old_tail;
        old_tail->next = tail;
        size++;
        return true;
    }

    bool delete_front()
    {
        if (!head)
            return false;

        if (!head->next)
        {
            delete head;
            size--;
            head = nullptr;
            tail = nullptr;
            return true;
        }

        auto old_head = head;
        head = old_head->next;
        head->previous = nullptr;
        delete old_head;
        size--;
        return true;
    }

    bool delete_back()
    {
        if (!tail)
            return false;

        if (!tail->previous)
        {
            delete tail;
            size--;
            head = nullptr;
            tail = nullptr;
            return true;
        }

        auto old_tail = tail;
        tail = old_tail->previous;
        tail->next = nullptr;
        delete old_tail;
        size--;
        return true;
    }

    std::optional<T> get_front()
    {
        if (!head)
            return {};
        return head->value;
    }

    std::optional<T> get_back()
    {
        if (!tail)
            return {};
        return tail->value;
    }

    bool is_empty()
    {
        return size == 0;
    }

    bool is_full()
    {
        return size == capacity;
    }
};


template <typename T>
class CircularDequeArray
{
    std::vector<T> queue;
    int capacity{};
    int size{};
    int front_index{};
    int back_index{};

public:
    explicit CircularDequeArray(int k) : capacity{k}
    {
        queue = std::vector<T>(capacity);
        back_index = capacity - 1;
    }

    bool insert_front(T value)
    {
        if (is_full())
            return false;
        front_index = (front_index - 1 + capacity) % capacity;
        queue[front_index] = value;
        size++;
        return true;
    }

    bool insert_back(T value)
    {
        if (is_full())
            return false;
        back_index = (back_index + 1) % capacity;
        queue[back_index] = value;
        size++;
        return true;
    }

    bool delete_front()
    {
        if (is_empty())
            return false;
        front_index = (front_index + 1) % capacity;
        size--;
        return true;
    }

    bool delete_back()
    {
        if (is_empty())
            return false;
        back_index = (back_index - 1 + capacity) % capacity;
        size--;
        return true;
    }

    std::optional<T> get_front()
    {
        if (is_empty())
            return {};
        return queue[front_index];
    }

    std::optional<T> get_back()
    {
        if (is_empty())
            return {};
        return queue[back_index];
    }

    bool is_empty()
    {
        return size == 0;
    }

    bool is_full()
    {
        return size == capacity;
    }
};

#endif //DATA_STRUCTURES_CIRCULAR_DEQUE_H
