//
// Created by andreas on 06.04.26.
//

#ifndef ALGORITHMS_MAX_STACK_H
#define ALGORITHMS_MAX_STACK_H
#include <set>

class MaxStack {
    std::set<std::pair<int, int>> stack;
    std::set<std::pair<int, int>> ordered_values;
    int count{};
public:
    MaxStack() = default;

    void push(int value) {
        stack.insert({count, value});
        ordered_values.insert({value, count});
        count++;
    }

    int pop() {
        if (stack.empty()) {
            throw std::out_of_range("pop() on empty MaxStack");
        }
        auto pair = *stack.rbegin();
        stack.erase(pair);
        ordered_values.erase({pair.second, pair.first});
        return pair.second;
    }

    int top() {
        if (stack.empty()) {
            throw std::out_of_range("top() on empty MaxStack");
        }
        return stack.rbegin()->second;
    }

    int peekMax() {
        if (stack.empty()) {
            throw std::out_of_range("peekMax() on empty MaxStack");
        }
        return ordered_values.rbegin()->first;
    }

    int popMax() {
        if (stack.empty()) {
            throw std::out_of_range("popMax() on empty MaxStack");
        }
        auto pair = *ordered_values.rbegin();
        ordered_values.erase(pair);
        stack.erase({pair.second, pair.first});
        return pair.first;
    }
};
#endif //ALGORITHMS_MAX_STACK_H
