//
// Created by andreas on 06.02.22.
//

#ifndef I_HEAP_H
#define I_HEAP_H
template <typename T, size_t heap_capacity>
class IHeap{
	virtual T find_max() const =0;
	virtual void delete_max() =0;
	virtual void insert(const T & value) =0;
	virtual size_t size() const = 0;
	virtual bool is_empty() const = 0;
	virtual merge(IHeap & other) = 0;
};


#endif //I_HEAP_H
