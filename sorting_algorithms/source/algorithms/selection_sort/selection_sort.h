//
// Created by andreas on 12.01.22.
//

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "../i_sort.h"
#include "../swap.h"

class SelectionSort final: public ISort
{
public:
	SelectionSort() = default;
	void sort(std::vector<int64_t> &array) final;
	~SelectionSort() final =default;
};


#endif //SELECTION_SORT_H
