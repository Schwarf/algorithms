//
// Created by andreas on 31.03.26.
//

#ifndef ALGORITHMS_DOUBLE_ENDED_QUEUE_H
#define ALGORITHMS_DOUBLE_ENDED_QUEUE_H
// Design a Double-ended Queue class.
//
// Your Deque class should support the following operations:
//
//     Deque() will initialize an empty queue.
//     bool isEmpty() will return whether the queue is empty or not.
//     void append(int value) will insert value at the end of the queue.
//     void appendleft(int val) will insert value at the beginning of the queue.
//     int pop() will remove and return the value at the end of the queue. If the queue is empty, return -1.
//     int popleft() will remove and return the value at the beginning of the queue. If the queue is empty, return -1.
//
// Note: You should implement each operation in O(1)O(1) time complexity.
#include <optional>

template <typename T>
class Deque {
  struct Node{
    Node(T val): value(val){}
    T value;
    Node * next = nullptr;
    Node * prev = nullptr;
  };
  Node * head = nullptr;
  Node * tail = nullptr;
public:
  Deque() {

  }
  ~Deque() {
    while (!isEmpty()) {
      popleft();
    }
  }

  Deque(const Deque&) = delete;
  Deque& operator=(const Deque&) = delete;

  bool isEmpty() const {
    return head == nullptr;
  }

  void append(T value) {
    if(!head)
    {
      head = new Node(value);
      tail = head;
      return;
    }
    auto node = new Node(value);
    tail->next = node;
    node->prev = tail;
    tail = node;
  }

  void appendLeft(T value) {
    if(!head)
    {
      head = new Node(value);
      tail = head;
      return;
    }
    auto node = new Node(value);
    node->next = head;
    head->prev = node;
    head = node;
  }

  std::optional<T> pop() {
    if(!head)
      return std::nullopt;
    T value = tail->value;
    if(head == tail)
    {
      delete tail;
      head = nullptr;
      tail = nullptr;
      return value;
    }
    auto newTail = tail->prev;
    newTail->next = nullptr;
    delete tail;
    tail = newTail;
    return value;
  }

  std::optional<T> popleft() {
    if(!head)
      return std::nullopt;
    T value = head->value;
    if(head == tail)
    {
      delete tail;
      head = nullptr;
      tail = nullptr;
      return value;
    }

    auto newHead = head->next;
    newHead->prev = nullptr;
    delete head;
    head = newHead;
    return value;
  }
};

#endif // ALGORITHMS_DOUBLE_ENDED_QUEUE_H
