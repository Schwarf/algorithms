//
// Created by andreas on 06.02.22.
//

#ifndef QUEUE_ARRAY_BASED_H
#define QUEUE_ARRAY_BASED_H
#include "i_queue.h"

template <class T, size_t queue_size>
class QueueAB : IQueue<T>
{
private:
	T elements_[queue_size];
	size_t head_{};
	size_t tail_{};
	size_t size_{};
public:
	QueueAB() = default;
	bool is_empty() const final
	{
		return size_ == 0;
	}

	bool is_full() const
	{
		return size_ == queue_size;
	}

	size_t size() const final
	{
		return size_;
	}

	void enqueue(const T &value)
	{
		if(is_full())
		{
			throw std::out_of_range("Can not enqueue. The array-based queue is full.");
		}

		elements_[tail_] = value;
		tail_ = (tail_+ 1) % queue_size;
		std::cout << "Head_, tail " << head_ << "  " << tail_ << std::endl;
		size_++;
	}

	T dequeue()
	{
		if (is_empty()) {
			throw std::out_of_range("Can not dequeue. The array-based queue is empty.");
		}
		auto value = elements_[head_];
		head_ = (head_ + 1) % queue_size;
		return value;
	}

	T front() const final
	{
		if(is_empty())
			throw std::out_of_range("Can not return front element. The queue is empty.");
		return elements_[head_];
	}

	T back() const final
	{
		if(is_empty())
			throw std::out_of_range("Can not return back element. The queue is empty.");
		return elements_[tail_];
	}

};

#endif //QUEUE_ARRAY_BASED_H
