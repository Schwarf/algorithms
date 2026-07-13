//
// Created by andreas on 30.05.26.
//

#ifndef ALGORITHMS_MAX_HEAP_H
#define ALGORITHMS_MAX_HEAP_H

#include <concepts>
#include <stdexcept>
#include <vector>

template <std::totally_ordered T>
class MaxHeap
{
    std::vector<T> heap;
    void heapify_down(int parent, int end, std::vector<T>& heap)
    {
        while (true)
        {
            auto left_left = 2 * parent + 1;
            auto right_child = 2 * parent + 2;
            auto current = parent;
            if (left_left <= end && heap[left_left] > heap[current])
            {
                current = left_left;
            }
            if (right_child <= end && heap[right_child] > heap[current])
            {
                current = right_child;
            }

            if (current != parent)
            {
                std::swap(heap[parent], heap[current]);
                parent = current;
            }
            else
                break;
        }
    }

    void heapify_up(int child, std::vector<T>& heap)
    {
        while (child > 0)
        {
            auto parent = (child - 1) >> 1;
            if (heap[parent] >= heap[child])
                return;
            std::swap(heap[child], heap[parent]);
            child = parent;
        }
    }

public:
    explicit MaxHeap(const std::vector<T>& values) { build_max_heap(values); }

    bool empty() const { return heap.empty(); }

    std::vector<T> build_max_heap(const std::vector<T>& values)
    {
        heap = values;
        if (heap.size() < 2)
            return heap;

        int last_parent_index = (static_cast<int>(heap.size()) - 2) >> 1;

        for (int current = last_parent_index; current >= 0; --current)
        {
            heapify_down(current, static_cast<int>(heap.size()) - 1, heap);
        }
        return heap;
    }

    T peek() const
    {
        if (heap.empty())
        {
            throw std::runtime_error("Cannot peek from an empty heap.");
        }
        return heap[0];
    }

    T remove()
    {
        if (heap.empty())
        {
            throw std::runtime_error("Cannot remove from an empty heap.");
        }

        T value_to_remove = heap[0];
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify_down(0, static_cast<int>(heap.size()) - 1, heap);
        return value_to_remove;
    }

    void insert(T value)
    {
        heap.push_back(value);
        heapify_up(static_cast<int>(heap.size() - 1), heap);
    }
};

#endif // ALGORITHMS_MAX_HEAP_H
