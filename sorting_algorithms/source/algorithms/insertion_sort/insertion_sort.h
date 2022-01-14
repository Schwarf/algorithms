//
// Created by andreas on 14.01.22.
//

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"

class InsertionSort final: public ISort
{
public:
	void sort(std::vector<int64_t> &array) final;
	~InsertionSort() final = default;

};


#endif //INSERTION_SORT_H
