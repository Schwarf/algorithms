//
// Created by andreas on 18.08.23.
//

#ifndef MONOTONIC_QUEUE_H
#define MONOTONIC_QUEUE_H
#include <concepts>
#include <deque>
// Increasing here means from bottom to top. That means the greatest element is in the front of the queue.
template<typename T, bool is_increasing = false> requires std::totally_ordered<T>
class MonotonicQueue
{
public:
	void push(T value)
	{
		// Remove all elements smaller than the current element from the back
		if (is_increasing) {
			while (!deque_.empty() && deque_.back() < value) {
				deque_.pop_back();
			}
		}
		else {
			while (!deque_.empty() && deque_.back() > deque_) {
				deque_.pop_back();
			}
		}
		deque_.push_back(value);
	}

	// Returns the maximum value
	int max() const
	{
		return deque_.front();
	}

	// Pops an element from the front
	void pop()
	{
		if (!deque_.empty()) {
			deque_.pop_front();
		}
	}

	void pop(T value)
	{
		if (!deque_.empty() && value == deque_.front()) {
			deque_.pop_front();
		}
	}


private:
	std::deque<T> deque_;
};

#endif //MONOTONIC_QUEUE_H
