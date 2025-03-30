//
// Created by andreas on 25.04.23.
//

#ifndef SMALLEST_NUMBER_IN_INFINITE_SET_H
#define SMALLEST_NUMBER_IN_INFINITE_SET_H

#include <concepts>
#include <queue>
#include <unordered_set>

template <typename T> requires std::totally_ordered<T> && std::is_integral_v<T>
class SmallestPositiveInfiniteSet
{
public:
    explicit SmallestPositiveInfiniteSet(const T& initial_value)
        : current_value(initial_value)
    {
    }

    SmallestPositiveInfiniteSet()
        : current_value(T{})
    {
    }

    // pops the smallest element that has not been pooped yet and has not been re-added
    T pop()
    {
        T answer{};
        if (queue.empty())
        {
            answer = current_value;
            current_value += 1;
            return answer;
        }
        answer = queue.top();
        is_present.erase(answer);
        queue.pop();
        return answer;
    }

    void add_back(T value)
    {
        if (current_value <= value || is_present.find(value) != is_present.end())
        {
            return;
        }
        queue.push(value);
        is_present.insert(value);
    }

private:
    std::priority_queue<T, std::vector<T>, std::greater<T>> queue;
    std::unordered_set<T> is_present;
    T current_value;
};


#endif //SMALLEST_NUMBER_IN_INFINITE_SET_H
