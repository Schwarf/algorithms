//
// Created by andreas on 17.01.22.
//

#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "./../i_sort.h"
#include "./../swap.h"
class QuickSort final: public ISort
{
public:
	void sort(std::vector<int64_t> &array) final;
	void sort(std::shared_ptr<std::vector<int64_t>> &array) final;
	~QuickSort() override = default;
private:
	static void quick_sort_(std::vector<int64_t> &array, int start, int end);
	static int partition_(std::vector<int64_t> &array, int start, int end);
};


#endif //QUICK_SORT_H
