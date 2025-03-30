//
// Created by andreas on 31.01.22.
//

#ifndef I_LINKED_LIST_H
#define I_LINKED_LIST_H

template <typename T>
class ILinkedList
{
public:
    virtual void push_front(const T& value) = 0;
    virtual void push_back(const T& value) = 0;
    virtual bool push_at(size_t index, const T& value) = 0;
    virtual T pop_back() = 0;
    virtual T pop_front() = 0;
    virtual T pop_at(size_t index) = 0;
    virtual size_t size() const = 0;
    virtual bool is_empty() const = 0;
};

#endif //I_LINKED_LIST_H
