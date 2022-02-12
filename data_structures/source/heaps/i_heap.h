//
// Created by andreas on 06.02.22.
//

#ifndef I_HEAP_H
#define I_HEAP_H
template<typename T>
class IHeap
{
public:
	virtual T pop_maximum() = 0;
	virtual T get_maximum() const = 0;
	virtual void insert(const T &value) = 0;
	virtual size_t size() const = 0;
	virtual bool is_empty() const = 0;
	virtual T get_element(size_t index) const = 0;
};


#endif //I_HEAP_H
