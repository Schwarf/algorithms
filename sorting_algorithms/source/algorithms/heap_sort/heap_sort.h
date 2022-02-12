//
// Created by andreas on 12.02.22.
//

#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"

class HeapSort : ISort
{
public:
	void sort(std::vector<int64_t> &array) final;
	void sort(std::shared_ptr<std::vector<int64_t>> &array) final;
	~HeapSort() override = default;
private:
	size_t heap_size_{};
	void insert_(size_t index, std::vector<int64_t> & array);
	void promote_(size_t index, std::vector<int64_t> & array);
};


#endif //HEAP_SORT_H
