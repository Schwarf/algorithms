//
// Created by andreas on 14.01.22.
//

#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"

class MergeSort final : public ISort
{
public:
	void sort(std::vector<int64_t> &array) override;
	~MergeSort() final = default;

};


#endif //MERGE_SORT_H
