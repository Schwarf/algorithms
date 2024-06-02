//
// Created by andreas on 22.05.23.
//

#ifndef KTH_LARGEST_ELEMENT_IN_STREAM_H
#define KTH_LARGEST_ELEMENT_IN_STREAM_H

#include <vector>
#include <functional>
#include <queue>

template<typename T>
class KthLargestElementInStream {
public:
    KthLargestElementInStream(int k, const std::vector<T> &initial_input)
            : k_(k) {
        for (const auto &element: initial_input)
            queue_.push(element);
        while (queue_.size() > k_)
            queue_.pop();

    }

    T add_and_return_kth_element(T value) {
        queue_.push(value);
        if (queue_.size() > k_)
            queue_.pop();
        return queue_.top();
    }

private:
    std::priority_queue<T, std::vector<T>, std::greater<>> queue_;
    size_t k_;
};

#endif //KTH_LARGEST_ELEMENT_IN_STREAM_H
