//
// Created by andreas on 31.03.26.
//

#ifndef ALGORITHMS_DOUBLE_ENDED_QUEUE_H
#define ALGORITHMS_DOUBLE_ENDED_QUEUE_H

class Deque {
  struct Node{
    Node(int val): value(val){}
    int value;
    Node * next = nullptr;
    Node * prev = nullptr;
  };
  Node * head = nullptr;
  Node * tail = nullptr;
public:
  Deque() {

  }

  bool isEmpty() const {
    return head == nullptr;
  }

  void append(int value) {
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

  void appendLeft(int value) {
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

  int pop() {
    if(!head)
      return -1;
    int value = tail->value;
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

  int popleft() {
    if(!head)
      return -1;
    int value = head->value;
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
