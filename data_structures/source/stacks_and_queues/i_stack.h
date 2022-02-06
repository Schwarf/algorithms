//
// Created by andreas on 02.02.22.
//

#ifndef I_STACK_H
#define I_STACK_H
#include <cstddef>
#include <iostream>

template <typename T>
class IStack{
public:
	virtual T pop() = 0;
	virtual void push(const T & value) = 0;
	virtual bool is_empty() const = 0;
	virtual T top() const = 0;
	virtual size_t size() const = 0;
};

#endif //I_STACK_H
