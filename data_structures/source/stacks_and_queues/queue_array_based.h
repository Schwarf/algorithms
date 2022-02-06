//
// Created by andreas on 06.02.22.
//

#ifndef QUEUE_ARRAY_BASED_H
#define QUEUE_ARRAY_BASED_H
#include "i_queue.h"

template<class T, size_t queue_capacity>
class QueueAB: IQueue<T>
{
private:
	T elements_[queue_capacity];
	size_t head_{};
	size_t tail_{queue_capacity - 1};
	size_t size_{};
public:
	QueueAB() = default;
	bool is_empty() const final
	{
		return size_ == 0;
	}

	bool is_full() const
	{
		return size_ == queue_capacity;
	}

	size_t size() const final
	{
		return size_;
	}

	void enqueue(const T &value)
	{
		if (is_full()) {
			throw std::out_of_range("Can not enqueue. The array-based queue is full.");
		}

		tail_ = (tail_ + 1) % queue_capacity;
		elements_[tail_] = value;
		size_++;
	}

	T dequeue()
	{
		if (is_empty()) {
			throw std::out_of_range("Can not dequeue. The array-based queue is empty.");
		}
		auto value = elements_[head_];
		head_ = (head_ + 1) % queue_capacity;
		size_--;
		return value;
	}

	T front() const final
	{
		if (is_empty())
			throw std::out_of_range("Can not return front element. The queue is empty.");
		return elements_[head_];
	}

	T back() const final
	{
		if (is_empty())
			throw std::out_of_range("Can not return back element. The queue is empty.");
		return elements_[tail_];
	}

};

#endif //QUEUE_ARRAY_BASED_H
