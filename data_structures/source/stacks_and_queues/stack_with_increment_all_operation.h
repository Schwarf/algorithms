//
// Created by andreas on 30.09.24.
//

#ifndef DATA_STRUCTURES_STACK_WITH_INCREMENT_ALL_OPERATION_H
#define DATA_STRUCTURES_STACK_WITH_INCREMENT_ALL_OPERATION_H

#include <vector>
#include <optional>
// Design a stack that supports increment operations on its elements.
//
// Implement the IncrementStack class:
//
// IncrementStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
// void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
// std::optional<T> pop() Pops and returns the top of the stack.
// void increment(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.

template<typename T>
class IncrementStack {
private:
    int capacity{};
    int size{};
    std::vector<T> stack;
    int stack_index{};
public:
    explicit IncrementStack(int max_size) : capacity(max_size) {
        stack = std::vector<T>(capacity);
    }

    void push(T value) {
        if (size == capacity)
            return;

        stack_index = (stack_index - 1 + capacity) % capacity;
        stack[stack_index] = value;
        size++;
    }

    std::optional<T> pop() {
        if (size == 0)
            return {};
        std::optional<T> value{stack[stack_index]};
        stack_index = (stack_index + 1) % capacity;
        return value;
    }

    void increment(T value, int k) {
        auto index = capacity - 1;
        auto s = size;
        while (s && k) {
            stack[index] += value;
            index--;
            s--;
            k--;
        }

    }

};


#endif //DATA_STRUCTURES_STACK_WITH_INCREMENT_ALL_OPERATION_H
