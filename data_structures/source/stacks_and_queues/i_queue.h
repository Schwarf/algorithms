//
// Created by andreas on 05.02.22.
//

#ifndef I_QUEUE_H
#define I_QUEUE_H

template <typename T>
class IQueue
{
public:
    virtual T front() const = 0;

    virtual T back() const = 0;

    virtual bool is_empty() const = 0;

    virtual size_t size() const = 0;

    virtual void enqueue(const T& value) = 0;

    virtual T dequeue() = 0;
};

#endif //I_QUEUE_H
