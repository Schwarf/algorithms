//
// Created by andreas on 07.02.22.
//

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "i_heap.h"
#include <iostream>


template<typename T, size_t heap_capacity, class Comparator = std::less<T>>
class StackHeap {
public:
    StackHeap() = default;

    static constexpr size_t index_for_extremum{};

    bool insert(const T &value) {
        if (heap_size_ == heap_capacity)
            return false;
        elements_[heap_size_++] = value; // add value at the end and increase size
        promote_(); // promote_ the value to the correct position in heap
        return true;
    }

    T pop() {
        auto value = elements_[index_for_extremum];
        std::swap(elements_[index_for_extremum], elements_[--heap_size_]);
        demote_();
        return value;
    }

    T top() const {
        return elements_[index_for_extremum];
    }

    bool is_empty() const {
        return heap_size_ == 0;
    }

    size_t size() const {
        return heap_size_;
    }

private:
    std::array<T, heap_capacity> elements_;
    size_t heap_size_{};
    Comparator comparator_;

    int parent(int index) const {
        return (index - 1) >> 1;
    }

    int left_child(int index) const {
        return (index << 1) + 1;
    }

    int right_child(int index) const {
        return (index << 1) + 2;
    }

    void promote_() {
        for (int child_index = heap_size_ - 1; child_index > 0;) {
            int parent_index = parent(child_index);
            if (comparator_(elements_[child_index], elements_[parent_index]))
                return;
            std::swap(elements_[child_index], elements_[parent_index]);
            child_index = parent_index;
        }
    }

    void demote_() {
        int index{};

        while (true) {
            auto left = left_child(index);
            auto right = right_child(index);;
            auto childIndexToCompare = index;
            // Check if value at childIndexToCompare is less/greater (max/min case) than value at left
            if (left < heap_size_ && comparator_(elements_[childIndexToCompare], elements_[left])) {
                childIndexToCompare = left;
            }
            // Check if value at childIndexToCompare is less/greater (max/min case) than value at right
            if (right < heap_size_ && comparator_(elements_[childIndexToCompare], elements_[right])) {
                childIndexToCompare = right;
            }
            // If childIndexToCompare
            if (childIndexToCompare != index) {
                std::swap(elements_[index], elements_[childIndexToCompare]);
                // Move down the tree
                index = childIndexToCompare;
            } else {
                // If we didn't swap, the heap property is restored
                break;
            }
        }
    }
};


#endif //BINARY_HEAP_H
