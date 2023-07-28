//
// Created by andreas on 06.02.22.
//

#ifndef QUEUE_LINKED_LIST_BASED_H
#define QUEUE_LINKED_LIST_BASED_H

#include "i_queue.h"

template<typename T>
class QueueLLB : IQueue<T> {
private:
    struct Node {
        Node() {
            next = nullptr;
        }

        explicit Node(const T &val) {
            value = val;
            next = nullptr;
        }

        T value{};
        Node *next;

    };

    Node *head_;
    Node *tail_;
    size_t size_{};
public:
    QueueLLB() {
        head_ = nullptr;
        tail_ = nullptr;
    }

    bool is_empty() const final {
        return head_ == nullptr;
    }

    size_t size() const final {
        return size_;
    }

    void enqueue(const T &value) {
        if (is_empty()) {
            head_ = new Node(value);
            tail_ = head_;
            size_++;
            return;
        }
        auto help = tail_;
        tail_ = new Node(value);
        help->next = tail_;
        size_++;
    }

    T dequeue() {
        if (is_empty()) {
            throw std::out_of_range("Can not dequeue. The queue is empty.");
        }
        auto help = head_;
        head_ = head_->next;
        auto value = help->value;
        delete help;
        size_--;
        return value;
    }

    T front() const final {
        if (is_empty()) {
            throw std::out_of_range("Can not return front element. The queue is empty.");
        }
        return head_->value;
    }

    T back() const final {
        if (is_empty()) {
            throw std::out_of_range("Can not return back element. The queue is empty.");
        }
        return tail_->value;
    }

};

#endif //QUEUE_LINKED_LIST_BASED_H
