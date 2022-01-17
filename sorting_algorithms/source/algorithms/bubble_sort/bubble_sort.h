//
// Created by andreas on 17.01.22.
//

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"

class BubbleSort final: ISort
{
public:
	void sort(std::vector<int64_t> &array) final;
	void sort(std::shared_ptr<std::vector<int64_t>> &array) final;
	~BubbleSort() final = default;
};


#endif //BUBBLE_SORT_H
