//
// Created by andreas on 02.02.22.
//

#ifndef I_STACK_H
#define I_STACK_H

template <typename T>
class IStack{
public:
	virtual T pop() = 0;
	virtual void push(const T & value) = 0;
	virtual bool is_empty() = 0;
	virtual T top() = 0;

};

#endif //I_STACK_H
